
byte off  = 48;  // key '0'
byte pin10 = 49; // key '1'
byte pin11 = 50; // key '2'
byte pin12 = 51; // key '3'
byte pin13 = 52; // key '4'
byte pin10_dimmer = 53; // key '5'

void setup() {
    Serial.begin(9600);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop() {

    if (Serial.available() > 0) {
        // read the incoming byte:
        byte incomingByte = Serial.read();
        
        // disable all pins
        if (incomingByte == 48) {
            Serial.println("un-pressing all");
            for (int i=2; i<=13; i++) {
                digitalWrite(i, LOW);
            }
        }

        // turn on pin 10
        if (incomingByte == pin10) {
            Serial.println("pressing 10, light toggle");
            digitalWrite(10, HIGH);
            delay(300);
            digitalWrite(10, LOW);
        }
        
        // turn on pin 10 -- hold for dimmer
        if (incomingByte == pin10_dimmer) {
            Serial.println("pressing 10, light dimmer 12 seconds");
            digitalWrite(10, HIGH);
            delay(12000);
            digitalWrite(10, LOW);
        }

        // turn on pin 11
        if (incomingByte == pin11) {
            Serial.println("pressing 11, fan off");
            digitalWrite(11, HIGH);
            delay(300);
            digitalWrite(11, LOW);
        }
        
        // turn on pin 12
        else if (incomingByte == pin12) {
            Serial.println("pressing 12, fan medium");
            digitalWrite(12, HIGH);
            delay(300);
            digitalWrite(12, LOW);
        }

        // turn on pin 13
        if (incomingByte == pin13) {
            Serial.println("pressing 13, fan high");
            digitalWrite(13, HIGH);
            delay(300);
            digitalWrite(13, LOW);
        }

        else {
            Serial.println("unknown byte");
            Serial.println(incomingByte);
        }
    }
}


