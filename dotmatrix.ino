#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 3

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
void setup()
{
    // Intialize the object:
    myDisplay.begin();
    myDisplay.setZoneEffect(0, true, PA_FLIP_LR);
}
int count = 0;
void loop()
{
    myDisplay.setTextAlignment(PA_CENTER);
    myDisplay.print("HELLO");
    delay(1000);

    myDisplay.setTextAlignment(PA_CENTER);
    myDisplay.print(count++);
    delay(1000);

    myDisplay.setTextAlignment(PA_CENTER);
    myDisplay.print("HELLO");
    delay(1000);
}