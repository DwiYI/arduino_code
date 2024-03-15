
int LEDSPIN[7] = {2, 3, 4, 5, 6, 7, 8};

const int POTENSI = A5;
void setup()
{
    pinMode(LEDSPIN[0], OUTPUT);
    pinMode(LEDSPIN[1], OUTPUT);
    pinMode(LEDSPIN[2], OUTPUT);
    pinMode(LEDSPIN[3], OUTPUT);
    pinMode(LEDSPIN[4], OUTPUT);
    pinMode(LEDSPIN[5], OUTPUT);
    pinMode(LEDSPIN[6], OUTPUT);

    pinMode(POTENSI, INPUT);
}

void loop()
{
    int pot = analogRead(POTENSI);
    pot = map(pot, 0, 1023, 0, 7);

    for (int i = 0; i < 7; i++)
    {
        if (pot > i)
        {
            digitalWrite(LEDSPIN[i], HIGH);
        }
        else
        {
            digitalWrite(LEDSPIN[i], LOW);
        }
    }
}
