
#include <MD_Parola.h>
#include <MD_MAX72XX.h>
#include <SPI.h>

#include <SimpleDHT.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

const int DHTPIN = 2;

MD_Parola tampilan = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
SimpleDHT11 dht11(DHTPIN);

void setup()
{
    tampilan.begin();
}
String txt;

void loop()
{
    byte temperature = 0;
    byte humidity = 0;

    if (dht11.read(&temperature, &humidity, NULL) != SimpleDHTErrSuccess)
        return;
    txt = "T : " + String((int)temperature) + " H : " + String((int)humidity);
    if (tampilan.displayAnimate())
        tampilan.displayText(txt.c_str(), PA_CENTER, 50, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}
