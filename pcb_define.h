/**
 * @file pcb_define.h
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief 基板定義(ESP32-C6)
 * @version 0.1
 * @date 2026-05-20
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#ifndef PCB_DEFINE_H
#define PCB_DEFINE_H

// -----------------------------------------------------------
// [コンパイルスイッチ]

// [ESP32-C6 Super Mini] https://www.espboards.dev/esp32/esp32-c6-super-mini/
#define PCB_ESP32_C6_SUPER_MINI

// -----------------------------------------------------------
#ifdef PCB_ESP32_C6_SUPER_MINI
#define OB_LED_PIN        15 // オンボードLED    @GPIO 15
#define OB_RGBLED_PIN      8 // オンボードRGBLED @GPIO 8

#define UART_BAUD         115200
#endif // PCB_YD_ESP32_S3

// -----------------------------------------------------------
// [DeepSleep]
#include "esp_sleep.h"
#define DEEPSLEEP_TIME_US_30SEC     (30ULL    * 1000000ULL) // DeepSleep @30秒
#define DEEPSLEEP_TIME_US_1MIN      (60ULL    * 1000000ULL) // DeepSleep @1分
#define DEEPSLEEP_TIME_US_2MIN      (120ULL   * 1000000ULL) // DeepSleep @2分
#define DEEPSLEEP_TIME_US_3MIN      (180ULL   * 1000000ULL) // DeepSleep @3分
#define DEEPSLEEP_TIME_US_5MIN      (300ULL   * 1000000ULL) // DeepSleep @5分
#define DEEPSLEEP_TIME_US_10MIN     (600ULL   * 1000000ULL) // DeepSleep @10分
#define DEEPSLEEP_TIME_US_15MIN     (900ULL   * 1000000ULL) // DeepSleep @15分
#define DEEPSLEEP_TIME_US_20MIN     (1200ULL  * 1000000ULL) // DeepSleep @20分
#define DEEPSLEEP_TIME_US_30MIN     (1800ULL  * 1000000ULL) // DeepSleep @30分
#define DEEPSLEEP_TIME_US_1HOUR     (3600ULL  * 1000000ULL) // DeepSleep @1時間
#define DEEPSLEEP_TIME_US_2HOUR     (7200ULL  * 1000000ULL) // DeepSleep @2時間
#define DEEPSLEEP_TIME_US_3HOUR     (10800ULL * 1000000ULL) // DeepSleep @3時間
#define DEEPSLEEP_TIME_US_5HOUR     (18000ULL * 1000000ULL) // DeepSleep @5時間
#define DEEPSLEEP_TIME_US_8HOUR     (28800ULL * 1000000ULL) // DeepSleep @8時間
#define DEEPSLEEP_TIME_US_12HOUR    (43200ULL * 1000000ULL) // DeepSleep @12時間
#define DEEPSLEEP_TIME_US_24HOUR    (86400ULL * 1000000ULL) // DeepSleep @24時間

#define DEEPSLEEP_TIME_US           DEEPSLEEP_TIME_US_1MIN

// -----------------------------------------------------------

#endif // PCB_DEFINE_H