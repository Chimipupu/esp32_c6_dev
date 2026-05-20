/**
 * @file app_rtos.cpp
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief FreeRTOS アプリ
 * @version 0.1
 * @date 2026-05-20
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include "app_rtos.h"
#include "app_wifi.h"
#include "app_neopixel.h"
#include "pcb_define.h"

// -----------------------------------------------------------
#define TASK_MAIN_DELAY_MS    (100 / portTICK_PERIOD_MS)
#define TASK_WIFI_DELAY_MS    (1000 / portTICK_PERIOD_MS)

static xTaskHandle s_TaskMain_Handle;
static xTaskHandle s_xTaskWiFi_Handle;

static void _vTaskMain(void *p_param);
static void _vTaskWiFi(void *p_param);

// -----------------------------------------------------------
// [Static]

static void _vTaskMain(void *p_param)
{
    static bool s_led_val = true;

    while (1)
    {
        digitalWrite(OB_LED_PIN, s_led_val ? HIGH : LOW);
        s_led_val = !s_led_val;
        vTaskDelay(TASK_MAIN_DELAY_MS / portTICK_PERIOD_MS);
    }
}

static void _vTaskWiFi(void *p_param)
{
    static bool s_wifi_enable = false;

    app_wifi_init(MY_WIFI_SSID, MY_WIFI_PASSWORD);
    s_wifi_enable = true;

    while (1)
    {
        app_wifi_main();
        app_neopixel_rgb_illumination(0);
        vTaskDelay(TASK_WIFI_DELAY_MS / portTICK_PERIOD_MS);
    }
}

// -----------------------------------------------------------
// [API]

void app_rtos_init(void)
{
    xTaskCreatePinnedToCore(_vTaskMain,    // コールバック関数ポインタ
                            "vTaskMain",  // タスク名
                            2048,         // スタック
                            NULL,         // パラメータ
                            0,            // 優先度(0～7、7が最優先)
                            &s_TaskMain_Handle, // ハンドル
                            0);

    xTaskCreatePinnedToCore(_vTaskWiFi,    // コールバック関数ポインタ
                            "vTaskWiFi",  // タスク名
                            16384,        // スタック
                            NULL,         // パラメータ
                            6,            // 優先度(0～7、7が最優先)
                            &s_xTaskWiFi_Handle, // ハンドル
                            0);
}