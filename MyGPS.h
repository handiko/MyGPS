#ifndef MyGPS_h
#define MyGPS_h

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

char* parse_rmc_time(char gps_str[])
{
  char waktu[10];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<10;j++)
  {
    waktu[j] = 0;
  }

  for(;c<150;c++)
  {
    if(gps_str[c] == ',')
      break;
  }
  
  c++;

  while(gps_str[c] != ',')
  {
    waktu[i] = gps_str[c];
    c++;
    i++;
  }

  result = waktu;

  Serial.print('.');
  
  return result;
}

char parse_rmc_valid(char gps_str[])
{
  char validity = 0;
  int c=0;
  int i=0;

  for(i=0;i<2;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  validity = gps_str[c];

  Serial.print('.');

  return validity;
}

char* parse_rmc_lat(char gps_str[])
{
  char lintang[20];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<20;j++)
  {
    lintang[j] = 0;
  }

  for(i=0;i<3;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  i=0;

  while(gps_str[c] != ',')
  {
    lintang[i] = gps_str[c];
    c++;
    i++;
  }

  result = lintang;

  Serial.print('.');
  
  return result;
}

char parse_rmc_NS(char gps_str[])
{
  char ns=0;
  int c=0;
  int i=0;

  for(i=0;i<4;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  if(gps_str[c]!=',')
    ns = gps_str[c];

  Serial.print('.');

  return ns;
}

char* parse_rmc_lon(char gps_str[])
{
  char bujur[20];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<20;j++)
  {
    bujur[j] = 0;
  }

  for(i=0;i<5;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  i=0;

  while(gps_str[c] != ',')
  {
    bujur[i] = gps_str[c];
    c++;
    i++;
  }

  result = bujur;

  Serial.print('.');
  
  return result;
}

char parse_rmc_EW(char gps_str[])
{
  char ew=0;
  int c=0;
  int i=0;

  for(i=0;i<6;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  if(gps_str[c]!=',')
    ew = gps_str[c];

  Serial.print('.');

  return ew;
}

char* parse_rmc_spd(char gps_str[])
{
  char spd[10];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<10;j++)
  {
    spd[j] = 0;
  }

  for(i=0;i<7;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  i=0;

  while(gps_str[c] != ',')
  {
    spd[i] = gps_str[c];
    c++;
    i++;
  }

  result = spd;

  Serial.print('.');
  
  return result;
}

char* parse_rmc_cse(char gps_str[])
{
  char cse[10];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<10;j++)
  {
    cse[j] = 0;
  }

  for(i=0;i<8;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  i=0;

  while(gps_str[c] != ',')
  {
    cse[i] = gps_str[c];
    c++;
    i++;
  }

  result = cse;

  Serial.print('.');
  
  return result;
}

char* parse_rmc_date(char gps_str[])
{
  char gps_date[10];
  char *result;
  int c=0;
  int i=0;

  for(int j=0;j<10;j++)
  {
    gps_date[j] = 0;
  }

  for(i=0;i<9;i++)
  {
    while(gps_str[c] != ',')
    {
      c++;
    }

    c++;
  }

  i=0;

  while(gps_str[c] != ',')
  {
    gps_date[i] = gps_str[c];
    c++;
    i++;
  }

  result = gps_date;

  Serial.print('.');
  
  return result;
}

struct GPSresults gps_parse(SoftwareSerial &ser)
{
  char rmc[150];
  char temp;
  int c=0;

  GPSresults result;

  for(int i=0;i<150;i++)
    rmc[i]='\0';

  do
  {
    if(ser.available()>0)
      temp = ser.read(); 
  }
  while(temp!='$');

  rmc[c] = temp;
  c++;

  do
  {
    if(ser.available()>0)
    {
      temp = ser.read();
      rmc[c] = temp;
      c++;
    }

    if(c==6)
    {
      if(rmc[5]!='C')
      {
        result.gps_success = 0;
        
        return result;

        goto esc;
      }
    }
  }
  while((temp!=10)&&(temp!=13));

  c--;

  strcpy(result.gps_rmc, rmc);
  strcpy(result.gps_time, parse_rmc_time(rmc));
  result.gps_valid = parse_rmc_valid(rmc);
  strcpy(result.gps_lat, parse_rmc_lat(rmc));
  result.gps_ns = parse_rmc_NS(rmc);
  strcpy(result.gps_lon, parse_rmc_lon(rmc));
  result.gps_ew = parse_rmc_EW(rmc);
  strcpy(result.gps_spd, parse_rmc_spd(rmc));
  strcpy(result.gps_cse, parse_rmc_cse(rmc));
  strcpy(result.gps_date, parse_rmc_date(rmc));
  
  result.gps_success = c;
  
  return result;

  esc:
  ;
}

#endif