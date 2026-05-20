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

void setup()
{
    // UART
    Serial.begin(UART_BAUD);

    // LED初期化
    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);
    app_neopixel_init(RGBLED_NUM, RGBLED_MAX_BRIGHTNESS);
    app_neopixel_set_color(0, NEOPIXCEL_COLOR_OFF);

    // FreeRTOS初期化 & OS起動
    app_rtos_init();
}

void loop()
{
    // NOTE; Loopタスクはサスペンドで寝かせとく
    vTaskSuspend(NULL);
}