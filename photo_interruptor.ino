#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola tampilan = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const int DATAPIN = 7;

void setup()
{
    tampilan.begin();
    pinMode(DATAPIN, INPUT);
}

String status;

void loop()
{
    int value = digitalRead(DATAPIN);
    if (value == LOW)
        status = "Tidak Tertutup";
    else
        status = "Tertutup";

    if (tampilan.displayAnimate())
        tampilan.displayText(status.c_str(), PA_CENTER, 70, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}
