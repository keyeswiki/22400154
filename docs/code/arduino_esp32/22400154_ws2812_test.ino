/*
 * 22400154 - WS2812 RGB 灯带基础测试
 * 平台：ESP32（Arduino 框架）
 * 依赖：Adafruit NeoPixel by Adafruit
 * 数据引脚：GPIO 12
 * 灯珠数量：10
 */

#include <Adafruit_NeoPixel.h>

constexpr uint8_t DATA_PIN = 12;
constexpr uint16_t LED_COUNT = 10;
// 亮度范围 0~255。测试时使用较低亮度，以降低电源压力。
constexpr uint8_t TEST_BRIGHTNESS = 40;

Adafruit_NeoPixel strip(LED_COUNT, DATA_PIN, NEO_GRB + NEO_KHZ800);

void fillColor(uint8_t red, uint8_t green, uint8_t blue) {
  for (uint16_t i = 0; i < strip.numPixels(); ++i) {
    strip.setPixelColor(i, strip.Color(red, green, blue));
  }
  strip.show();
}

void setup() {
  strip.begin();
  strip.setBrightness(TEST_BRIGHTNESS);
  strip.clear();
  strip.show();
}

void loop() {
  fillColor(255, 0, 0);   // 红色
  delay(800);
  fillColor(0, 255, 0);   // 绿色
  delay(800);
  fillColor(0, 0, 255);   // 蓝色
  delay(800);
  fillColor(255, 255, 255); // 低亮度白色
  delay(800);
  fillColor(0, 0, 0);     // 熄灭
  delay(500);
}
