# MyGPS - A Simple GPS GPRMC Parser Library for Arduino
Parsing GPS GPRMC sentence from a GPS serial data, written in C.

## Instalation
* Download as .zip
* Open Arduino IDE.
* From **Sketch**, **Include Library --> Add .ZIP Library...**
* Choose the downloaded .zip. (when downloaded, more likely be named **MyGPS-master.zip**)
* Restart the Arduino IDE

## Usage
```C
// include this library
#include <MyGPS.h>          
//include software serial for creating the second serial line
#include <SoftwareSerial.h> 

// Arduino PIN 8 <-- serial data from GPS
// Arduino PIN 9 --> serial data to GPS (not required)
SoftwareSerial gps = SoftwareSerial(8, 9);

// somewhere in your code...
// creating GPS struct variable
GPSresults GPS;
// perform gps GPRMC parsing and save the results into GPS
GPS = gps_parse(gps);
```

## Example
