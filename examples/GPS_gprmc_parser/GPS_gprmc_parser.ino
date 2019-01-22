/*
 *  Copyright (C) 2018 - Handiko Gesang - www.github.com/handiko
 *  
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <SoftwareSerial.h>
#include <MyGPS.h>

SoftwareSerial gps = SoftwareSerial(8, 9);

void setup()
{
  Serial.begin(115200);
  
  Serial.println(" ");
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
  
  Serial.println("GPS Struct Test - Started ! \n");

  gps.begin(9600);
}

void loop()
{
  char buff[250];
  
  GPSresults GPS = gps_parse(gps);

  if(GPS.gps_success)
  {    
    sprintf(buff, "\n%s", GPS.gps_rmc);
    
    sprintf(buff, "%s \n GPS Time (HHMMSS): %s", buff, GPS.gps_time);
    sprintf(buff, "%s \n GPS Valid: %c", buff, GPS.gps_valid);
    sprintf(buff, "%s \n GPS Latitude: %s", buff, GPS.gps_lat);
    sprintf(buff, "%s \n GPS N/S: %c", buff, GPS.gps_ns);
    sprintf(buff, "%s \n GPS Longitude: %s", buff, GPS.gps_lon);
    sprintf(buff, "%s \n GPS E/W: %c", buff, GPS.gps_ew);
    sprintf(buff, "%s \n GPS Speed (knots): %s", buff, GPS.gps_spd);
    sprintf(buff, "%s \n GPS Course (degree): %s", buff, GPS.gps_cse);
    sprintf(buff, "%s \n GPS Date (DDMMYY): %s \n", buff, GPS.gps_date);
    
    Serial.println(buff);
  }
}
