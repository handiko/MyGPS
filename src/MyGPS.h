#ifndef MyGPS_h
#define MyGPS_h

#include <Arduino.h>
#include <SoftwareSerial.h>

struct GPSresults {
  char gps_success;
  char gps_rmc[150];
  char gps_time[10];
  char gps_valid;
  char gps_lat[15];
  char gps_ns;
  char gps_lon[15];
  char gps_ew;
  char gps_spd[10];
  char gps_cse[10];
  char gps_date[10];
}; 

struct GPSresults gps_parse(SoftwareSerial &ser);

char* parse_rmc_time(char gps_str[]);
char parse_rmc_valid(char gps_str[]);
char* parse_rmc_lat(char gps_str[]);
char parse_rmc_NS(char gps_str[]);
char* parse_rmc_lon(char gps_str[]);
char parse_rmc_EW(char gps_str[]);
char* parse_rmc_spd(char gps_str[]);
char* parse_rmc_cse(char gps_str[]);
char* parse_rmc_date(char gps_str[]);

#endif
