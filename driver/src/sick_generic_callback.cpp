/*
* Copyright (C) 2022, Ing.-Buero Dr. Michael Lehning, Hildesheim
* Copyright (C) 2022, SICK AG, Waldkirch
* All rights reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Osnabrueck University nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission.
*     * Neither the name of SICK AG nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission
*     * Neither the name of Ing.-Buero Dr. Michael Lehning nor the names of its
*       contributors may be used to endorse or promote products derived from
*       this software without specific prior written permission
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
*
*      Authors:
*         Michael Lehning <michael.lehning@lehning.de>
*
*/
#include <sick_scan/sick_generic_callback.h>

static sick_scan::SickCallbackHandler<rosNodePtr,sick_scan::PointCloud2withEcho> s_cartesian_poincloud_callback_handler;
static sick_scan::SickCallbackHandler<rosNodePtr,sick_scan::PointCloud2withEcho> s_polar_poincloud_callback_handler;
static sick_scan::SickCallbackHandler<rosNodePtr,ros_sensor_msgs::Imu>           s_imu_callback_handler;

namespace sick_scan
{
    void addCartesianPointcloudListener(rosNodePtr handle, PointCloud2Callback listener)
    {
        s_cartesian_poincloud_callback_handler.addListener(handle, listener);
	}

    void notifyCartesianPointcloudListener(rosNodePtr handle, const sick_scan::PointCloud2withEcho* msg)
    {
        s_cartesian_poincloud_callback_handler.notifyListener(handle, msg);
	}

    void removeCartesianPointcloudListener(rosNodePtr handle, PointCloud2Callback listener)
    {
        s_cartesian_poincloud_callback_handler.removeListener(handle, listener);
	}

    void addPolarPointcloudListener(rosNodePtr handle, PointCloud2Callback listener)
    {
        s_polar_poincloud_callback_handler.addListener(handle, listener);
	}

    void notifyPolarPointcloudListener(rosNodePtr handle, const sick_scan::PointCloud2withEcho* msg)
    {
        s_polar_poincloud_callback_handler.notifyListener(handle, msg);
	}

    void removePolarPointcloudListener(rosNodePtr handle, PointCloud2Callback listener)
    {
        s_polar_poincloud_callback_handler.removeListener(handle, listener);
	}

    void addImuListener(rosNodePtr handle, ImuCallback listener)
    {
        s_imu_callback_handler.addListener(handle, listener);
	}

    void notifyImuListener(rosNodePtr handle, const ros_sensor_msgs::Imu* msg)
    {
        s_imu_callback_handler.notifyListener(handle, msg);
	}

    void removeImuListener(rosNodePtr handle, ImuCallback listener)
    {
        s_imu_callback_handler.removeListener(handle, listener);
	}

}   // namespace sick_scan
