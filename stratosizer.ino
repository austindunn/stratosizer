{\rtf1\ansi\ansicpg1252\cocoartf1265\cocoasubrtf200
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural

\f0\fs24 \cf0 \
//button pins\
int b1Pin = 0;\
int b2Pin = 1;\
\
//pot pins\
int pot1 = 5;\
int pot2 = 4;\
int pot3 = 2;\
int pot4 = 3;\
\
int mode = 0;      //mode 0 is sequencing mode, mode 1 playing mode\
\
void setup()\
\{\
  Serial.begin( 9600 );       // set the serial communication rate\
\}\
\
void loop()\
\{\
  //val = analogRead( potPin );  // read the value from the sensor\
  //Serial.println( 10000 + val );         // print the value, and add a number\
                                         // to identify resistor by\
  if (mode == 0) \{\
    if ( analogRead(b1Pin) > 100 && analogRead(b2Pin) > 100) \{  //Press both buttons simultaneously for mode switch\
      Serial.println(70000);        //switch record to play mode\
      mode = 1;\
      delay(500);\
    \} else if ( analogRead(b1Pin) > 100 ) \{  //Press just button one to repeat the previous note played\
      Serial.println(50000 + analogRead(b1Pin));\
      delay(500);\
    \} else if ( analogRead(b2Pin) > 100) \{  //Press just button two to switch octave down.\
      Serial.println(60000 + analogRead(b2Pin));\
      delay(500);\
    \}\
    else \{ \
      delay(100); \
    \}\
  \} else \{    //mode == 1\
    if ( analogRead(b1Pin) > 100 && analogRead(b2Pin) > 100) \{  //Press both buttons simultaneously for mode switch\
      Serial.println(80000);          //switch play to record mode\
      mode = 0;\
      delay(500);\
    \} else if (analogRead(b1Pin) > 100) \{\
      Serial.println(90000);\
      delay(500);\
    \}\
    Serial.println(10000 + analogRead(pot1));\
    Serial.println(20000 + analogRead(pot2));\
    Serial.println(30000 + analogRead(pot3));\
    Serial.println(40000 + analogRead(pot4));\
    delay(10);      //change back to 10\
  \}\
\}}