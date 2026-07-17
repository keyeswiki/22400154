"""
22400154 - WS2812 RGB 灯带基础测试
平台：ESP32 + MicroPython
数据引脚：GPIO 12
灯珠数量：10

说明：代码使用 MicroPython 固件常见的 machine 与 neopixel 模块。
若导入 neopixel 失败，请改用包含该模块的官方/兼容 ESP32 MicroPython 固件。
"""

from machine import Pin
import neopixel
import time

DATA_PIN = 12
LED_COUNT = 10
# 使用较低的 RGB 数值测试，降低电源压力。
TEST_LEVEL = 32

pixels = neopixel.NeoPixel(Pin(DATA_PIN, Pin.OUT), LED_COUNT)


def fill(color):
    for index in range(LED_COUNT):
        pixels[index] = color
    pixels.write()


try:
    while True:
        fill((TEST_LEVEL, 0, 0))
        time.sleep_ms(800)
        fill((0, TEST_LEVEL, 0))
        time.sleep_ms(800)
        fill((0, 0, TEST_LEVEL))
        time.sleep_ms(800)
        fill((TEST_LEVEL, TEST_LEVEL, TEST_LEVEL))
        time.sleep_ms(800)
        fill((0, 0, 0))
        time.sleep_ms(500)
except KeyboardInterrupt:
    fill((0, 0, 0))
