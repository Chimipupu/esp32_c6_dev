/**
 * @file esp32_c6_dev.ino
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief ESP32-C6 評価F/W @Arduino IDE用ファイル
 * @version 0.1
 * @date 2026-05-12
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include "pcb_define.h"
#include "app_wifi.h"
#include "app_neopixel.h"

// -----------------------------------------------------------
static void _vTaskMain(void *p_parameter);

// -----------------------------------------------------------
// [Static]

static void _vTaskMain(void *p_parameter)
{
    static bool s_led_val = true;

    while (1)
    {
        digitalWrite(OB_LED_PIN, s_led_val ? HIGH : LOW);
        s_led_val = !s_led_val;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

// -----------------------------------------------------------
void setup()
{
    // UART
    Serial.begin(UART_BAUD);

    // LED初期化
    pinMode(OB_LED_PIN, OUTPUT);
    digitalWrite(OB_LED_PIN, HIGH);
    app_neopixel_init(RGBLED_NUM, RGBLED_MAX_BRIGHTNESS);
    app_neopixel_set_color(0, NEOPIXCEL_COLOR_OFF);

    // WiFi初期化
    // app_wifi_init();
    // app_wifi_main();

    xTaskCreatePinnedToCore(_vTaskMain,    // コールバック関数ポインタ
                            "vTaskMain",  // タスク名
                            2048,         // スタック
                            NULL,         // パラメータ
                            2,            // 優先度(0～7、7が最優先)
                            NULL,         // ハンドル
                            0);
}

void loop()
{
    app_neopixel_rgb_illumination(0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
}