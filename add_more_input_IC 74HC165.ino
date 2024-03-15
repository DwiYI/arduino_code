class IC74HC165
{
private:
    byte temp;
    int lpin[8] = {0};
    int cpin[8] = {0};
    byte sb[8] = {0b00000001, 0b00000010, 0b00000100, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000};
    int PL;
    int CE;
    int Q7;
    int CP;

public:
    int pin[8] = {0};
    IC74HC165(int,int,int,int);
    void Read();
};

IC74HC165::IC74HC165(int pl, int ce, int q7, int cp)
{
    this->PL = pl;
    this->CE = ce;
    this->Q7 = q7;
    this->CP = cp;
}

void IC74HC165::Read()
{
    digitalWrite(PL, LOW);
    delayMicroseconds(5);
    digitalWrite(PL, HIGH);
    delayMicroseconds(5);
    digitalWrite(CP, HIGH);
    digitalWrite(CE, LOW);
    temp = shiftIn(Q7, CP, MSBFIRST);
    digitalWrite(CE, HIGH);

    for (int i = 0; i < 8; i++)
    {
        /* code */
        lpin[i] = (temp & sb[i]) ? 1 : 0;
        delay(1);
        if (cpin[i] == HIGH && lpin[i] == LOW)
        {
            pin[i] = !pin[i];
        }
        delay(1);
        cpin[i] = lpin[i];
    }
}

// IC PIN
const int load = 3;
const int clockEnablePin = 5;
const int dataIn = 2;
const int clockIn = 4;
const int LED = 6;

IC74HC165 ic(load, clockEnablePin, dataIn, clockIn);
bool statusLampu = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ic.Read();
  if (ic.pin[0] || ic.pin[1] || ic.pin[2] || ic.pin[3] || ic.pin[4] || ic.pin[5]|| ic.pin[6] ||ic.pin[7])
  {
    lampuON();
  }else{
    lampuOFF();
  }
  lampu(statusLampu);
}

void lampu(bool val)
{
    if (val)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {

        digitalWrite(LED, LOW);
    }
}

void lampuON()
{
    statusLampu = true;
}
void lampuOFF()
{
    statusLampu = false;
}
