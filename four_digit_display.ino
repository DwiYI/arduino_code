#include <TM1637.h>

const int CLKPIN = 7;
const int DIOPIN = 6;

TM1637 TM(CLKPIN, DIOPIN);

void setup()
{
    TM.init();
    TM.set(2);
}

boolean toogle;
void loop()
{
    TM.display(0, 1);
    TM.display(1, 2);
    TM.point(toogle = !toogle);
    TM.display(2, 3);
    TM.display(3, 4);
    delay(1000);
}
