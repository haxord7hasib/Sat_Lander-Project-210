#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

RF24 radio(7, 8); // CE, CSN pins
const byte address[6] = "00001";
MPU6050 mpu;
unsigned long lastTime;
float dt, filteredAngleX, filteredAngleY;

void setup() {
  Wire.begin();
  mpu.initialize();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  lastTime = millis();
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  unsigned long currentTime = millis();
  dt = (currentTime - lastTime) / 1000.0;
  lastTime = currentTime;

  // Calculate angles
  float roll = atan2(ay, az) * 180/PI;
  float pitch = atan2(-ax, sqrt(ay * ay + az * az)) * 180/PI;

  // Complementary filter
  filteredAngleX = 0.98 * (filteredAngleX + gx * dt) + 0.02 * roll;
  filteredAngleY = 0.98 * (filteredAngleY + gy * dt) + 0.02 * pitch;

  // Create a struct to hold the data
  struct {
    float angleX;
    float angleY;
  } data = {filteredAngleX, filteredAngleY};

  // Send the data
  radio.write(&data, sizeof(data));
  delay(100);
}
