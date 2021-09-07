/*
 * Copyright (C) 2009, Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROSCPP_SERVICE_CLIENT_H
#define ROSCPP_SERVICE_CLIENT_H

#include "ros/forwards.h"
#include "ros/common.h"
#include "ros/service_traits.h"
#include "ros/serialization.h"

namespace ros
{

/**
 * @brief Provides a handle-based interface to service client connections
 */
class ROSCPP_DECL ServiceClient
{
public:
  ServiceClient() {}
  ServiceClient(const std::string& service_name, bool persistent, const M_string& header_values, const std::string& service_md5sum);
  ServiceClient(const ServiceClient& rhs);
  ~ServiceClient();

  /**
   * @brief Call the service aliased by this handle with the specified request/response messages.
   * @note The request/response message types must match the types specified in the templated call to NodeHandle::serviceClient()/service::createClient()
   */
  template<class MReq, class MRes>
  bool call(MReq& req, MRes& res)
  {
    namespace st = service_traits;

    if (!isValid())
    {
      return false;
    }

    if (strcmp(st::md5sum(req), st::md5sum(res)))
    {
      ROS_ERROR("The request and response parameters to the service "
                 "call must be autogenerated from the same "
                 "server definition file (.srv). your service call "
                 "for %s appeared to use request/response types "
                 "from different .srv files. (%s vs. %s)", impl_->name_.c_str(), st::md5sum(req), st::md5sum(res));
      return false;
    }

    return call(req, res, st::md5sum(req));
  }

  /**
   * @brief Call the service aliased by this handle with the specified service request/response
   */
  template<class Service>
  bool call(Service& service)
  {
    namespace st = service_traits;

    if (!isValid())
    {
      return false;
    }

    return call(service.request, service.response, st::md5sum(service));
  }

  /**
   * \brief Mostly for internal use, the other templated versions of call() just call into this one
   */
  template<typename MReq, typename MRes>
  bool call(const MReq& req, MRes& resp, const std::string& service_md5sum)
  {
    namespace ser = serialization;
    SerializedMessage ser_req = ser::serializeMessage(req);
    SerializedMessage ser_resp;
    bool ok = call(ser_req, ser_resp, service_md5sum);
    if (!ok)
    {
      return false;
    }

    try
    {
      ser::deserializeMessage(ser_resp, resp);
    }
    catch (std::exception& e)
    {
      deserializeFailed(e);
      return false;
    }

    return true;
  }

  bool call(const SerializedMessage& req, SerializedMessage& resp, const std::string& service_md5sum);

  /**
   * \brief Returns whether or not this handle is valid.  For a persistent service, this becomes false when the connection has dropped.
   * Non-persistent service handles are always valid.
   */
  bool isValid() const;

  /**
   * \brief Returns true if this handle points to a persistent service, false otherwise.
   */
  bool isPersistent() const;

  /**
   * \brief Shutdown the connection associated with this ServiceClient
   *
   * This method usually does not need to be explicitly called, as automatic shutdown happens when
   * all copies of this ServiceClient go out of scope
   *
   * This method overrides the automatic reference counted shutdown, and does so immediately.
   */
  void shutdown();

  /**
   * \brief Wait for this service to be advertised and available.  Blocks until it is.
   * \param timeout The amount of time to wait for before timing out.  If timeout is -1 (default),
   * waits until the node is shutdown
   * \return true on success, false otherwise
   */
  bool waitForExistence(ros::Duration timeout = ros::Duration(-1));

  /**
   * \brief Checks if this is both advertised and available.
   * \return true if the service is up and available, false otherwise
   */
  bool exists();

  /**
   * \brief Returns the name of the service this ServiceClient connects to
   */
  std::string getService();

  operator void*() const { return isValid() ? (void*)1 : (void*)0; }
  bool operator<(const ServiceClient& rhs) const
  {
    return impl_ < rhs.impl_;
  }

  bool operator==(const ServiceClient& rhs) const
  {
    return impl_ == rhs.impl_;
  }

  bool operator!=(const ServiceClient& rhs) const
  {
    return impl_ != rhs.impl_;
  }

private:
  // This works around a problem with the OSX linker that causes the static variable declared by
  // ROS_ERROR to error with missing symbols when it's used directly in the templated call() method above
  // This for some reason only showed up in the rxtools package
  void deserializeFailed(const std::exception& e)
  {
    ROS_ERROR("Exception thrown while while deserializing service call: %s", e.what());
  }

  struct Impl
  {
    Impl();
    ~Impl();

    void shutdown();
    bool isValid() const;

    ServiceServerLinkPtr server_link_;
    std::string name_;
    bool persistent_;
    M_string header_values_;
    std::string service_md5sum_;
    bool is_shutdown_;
  };
  typedef std::shared_ptr<Impl> ImplPtr;
  typedef std::weak_ptr<Impl> ImplWPtr;

  ImplPtr impl_;

  friend class NodeHandle;
  friend class NodeHandleBackingCollection;
};
typedef std::shared_ptr<ServiceClient> ServiceClientPtr;

}

#endif
