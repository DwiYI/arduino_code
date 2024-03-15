#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3
MD_Parola tampilan = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const int TRIGPIN = 6;
const int ECHOPIN = 7;

void setup()
{
    tampilan.begin();
    pinMode(TRIGPIN, OUTPUT);
    pinMode(ECHOPIN, INPUT);
}
int distance;
long duration;
String status;
void loop()
{
    digitalWrite(TRIGPIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGPIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGPIN, LOW);
    duration = pulseIn(ECHOPIN, HIGH);
    distance = duration * 0.034 / 2;

    status = String(distance) + " cm";
    if (tampilan.displayAnimate())
        tampilan.displayText(status.c_str(), PA_CENTER, 70, 0, PA_NO_EFFECT);
}
