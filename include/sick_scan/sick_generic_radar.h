#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
/*
 * Copyright (C) 2018, Ing.-Buero Dr. Michael Lehning, Hildesheim
 * Copyright (C) 2018, SICK AG, Waldkirch
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
 *  Created on: 28th May 2018
 *
 *      Authors:
 *       Michael Lehning <michael.lehning@lehning.de>
 *
 */

#ifndef SICK_GENERIC_RADAR_H_
#define SICK_GENERIC_RADAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>

#include <sick_scan/sick_ros_wrapper.h>
#include <sick_scan/sick_scan_common_nw.h>
//#include <sick_scan/RadarScan.h> // generated by msg-generator

#include "sick_scan/sick_generic_parser.h"
#include "sick_scan/sick_scan_common_nw.h"

namespace sick_scan
{

  class SickScanRadarRawTarget
  {
  public:
    float Dist() const
    { return dist; }

    void Dist(float val)
    { dist = val; }

    float Azimuth() const
    { return azimuth; }

    void Azimuth(float val)
    { azimuth = val; }

    float Vrad() const
    { return vrad; }

    void Vrad(float val)
    { vrad = val; }

    float Ampl() const
    { return ampl; }

    void Ampl(float val)
    { ampl = val; }

    int Mode() const
    { return mode; }

    void Mode(int val)
    { mode = val; }

  private:
    float dist;
    float azimuth;
    float vrad;
    float ampl;
    int mode;
  };

  class SickScanRadarObject
  {
  public:
    float P3Dx() const
    { return p3Dx; }

    void P3Dx(float val)
    { p3Dx = val; }

    float P3Dy() const
    { return p3Dy; }

    void P3Dy(float val)
    { p3Dy = val; }

    float V3Dx() const
    { return v3Dx; }

    void V3Dx(float val)
    { v3Dx = val; }

    float V3Dy() const
    { return v3Dy; }

    void V3Dy(float val)
    { v3Dy = val; }

    float ObjLength() const
    { return objLength; }

    void ObjLength(float val)
    { objLength = val; }

    int ObjId() const
    { return objId; }

    void ObjId(int val)
    { objId = val; }

  private:
    float p3Dx;
    float p3Dy;
    float v3Dx;
    float v3Dy;
    float objLength;
    int objId;
  };


  class SickScanRadarSingleton
  {
  private:
    /* Here will be the instance stored. */
    static SickScanRadarSingleton *instance;

    /* Private constructor to prevent instancing. */
    SickScanRadarSingleton(rosNodePtr nh);

    void simulateAsciiDatagramFromFile(unsigned char *receiveBuffer, int *actual_length, std::string filePattern);

    bool emul = false;

    std::string radarName = "???"; // radar device type
    rosNodePtr node;

    rosPublisher<ros_sensor_msgs::PointCloud2> cloud_radar_rawtarget_pub_;
    rosPublisher<ros_sensor_msgs::PointCloud2> cloud_radar_track_pub_;
    rosPublisher<sick_scan_msg::RadarScan> radarScan_pub_;

  public:
    /* Static access method. */
    static SickScanRadarSingleton *getInstance(rosNodePtr nh);

    void setEmulation(bool _emul);

    bool getEmulation(void);

    int parseDatagram(rosTime timeStamp, unsigned char *receiveBuffer, int actual_length, bool useBinaryProtocol);

    int parseRadarDatagram(char* datagram, size_t datagram_length, bool useBinaryProtocol,
        sick_scan_msg::RadarScan* msgPtr,
        std::vector<SickScanRadarObject>& objectList,
        std::vector<SickScanRadarRawTarget>& rawTargetList, /* , SickScanConfig &config, */ // sensor_msgs::LaserScan &msg, int &numEchos, int &echoMask);
        int verboseLevel = 0);
        
    void simulateAsciiDatagram(unsigned char *receiveBuffer, int *actual_length);
    void setNameOfRadar(std::string _radarName)
    {
      radarName = _radarName;
    }
    std::string getNameOfRadar()
    {
      return(radarName);
    }
  };


#if 0
  class SickScanRadar
  {
  public:
    SickScanRadar(SickScanCommon *commonPtr_)
    {
      commonPtr = commonPtr_;
    }
    void setEmulation(bool _emul);
    bool getEmulation(void);
    int parseDatagram(rosTime timeStamp, unsigned char *receiveBuffer, int actual_length, bool useBinaryProtocol);
    int parseAsciiDatagram(char* datagram, size_t datagram_length, sick_scan_msg::RadarScan *msgPtr, std::vector<SickScanRadarObject> &objectList, std::vector<SickScanRadarRawTarget> &rawTargetList); /* , SickScanConfig &config, */ // sensor_msgs::LaserScan &msg, int &numEchos, int &echoMask);
    void simulateAsciiDatagram(unsigned char * receiveBuffer, int* actual_length);
  private:
//		SickScanCommon *commonPtr;
    void simulateAsciiDatagramFromFile(unsigned char *receiveBuffer, int *actual_length, std::string filePattern);
    bool emul;
  };
#endif

} /* namespace sick_scan */
#endif // SICK_GENERIC_RADAR_H_
