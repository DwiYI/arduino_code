#include <IRremote.h>

const int IRPIN = 5;
const int LAMPPIN = 8;
void setup()
{
    Serial.begin(9600);
    IrReceiver.begin(IRPIN, ENABLE_LED_FEEDBACK);
    pinMode(LAMPPIN, OUTPUT);
}

int lastStateLampu = LOW;
int currentStateLampu;
int statusLampu = false;

void buttonLampu()
{

    if (lastStateLampu == HIGH && currentStateLampu == LOW)
    {
        if (statusLampu)
        {
            statusLampu = false;
            digitalWrite(LAMPPIN, LOW);
        }
        else
        {
            statusLampu = true;
            digitalWrite(LAMPPIN, HIGH);
        }
    }
    lastStateLampu = currentStateLampu;
}

void loop()
{
    if (IrReceiver.decode())
    {
        IrReceiver.resume();
        if (IrReceiver.decodedIRData.command == 28)
        {
            Serial.println(IrReceiver.decodedIRData.command);
            currentStateLampu = HIGH;
        }
    }
    buttonLampu();
    currentStateLampu = LOW;
    delay(100);
}
