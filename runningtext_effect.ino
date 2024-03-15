#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola tampilan = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup()
{
    tampilan.begin();
}
int count = 0;
void loop()
{
    if (tampilan.displayAnimate())
        tampilan.displayText("HELLO", PA_CENTER, 70, 0, PA_SCROLL_UP, PA_SCROLL_UP);
}