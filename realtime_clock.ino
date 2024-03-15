// now.pde
// Prints a snapshot of the current date and time along with the UNIX time
// Modified by Andy Wickert from the JeeLabs / Ladyada RTC library examples
// 5/15/11

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#include <Wire.h>
#include <DS3231.h>
#include <time.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola tampilan = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

RTClib myRTC;

void setup()
{
    Wire.begin();
    tampilan.begin();
}

void loop()
{
    DateTime dt = myRTC.now();

    time_t t = dt.unixtime() - UNIX_OFFSET;
    struct tm *lt = localtime(&t);
    char str[32];
    strftime(str, sizeof str, "%d/%m/%Y - %H.%M", lt);
    Serial.println(str);

    if (tampilan.displayAnimate())
        tampilan.displayText(str, PA_CENTER, 70, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}