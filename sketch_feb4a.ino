#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int lm35Pin = 34;

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    while (true);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  int valorADC = analogRead(lm35Pin);
  valorADC = constrain(valorADC, 0, 4095);

  float voltaje = valorADC * (3.3 / 4095.0);
  float temperatura = voltaje * 100.0; // LM35

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Primer Practica :D");

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print(temperatura, 1); // 1 decimal
  display.print((char)247);
  display.print("C");

  display.display();

  delay(500);
}