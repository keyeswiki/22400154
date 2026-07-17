# 22400154 测试代码说明

| 目录 | 适用环境 | 依赖 |
|---|---|---|
| `arduino_esp32/` | ESP32 Arduino 框架 | Adafruit NeoPixel |
| `micropython_esp32/` | ESP32 MicroPython | 固件自带 `machine`、`neopixel` 模块 |

两个示例均按 **GPIO 12**、**10 颗灯珠**配置。首次上电采用低亮度红、绿、蓝、白、熄灭循环，以便检查数据方向、颜色顺序和坏点。请先核对灯带箭头方向，从 `DIN` 端输入数据，并确保控制板与灯带共地。
