const int ledPin = 4;
void setup()
{
    pinMode(ledPin, OUTPUT);
}
void loop()
{
    while(true) {
        for(int i = 0;i<=60;i = i + 5) {
            digitalWrite(ledPin, LOW);
            delayMicroseconds(i);
            digitalWrite(ledPin, HIGH);
        }
        for(int i = 60;i>=0;i = i - 5) {
            digitalWrite(ledPin, LOW);
            delayMicroseconds(i);
            digitalWrite(ledPin, HIGH);
        }
    }
}
