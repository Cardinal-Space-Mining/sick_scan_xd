/*
 * @brief Pointcloud utilities for ROS simu
 *
 * Copyright (C) 2021, Ing.-Buero Dr. Michael Lehning, Hildesheim
 * Copyright (C) 2021, SICK AG, Waldkirch
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
 *     * Neither the name of Osnabr�ck University nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
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
 *  Created on: 12.01.2021
 *
 *      Authors:
 *         Michael Lehning <michael.lehning@lehning.de>
 *
 */

#include <sick_scan/pointcloud_utils.h>

#include "toojpeg.h"

static FILE *foutJpg = 0;

static std::vector<ros_visualization_msgs::Marker> s_visualization_marker_array;

static unsigned char s_fontCharBlock8x12[] =
{
	  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , //  
	 0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00	 , // !
	 0x00,0x36,0x36,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , // "
	 0x00,0x00,0x14,0x14,0x3E,0x14,0x14,0x3E,0x14,0x14,0x00,0x00	 , // #
	 0x00,0x08,0x1C,0x32,0x30,0x1C,0x06,0x26,0x1C,0x08,0x08,0x00	 , // $
	 0x00,0x13,0x2B,0x2B,0x16,0x0C,0x1A,0x35,0x35,0x32,0x00,0x00	 , // %
	 0x00,0x1C,0x36,0x36,0x1C,0x1D,0x37,0x36,0x36,0x1B,0x00,0x00	 , // &
	 0x00,0x0C,0x0C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , // '
	 0x00,0x0C,0x18,0x30,0x30,0x30,0x30,0x30,0x18,0x0C,0x00,0x00	 , // (
	 0x00,0x30,0x18,0x0C,0x0C,0x0C,0x0C,0x0C,0x18,0x30,0x00,0x00	 , // )
	 0x00,0x00,0x00,0x36,0x1C,0x7F,0x1C,0x36,0x00,0x00,0x00,0x00	 , // *
	 0x00,0x00,0x00,0x00,0x0C,0x0C,0x3F,0x0C,0x0C,0x00,0x00,0x00	 , // +
	 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x0C,0x18	 , // ,
	 0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x00,0x00,0x00	 , // -
	 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00	 , // .
	 0x00,0x06,0x06,0x0C,0x0C,0x18,0x18,0x30,0x30,0x60,0x00,0x00	 , // /
	 0x00,0x1E,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x3C,0x00,0x00	 , // 0
	 0x00,0x0C,0x1C,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00	 , // 1
	 0x00,0x1C,0x36,0x36,0x06,0x0C,0x0C,0x18,0x30,0x3E,0x00,0x00	 , // 2
	 0x00,0x1C,0x36,0x06,0x06,0x1C,0x06,0x06,0x36,0x1C,0x00,0x00	 , // 3
	 0x00,0x18,0x18,0x18,0x36,0x36,0x36,0x3F,0x06,0x06,0x00,0x00	 , // 4
	 0x00,0x3E,0x30,0x30,0x30,0x3C,0x06,0x06,0x36,0x1C,0x00,0x00	 , // 5
	 0x00,0x0C,0x18,0x18,0x30,0x3C,0x36,0x36,0x36,0x1C,0x00,0x00	 , // 6
	 0x00,0x3E,0x06,0x06,0x0C,0x0C,0x0C,0x18,0x18,0x18,0x00,0x00	 , // 7
	 0x00,0x1C,0x36,0x36,0x36,0x1C,0x36,0x36,0x36,0x1C,0x00,0x00	 , // 8
	 0x00,0x1C,0x36,0x36,0x36,0x1E,0x0C,0x0C,0x18,0x30,0x00,0x00	 , // 9
	 0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x1C,0x1C,0x00,0x00	 , // :
	 0x00,0x00,0x00,0x1C,0x1C,0x00,0x00,0x00,0x1C,0x1C,0x0C,0x18	 , // , //
	 0x00,0x02,0x06,0x0C,0x18,0x30,0x18,0x0C,0x06,0x02,0x00,0x00	 , // <
	 0x00,0x00,0x00,0x00,0x3E,0x00,0x00,0x3E,0x00,0x00,0x00,0x00	 , // =
	 0x00,0x20,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x20,0x00,0x00	 , // >
	 0x00,0x1C,0x36,0x36,0x06,0x0C,0x18,0x00,0x18,0x18,0x00,0x00	 , // ?
	 0x00,0x0E,0x19,0x33,0x35,0x35,0x35,0x32,0x18,0x0F,0x00,0x00	 , // @
	 0x00,0x08,0x1C,0x36,0x36,0x36,0x3E,0x36,0x36,0x36,0x00,0x00	 , // A
	 0x00,0x3C,0x36,0x36,0x36,0x3C,0x36,0x36,0x36,0x3C,0x00,0x00	 , // B
	 0x00,0x1C,0x36,0x36,0x30,0x30,0x30,0x36,0x36,0x1C,0x00,0x00	 , // C
	 0x00,0x3C,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x3C,0x00,0x00	 , // D
	 0x00,0x3E,0x30,0x30,0x30,0x3C,0x30,0x30,0x30,0x3E,0x00,0x00	 , // E
	 0x00,0x3E,0x30,0x30,0x30,0x3C,0x30,0x30,0x30,0x30,0x00,0x00	 , // F
	 0x00,0x1C,0x36,0x30,0x30,0x36,0x36,0x36,0x36,0x1C,0x00,0x00	 , // G
	 0x00,0x36,0x36,0x36,0x36,0x3E,0x36,0x36,0x36,0x36,0x00,0x00	 , // H
	 0x00,0x1E,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00	 , // I
	 0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x36,0x36,0x1C,0x00,0x00	 , // J
	 0x00,0x36,0x36,0x36,0x3C,0x38,0x3C,0x36,0x36,0x36,0x00,0x00	 , // K
	 0x00,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3E,0x00,0x00	 , // L
	 0x00,0x63,0x63,0x77,0x77,0x7F,0x6B,0x6B,0x63,0x63,0x00,0x00	 , // M
	 0x00,0x33,0x33,0x3B,0x3B,0x3F,0x37,0x33,0x33,0x33,0x00,0x00	 , // N
	 0x00,0x1C,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x1C,0x00,0x00	 , // O
	 0x00,0x3C,0x36,0x36,0x36,0x3C,0x30,0x30,0x30,0x30,0x00,0x00	 , // P
	 0x00,0x1C,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x1C,0x0C,0x06	 , // Q
	 0x00,0x3C,0x36,0x36,0x36,0x3C,0x36,0x36,0x36,0x36,0x00,0x00	 , // R
	 0x00,0x1C,0x36,0x32,0x38,0x1C,0x0E,0x26,0x36,0x1C,0x00,0x00	 , // S
	 0x00,0x3F,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x00,0x00	 , // T
	 0x00,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x1C,0x00,0x00	 , // U
	 0x00,0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x1C,0x08,0x00,0x00	 , // V
	 0x00,0x63,0x63,0x6B,0x6B,0x6B,0x6B,0x36,0x36,0x36,0x00,0x00	 , // W
	 0x00,0x36,0x36,0x36,0x1C,0x08,0x1C,0x36,0x36,0x36,0x00,0x00	 , // X
	 0x00,0x33,0x33,0x33,0x33,0x1E,0x0C,0x0C,0x0C,0x0C,0x00,0x00	 , // Y
	 0x00,0x3E,0x06,0x0C,0x0C,0x18,0x18,0x30,0x30,0x3E,0x00,0x00	 , // Z
	 0x00,0x1E,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x1E	 , // [
	 0x00,0x30,0x30,0x18,0x18,0x0C,0x0C,0x06,0x06,0x03,0x00,0x00	 , // Backslash
	 0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C	 , // ]
	 0x00,0x08,0x1C,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , // ^
	 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F	 , // _
	 0x00,0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , // `
	 0x00,0x00,0x00,0x00,0x1C,0x06,0x1E,0x36,0x36,0x1E,0x00,0x00	 , // a
	 0x00,0x30,0x30,0x30,0x3C,0x36,0x36,0x36,0x36,0x3C,0x00,0x00	 , // b
	 0x00,0x00,0x00,0x00,0x1C,0x36,0x30,0x30,0x36,0x1C,0x00,0x00	 , // c
	 0x00,0x06,0x06,0x06,0x1E,0x36,0x36,0x36,0x36,0x1E,0x00,0x00	 , // d
	 0x00,0x00,0x00,0x00,0x1C,0x36,0x3E,0x30,0x32,0x1C,0x00,0x00	 , // e
	 0x00,0x0E,0x18,0x18,0x3E,0x18,0x18,0x18,0x18,0x18,0x00,0x00	 , // f
	 0x00,0x00,0x00,0x00,0x1E,0x36,0x36,0x36,0x1E,0x06,0x26,0x1C	 , // g
	 0x00,0x30,0x30,0x30,0x3C,0x36,0x36,0x36,0x36,0x36,0x00,0x00	 , // h
	 0x00,0x0C,0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00	 , // i
	 0x00,0x0C,0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x38	 , // j
	 0x00,0x30,0x30,0x30,0x36,0x3C,0x38,0x3C,0x36,0x36,0x00,0x00	 , // k
	 0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00	 , // l
	 0x00,0x00,0x00,0x00,0x76,0x7F,0x6B,0x6B,0x6B,0x63,0x00,0x00	 , // m
	 0x00,0x00,0x00,0x00,0x3C,0x36,0x36,0x36,0x36,0x36,0x00,0x00	 , // n
	 0x00,0x00,0x00,0x00,0x1C,0x36,0x36,0x36,0x36,0x1C,0x00,0x00	 , // o
	 0x00,0x00,0x00,0x00,0x3C,0x36,0x36,0x36,0x36,0x3C,0x30,0x30	 , // p
	 0x00,0x00,0x00,0x00,0x1E,0x36,0x36,0x36,0x36,0x1E,0x06,0x06	 , // q
	 0x00,0x00,0x00,0x00,0x36,0x3E,0x30,0x30,0x30,0x30,0x00,0x00	 , // r
	 0x00,0x00,0x00,0x00,0x1E,0x30,0x3C,0x1E,0x06,0x3C,0x00,0x00	 , // s
	 0x00,0x00,0x18,0x18,0x3C,0x18,0x18,0x18,0x18,0x0E,0x00,0x00	 , // t
	 0x00,0x00,0x00,0x00,0x36,0x36,0x36,0x36,0x36,0x1E,0x00,0x00	 , // u
	 0x00,0x00,0x00,0x00,0x36,0x36,0x36,0x36,0x1C,0x08,0x00,0x00	 , // v
	 0x00,0x00,0x00,0x00,0x63,0x6B,0x6B,0x6B,0x3E,0x36,0x00,0x00	 , // w
	 0x00,0x00,0x00,0x00,0x36,0x36,0x1C,0x1C,0x36,0x36,0x00,0x00	 , // x
	 0x00,0x00,0x00,0x00,0x36,0x36,0x36,0x36,0x1C,0x0C,0x18,0x30	 , // y
	 0x00,0x00,0x00,0x00,0x3E,0x06,0x0C,0x18,0x30,0x3E,0x00,0x00	 , // z
	 0x00,0x0E,0x18,0x18,0x18,0x30,0x18,0x18,0x18,0x0E,0x00,0x00	 , // {
	 0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18	 , // |
	 0x00,0x30,0x18,0x18,0x18,0x0C,0x18,0x18,0x18,0x30,0x00,0x00	 , // }
	 0x00,0x1A,0x3E,0x2C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00	 , // ~
	 0x00,0x00,0x00,0x08,0x1C,0x36,0x22,0x22,0x3E,0x3E,0x00,0x00	 , // 
};

