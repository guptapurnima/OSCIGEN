#include <TFT_eSPI.h>
#include "AiEsp32RotaryEncoder.h"

#define ROTARY_ENCODER_A_PIN    34
#define ROTARY_ENCODER_B_PIN    35
#define ROTARY_ENCODER_BUTTON_PIN 32
#define BTN1_PIN 33
#define BTN2_PIN 25
#define BTN3_PIN 26

TFT_eSPI tft = TFT_eSPI();
AiEsp32RotaryEncoder rotaryEncoder =
  AiEsp32RotaryEncoder(
    ROTARY_ENCODER_A_PIN,
    ROTARY_ENCODER_B_PIN,
    ROTARY_ENCODER_BUTTON_PIN,
    -1, 4);

const char* menuItems[] = {
  "Oscilloscope",
  "Signal Gen",
  "IMU Monitor",
  "LED Matrix",
  "System Info"
};
const int menuCount = 5;
int selectedItem = 0;

void IRAM_ATTR readEncoderISR() {
  rotaryEncoder.readEncoder_ISR();
}

void drawMenu() {
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_CYAN);
  tft.setTextSize(2);
  tft.setCursor(10, 8);
  tft.println("CYBERDECK  v1.0");
  tft.drawFastHLine(0, 32, 480, TFT_CYAN);

  for (int i = 0; i < menuCount; i++) {
    int y = 44 + i * 52;
    if (i == selectedItem) {
      tft.fillRect(0, y, 480, 48, TFT_CYAN);
      tft.setTextColor(TFT_BLACK);
    } else {
      tft.fillRect(0, y, 480, 48, TFT_BLACK);
      tft.setTextColor(TFT_WHITE);
    }
    tft.setTextSize(2);
    tft.setCursor(20, y + 14);
    tft.println(menuItems[i]);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);
  pinMode(BTN3_PIN, INPUT_PULLUP);

  rotaryEncoder.begin();
  rotaryEncoder.setup(readEncoderISR);
  rotaryEncoder.setBoundaries(0, menuCount - 1, true);
  rotaryEncoder.setAcceleration(0);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  drawMenu();
}

void loop() {
  if (rotaryEncoder.encoderChanged()) {
    selectedItem = rotaryEncoder.readEncoder();
    drawMenu();
  }

  if (rotaryEncoder.isEncoderButtonClicked()) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN);
    tft.setTextSize(2);
    tft.setCursor(10, 140);
    tft.print("Opening: ");
    tft.println(menuItems[selectedItem]);
    delay(1500);
    drawMenu();
  }
}