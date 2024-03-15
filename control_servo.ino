#include <Servo.h>
const int POTENSIAPIN = A5;
const int POTENSIBPIN = A3;
const int SERVOAPIN = 9;
const int SERVOBPIN = 10;

Servo servoA;
Servo servoB;

void setup()
{
    pinMode(POTENSIAPIN, INPUT);
    pinMode(POTENSIBPIN, INPUT);
    servoA.attach(SERVOAPIN);
    servoB.attach(SERVOBPIN);
}

void loop()
{
    int potensiA = analogRead(POTENSIAPIN);
    potensiA = map(potensiA, 0, 1023, 0, 180);
    int potensiB = analogRead(POTENSIBPIN);
    potensiB = map(potensiB, 0, 1023, 0, 180);

    servoA.write(potensiA);
    servoB.write(potensiB);
}