void jpegOutputCallback(unsigned char oneByte)
{
  fwrite(&oneByte, 1, 1, foutJpg);
}

void setVisualizationMarkerArray(const std::vector<ros_visualization_msgs::Marker> & marker_array)
{
  s_visualization_marker_array = marker_array;
}

static void setPixel(unsigned char *pixel, int wi, int hi, int numColorChannel, int x, int y, unsigned char rgb_color[3])
{
  if( x >= 0 && x < wi && y >= 0 && y < hi)
  {
    int pixAdr = numColorChannel * (y * wi + x);
    pixel[pixAdr + 0] = rgb_color[0];
    pixel[pixAdr + 1] = rgb_color[1];
    pixel[pixAdr + 2] = rgb_color[2];
  }
}

static void drawLine(unsigned char *pixel, int wi, int hi, int numColorChannel, int startpoint[2], int endpoint[2], float color[3])
{
  int x0 = startpoint[0], y0 = startpoint[1], x1 = endpoint[0], y1 = endpoint[1];
  unsigned char rgb_color[3] = { (unsigned char)((int)(255.999 * color[0])&0xFF), (unsigned char)((int)(255.999 * color[1])&0xFF), (unsigned char)((int)(255.999 * color[2])&0xFF) };
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;
	for (;;) 
  {
		setPixel(pixel, wi, hi, numColorChannel, x0, y0, rgb_color);
		if (x0 == x1 && y0 == y1) break;
		e2 = err;
		if (e2 > -dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

static void drawText(unsigned char *pixel, int wi, int hi, int numColorChannel, const std::string& text, int pos[2], float color[3])
{
  unsigned char rgb_color[3] = { (unsigned char)((int)(255.999 * color[0])&0xFF), (unsigned char)((int)(255.999 * color[1])&0xFF), (unsigned char)((int)(255.999 * color[2])&0xFF) };
	int strLen = (int)text.length();
	int xTmp = pos[0];
	for (int i = 0; i < strLen; i++)
	{
		char ch = text[i];
		if ((ch >= ' ') && (ch < 0x80))
		{
			int idx = ch - ' ';
			int offset = idx * 12;
			for (int ii = 0; ii < 12; ii++)
			{
				unsigned char ucBitMask = s_fontCharBlock8x12[offset + ii];
				for (int jj = 0; jj < 8; jj++)
				{
					if (ucBitMask & (0x01 << (7 - jj)))
					{
        		setPixel(pixel, wi, hi, numColorChannel, xTmp + jj, pos[1] + ii, rgb_color);
					}
				}
			}
		}
		xTmp += 8;
	}
}

/*
** Plots a pointcloud and saves to jpg and csv-file
*/
void plotPointCloud(const ros_sensor_msgs::PointCloud2& cloud_, int intervall, const std::string & outputfolder)
{
                static int cnt = 0;
                cnt++;
                
                ROS_DEBUG_STREAM("plotPointCloud: outputfolder=\"" << outputfolder << "\"");
                const unsigned char *cloudDataPtr = &(cloud_.data[0]);
                int w = cloud_.width;
                int h = cloud_.height;

                int numShots = w * h;

                float *ptr = (float *) cloudDataPtr;

                if (cnt == intervall)
                {
                  std::string filename_tmpl = outputfolder + "/scan";
#if linux				  
                  std::replace( filename_tmpl.begin(), filename_tmpl.end(), '\\', '/');
#else
                  std::replace( filename_tmpl.begin(), filename_tmpl.end(), '/', '\\');
#endif
                  std::string jpgFileName_tmp = filename_tmpl + ".jpg_tmp";

                  int xic = 400;
                  int yic = 400;
                  int w2i = 400;
                  int h2i = 400;
                  int hi = h2i * 2 + 1;
                  int wi = w2i * 2 + 1;
                  int pixNum = hi * wi;
                  int numColorChannel = 3;
                  unsigned char *pixel = (unsigned char *) malloc(numColorChannel * hi * wi);
                  memset(pixel, 0, numColorChannel * pixNum);
                  double scaleFac = 50.0;

                  for (int i = 0; i < hi; i++)
                  {
                    int pixAdr = numColorChannel * (i * wi + xic);
                    pixel[pixAdr] = 0x40;
                    pixel[pixAdr + 1] = 0x40;
                    pixel[pixAdr + 2] = 0x40;
                  }
                  for (int i = 0; i < wi; i++)
                  {
                    int pixAdr = numColorChannel * (yic * wi + i);
                    pixel[pixAdr] = 0x40;
                    pixel[pixAdr + 1] = 0x40;
                    pixel[pixAdr + 2] = 0x40;
                  }

                  scaleFac *= -1.0;
                  for (int i = 0; i < numShots; i++)
                  {
                    double x, y, z, intensity;
                    x = ptr[0];
                    y = ptr[1];
                    z = ptr[2];
                    intensity = ptr[3];
                    ptr += 4;
                    int xi = (x * scaleFac) + xic;
                    int yi = (y * scaleFac) + yic;
                    if ((xi >= 0) && (xi < wi))
                    {
                      if ((yi >= 0) && (xi < hi))
                      {
                        // yi shows left (due to neg. scaleFac)
                        // xi shows up (due to neg. scaleFac)
                        int pixAdr = numColorChannel * (xi * wi + yi);
                        int layer = i / w;
                        unsigned char color[3] = {0x00};
                        switch (layer)
                        {
                          case 0:
                            color[0] = 0xFF;
                            break;
                          case 1:
                            color[1] = 0xFF;
                            break;
                          case 2:
                            color[2] = 0xFF;
                            break;
                          case 3:
                            color[0] = 0xFF;
                            color[1] = 0xFF;
                            break;
                        }

                        for (int kk = 0; kk < 3; kk++)
                        {
                          pixel[pixAdr + kk] = color[kk];

                        }
                      }
                    }

                  }

                  // Draw marker array and fields (if any visualization markers are set)
                  // Convert ROS to image coordinates: ROS: x upward, y to the left, Image: x to the right, y downwards, Note: scaleFac is negative
                  for(int marker_idx = 0; marker_idx < s_visualization_marker_array.size(); marker_idx++)
                  {
                    const ros_visualization_msgs::Marker& marker = s_visualization_marker_array[marker_idx];
                    ros_std_msgs::ColorRGBA marker_rgba = marker.color;
                    float marker_pos[3] = { (float)marker.pose.position.x, (float)marker.pose.position.y, (float)marker.pose.position.z };
                    std::string marker_text = marker.text;
                    if(marker.type == ros_visualization_msgs::Marker::TRIANGLE_LIST)
                    {
                      for(int point_idx = 2; point_idx < marker.points.size(); point_idx+=3)
                      {
                        int triangle_p0[2] = { (int)(marker.points[point_idx - 2].y * scaleFac + xic), (int)(marker.points[point_idx - 2].x * scaleFac + yic) };
                        int triangle_p1[2] = { (int)(marker.points[point_idx - 1].y * scaleFac + xic), (int)(marker.points[point_idx - 1].x * scaleFac + yic) };
                        int triangle_p2[2] = { (int)(marker.points[point_idx - 0].y * scaleFac + xic), (int)(marker.points[point_idx - 0].x * scaleFac + yic) };
                        if(point_idx < marker.colors.size())
                          marker_rgba = marker.colors[point_idx];
                        float marker_color[3] = { (float)marker_rgba.r, (float)marker_rgba.g, (float)marker_rgba.b };
                        drawLine(pixel, wi, hi, numColorChannel, triangle_p0, triangle_p1, marker_color);
                        drawLine(pixel, wi, hi, numColorChannel, triangle_p1, triangle_p2, marker_color);
                        drawLine(pixel, wi, hi, numColorChannel, triangle_p2, triangle_p1, marker_color);
                      }
                    }
                    else if(marker.type == ros_visualization_msgs::Marker::TEXT_VIEW_FACING)
                    {
                      int text_pos[2] = { (int)(2 * marker_pos[1] * scaleFac + xic), (int)(3 * marker_pos[0] * scaleFac + yic) };
                      int text_bias = ((text_pos[0] < xic) ? -1 : 0) * 8 * marker_text.length(); // ROS: marker position is the center of the text area
                      text_pos[0] += text_bias; 
                      float text_color[3] = { (float)marker_rgba.r, (float)marker_rgba.g, (float)marker_rgba.b };
                      drawText(pixel, wi, hi, numColorChannel, marker_text, text_pos, text_color);
                    }
                    else // currently supported types are ros_visualization_msgs::Marker::TEXT_VIEW_FACING and ros_visualization_msgs::Marker::TRIANGLE_LIST
                    {
                      ROS_INFO_STREAM("visualization_marker[" << marker_idx << "]: type=" << (int)marker.type << " NOT supported, text=" << marker_text << ", pos=(" << marker_pos[0] << "," << marker_pos[1] << "," << marker_pos[1] << "), " 
                        << ", color_rgb=(" << marker_rgba.r << "," << marker_rgba.g << "," << marker_rgba.b << "), " << (marker.points.size()) << " points.");
                    }
                  }

                  // Write JPEG Scan Top View
                  foutJpg = fopen(jpgFileName_tmp.c_str(), "wb");
                  if (foutJpg == NULL)
                  {
                    ROS_INFO_STREAM("PANIC: Can not open " << jpgFileName_tmp << " for writing. Check existience of demo dir. or patch  code.\n");
                  }
                  else
                  {
                  TooJpeg::writeJpeg(jpegOutputCallback, pixel, wi, hi, true, 99);
                  fclose(foutJpg);

                  free(pixel);
                  std::string jpgFileName_out = filename_tmpl + ".jpg";
#if linux				  
				  rename(jpgFileName_tmp.c_str(), jpgFileName_out.c_str());
#else
				  _unlink(jpgFileName_out.c_str());
				  rename(jpgFileName_tmp.c_str(), jpgFileName_out.c_str());
#endif

                  }
                  // Write CSV-File
                  std::string csvFileNameTmp = filename_tmpl + ".csv_tmp";
                  FILE *foutCsv = fopen(csvFileNameTmp.c_str(), "w");
                  if (foutCsv)
                  {
                    // ZIEL: fprintf(foutCsv,"timestamp;range;elevation;azimuth;x;y;z;intensity\n");
                    fprintf(foutCsv,"timestamp_sec;timestamp_nanosec;range;azimuth_deg;elevation_deg;x;y;z;intensity\n");
                    const unsigned char *cloudDataPtr = &(cloud_.data[0]);

                    int numShots = w * h;

                    float *ptr = (float *) cloudDataPtr;


                    long timestamp_sec = cloud_.header.stamp.sec;
                    long timestamp_nanosec = cloud_.header.stamp.nsec;
                    for (int i = 0; i < numShots; i++)
                    {
                      double x, y, z, intensity;
                      x = ptr[0];
                      y = ptr[1];
                      z = ptr[2];
                      float range_xy = sqrt(x*x+y*y);
                      float range_xyz = sqrt(x*x+y*y+z*z);
                      float elevation = atan2(z, range_xy);
                      float azimuth = atan2(y,x);
                      float elevationDeg = elevation * 180.0 / M_PI;
                      float azimuthDeg = azimuth * 180.0 / M_PI;

                      intensity = ptr[3];
                      ptr += 4;
                      fprintf(foutCsv,"%12ld;%12ld;%8.3lf;%8.3lf;%8.3lf;%8.3f;%8.3f;%8.3f;%8.0f\n", timestamp_sec, timestamp_nanosec, range_xyz, azimuthDeg, elevationDeg, x,y,z,intensity);
                    }
                    fclose(foutCsv);
                    std::string csvFileNameOut = filename_tmpl + ".csv";
#ifdef linux
                     rename(csvFileNameTmp.c_str(), csvFileNameOut.c_str());
#else
					  _unlink(csvFileNameOut.c_str());
					  rename(csvFileNameTmp.c_str(), csvFileNameOut.c_str());
#endif
                  }
                  else
                  {
                        ROS_INFO_STREAM("PANIC: Can not open " << csvFileNameTmp << " for writing. Check existience of demo dir. or patch  code.\n");
                  }
                  cnt = 0;
                }

}