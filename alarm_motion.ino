const int BUZZPIN = 8;
const int PIRPIN = 2;

void setup()
{
    pinMode(PIRPIN, INPUT);
}

int pirStat = 0;
void loop()
{

    pirStat = digitalRead(PIRPIN);
    if (pirStat == HIGH)
    {
        for (int i = 700; i < 800; i++)
        {
            tone(BUZZPIN, i);
            delay(15);
        }
        for (int i = 800; i > 700; i--)
        {
            tone(BUZZPIN, i);
            delay(15);
        }
    }
    else
    {
        noTone(BUZZPIN);
    }
}