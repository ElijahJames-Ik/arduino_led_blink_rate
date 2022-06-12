#define LED_PIN 11

unsigned long blinkInterval = 300;
unsigned long previousTime = millis();
int ledState = LOW;
void setup(){
    Serial.begin(115200);
    Serial.setTimeout(10);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}


void loop(){
    unsigned long timeNow = millis();
    if(Serial.available() > 0){
        unsigned long value = Serial.parseInt();
        blinkInterval = value;
        Serial.println(value);
    }
    if(timeNow - previousTime >= blinkInterval){
        ledState = ledState == LOW ? HIGH : LOW;
        digitalWrite(LED_PIN, ledState);
        previousTime += blinkInterval;
    }
}