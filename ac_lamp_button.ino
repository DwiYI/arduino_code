const int DATAPIN = 8;
const int BUTTONPIN = 5;

int lastStateLampu = LOW;
int currentStateLampu;
int statusLampu = false;

void buttonLampu()
{
    currentStateLampu = digitalRead(BUTTONPIN);

    if (lastStateLampu == HIGH && currentStateLampu == LOW)
    {
        if (statusLampu)
        {
            statusLampu = false;
            digitalWrite(DATAPIN, LOW);
        }
        else
        {
            statusLampu = true;
            digitalWrite(DATAPIN, HIGH);
        }
    }
    lastStateLampu = currentStateLampu;
}

void setup()
{
    pinMode(DATAPIN, OUTPUT);
    pinMode(BUTTONPIN, INPUT);
}

void loop()
{
    buttonLampu();
}