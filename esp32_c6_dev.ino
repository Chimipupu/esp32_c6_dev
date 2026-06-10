/**
 * @file esp32_c6_dev.ino
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief ESP32-C6 評価F/W @Arduino IDE用ファイル
 * @version 0.1
 * @date 2026-05-20
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include "pcb_define.h"
#include "app_rtos.h"
#include "app_neopixel.h"

// -----------------------------------------------------------
static void _gpio_init(void);

// -----------------------------------------------------------
// [Static]

static void _gpio_init(void)
{
#ifdef PCB_M5_NANO_C6
    pinMode(OB_IR_LED_PIN, OUTPUT);
    pinMode(OB_BUTTON_PIN, INPUT);
    pinMode(OB_RGBLED_EN_PIN, OUTPUT);
    digitalWrite(OB_RGBLED_EN_PIN, HIGH);
#endif // PCB_M5_NANO_C6

    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);
    app_neopixel_init(RGBLED_NUM, RGBLED_MAX_BRIGHTNESS);
    app_neopixel_set_color(0, NEOPIXCEL_COLOR_OFF);
}
// -----------------------------------------------------------
// [App]

void setup()
{
    // GPIO初期化
    _gpio_init();

    // UART
    Serial.begin(UART_BAUD);

    // FreeRTOS初期化 & OS起動
    app_rtos_init();
}

void loop()
{
    // NOTE; Loopタスクはサスペンドで寝かせとく
    vTaskSuspend(NULL);
}
// -----------------------------------------------------------