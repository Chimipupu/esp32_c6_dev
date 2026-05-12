/**
 * @file esp32_c6_dev.ino
 * @author Chimipupu(https://github.com/Chimipupu)
 * @brief ESP32-C6 評価F/W @Arduino IDE用ファイル
 * @version 0.1
 * @date 2026-05-12
 * @copyright Copyright (c) 2026 Chimipupu All Rights Reserved.
 */

#include "app_wifi.h"

// -----------------------------------------------------------
#define UART_BAUD    6000000 // UART @CH343P 6Mbps 8N1

// -----------------------------------------------------------
// [Static]

// -----------------------------------------------------------
void setup()
{
    // UART
    Serial.begin(UART_BAUD);

    // WiFi初期化
    app_wifi_init();
}

void loop()
{
    // WiFiアプリ メイン
    app_wifi_main();
}