#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// CE and CSN pin assignments
RF24 radio(9, 10); // Change these pins if needed

// Address for the communication channel
const byte address[6] = "00001";

void setup() {
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();
}

void loop() {
    const char text[] = "Hello";
    if (radio.write(&text, sizeof(text))) {
        Serial.println("Sent message: Hello");
    } else {
        Serial.println("Sending failed");
    }
    delay(1000);
}
