const int LAMPPIN = 8;
const int PIRPIN = 2;

void setup()
{
    pinMode(PIRPIN, INPUT);
    pinMode(LAMPPIN, OUTPUT);
}

void loop()
{
    if (digitalRead(PIRPIN) == HIGH)
    {
        digitalWrite(LAMPPIN, HIGH);
    }
    else
    {
        digitalWrite(LAMPPIN, LOW);
    }
}
