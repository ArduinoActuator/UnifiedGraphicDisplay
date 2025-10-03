# 動作確認(簡易版)


## 動作確認結果のまとめ

|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## API一覧

```
UnifiedGraphicDisplay(GigaDisplay_GFX *tft, UnifiedDisplayType type);
graphicFunctionReturnValue fillScreen(uint16_t color);
graphicFunctionReturnValue setTextColor(uint16_t fg, uint16_t bg);
graphicFunctionReturnValue setCursor(int16_t x, int16_t y);
graphicFunctionReturnValue setTextWrap(bool w);
graphicFunctionReturnValue setTextSize(uint8_t s);
graphicFunctionReturnValue setTextSize(uint8_t sx, uint8_t sy);
graphicFunctionReturnValue setFont(const GFXfont *f=NULL);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h);
uint16_t width(void);
uint16_t height(void);
size_t write(uint8_t c);
```


```

typedef enum {
  DISPLAY_TYPE_GIGA_DISPLAY_GFX =1,
  DISPLAY_TYPE_ADAFRUIT_GFX,
  DISPLAY_TYPE_BODMER_TFT_ESPI
} UnifiedDisplayType;

typedef enum {
  GFX_FUNCTION_UNSUPPORTED = 1,
  GFX_FUNCTION_SUCCESS,
  GFX_FUNCTION_FAIL,
} graphicFunctionReturnValue;

```


## テストシナリオ1 : 画面サイズの取得

### テスト対象API
```
uint16_t width(void);
uint16_t height(void);
```

### 動作
- 人の合図(スタート)を待つ
- 取得した画面サイズをシリアルに出力する
- 人に確認してもらう


### テスト結果

|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## テストシナリオ2 : 画面の塗りつぶし


### テスト対象API
```
graphicFunctionReturnValue fillScreen(uint16_t color);
```

### 動作
- 画面を消す(黒で塗りつぶす)
- 人の合図(スタート)を待つ
- 白，灰色，黒，赤，青，緑で塗りつぶす (表示時間は2秒)．この際，塗りつぶす色をシリアルに出力
- 人に確認してもらう


### テスト結果




|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## テストシナリオ3 : カーソル位置変更と文字/背景色設定

### テスト対象API
```
graphicFunctionReturnValue setTextColor(uint16_t fg, uint16_t bg);
graphicFunctionReturnValue setCursor(int16_t x, int16_t y);
? size_t write(uint8_t c);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- 0行目0列目に「白背景，黒文字」で「1」を印字
- 0行目4列目に「灰背景，赤文字」で「2」を印字
- 0行目8列目に「赤背景，青文字」で「3」を印字
- 1行目2列目に「青背景，黒文字」で「4」を印字
- 1行目6列目に「緑背景，赤文字」で「5」を印字
- 2行目4列目に「灰背景，緑文字」で「6」を印字
- 2行目8列目に「黒背景，白文字」で「7」を印字
- 人に確認してもらう


### テスト結果


|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## テストシナリオ4 : 印字の折り返しの違いの確認

### テスト対象API
```
graphicFunctionReturnValue setTextWrap(bool w);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- ``setTextWrap(false)``で折り返しは無効にする．
- 1行目に白文字で「abcdefg...z」まで印字(印字しながらシリアルにも描画した文字を出力)
- 2行目1列目にカーソル設定
- 2行目に赤文字で「abcdefg...z」まで印字(印字しながらシリアルにも描画した文字を出力)
- 人に確認してもらう

### テスト結果


|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## テストシナリオ5 : 文字サイズ設定(等倍)

### テスト対象API
```
graphicFunctionReturnValueint setTextSize(uint8_t s);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- 1,2,3,4,5,6,7,8までサイズを変えて「A」を印字
- 人に確認してもらう

### テスト結果

|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## テストシナリオ6 : 文字サイズ設定

### テスト対象API
```
graphicFunctionReturnValue setTextSize(uint8_t sx, uint8_t sy);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- カーソル位置を0,0に設定
- サイズを4x1, 4x2, 4x3, 4x4まで変化させて「A」を印字
- サイズを4x5, 4x6, 4x7, 4x8まで変化させて「A」を印字
- 人に確認してもらう

### テスト結果


|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## テストシナリオ7 : オリジナルフォント利用

### テスト対象API
```
graphicFunctionReturnValue setFont(const GFXfont *f=NULL);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- 通常のフォントで，``Hello world!``を印字
- 2行目にカスタムフォントで``Hello World!``を印字
- 人に確認してもらう

### 参考
フォントの生成とそれをArduinoで使う場合は以下の参考文献を参照してください．
- [参考文献](https://qiita.com/tama326/items/c255bd6a58e4092f5508)


### テスト結果

|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## テストシナリオ8 : 小さなbitmapを異なる方法で描画

### テスト対象API
```
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h);
graphicFunctionReturnValue drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h);
```

### 動作
- 画面を真っ黒に塗る
- 人の合図(スタート)を待つ
- 以下を4回繰り返し
  - シリアルに何番目のAPIテストかを表示
  - bitmap画像を表示
  - 人に確認してもらう

### 参考
bitmap画像の作り方等は以下の参考文献を参照．
- [参考文献](https://qiita.com/caa45040/items/9be0f54507e03ccc8a0f)

### テスト結果

|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|◯|
|[Arduino Mega 2560][Mega2560]|-|未|
|[Arduino M0 pro][M0Pro]|-|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|-|未|
|[Arduino Nano 33 IoT][Nano33IoT]|-|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|◯|
|[Ardino MKR Zero][MKRZero]|-|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|-|未|


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



## テスト環境




|ソフトウェア/Arduinoファミリ|モジュール名|開発元|バージョン|
|---|---|---|---|
|Arduino IDE|－|Arduino|2.3.2|
|AVR|Arduino AVR Boards|Arduino|1.8.6|
|ESP32|Arduino ESP32 Boards|Arduino|2.0.18|
|Giga|Arduino Mbed OS Giga Boards|Arduino|4.3.1|
|Nano|Arduino Mbed OS Nano Boards|Arduino|4.3.1|
|M0|Arduino SAMD Boards (32bits ARM Cortex-M0+)|Arduino|1.8.14|
|UnoR4|Arduino Uno R4 Boards|Arduino|1.4.1|

### コンパイルテスト

|Arduino機種|コンパイル結果|
|---|---|
|[Arduino Nano ESP32][NanoESP32]||
|[Arduino Mega 2560][Mega2560]||
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 WiFi][UnoR4WiFi]||
|[Arduino UNO R4 Minima][UnoR4Minima]||
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]||
|[Arduino MKR WiFi 1010][MKRWiFi1010]||
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||



|内容|意味|
|---|---|
|◯|コンパイル成功|
|△|条件付き|
|✕|コンパイルできない|
|-|原理的に互換性がない|
|未|未検証|

<!-- 

### テスト結果


|機種名|[GIGA Display Shield][GigaDisplayShield]|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|||
|[Arduino Mega 2560][Mega2560]|||
|[Arduino M0 pro][M0Pro]|||
|[Arduino UNO R4 WiFi][UnoR4WiFi]|||
|[Arduino UNO R4 Minima][UnoR4Minima]|||
|[Arduino Nano 33 IoT][Nano33IoT]|||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|||
|[Arduino MKR WiFi 1010][MKRWiFi1010]|||
|[Ardino MKR Zero][MKRZero]|||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


 -->



<!-- グラフィックディスプレイ -->

|種類|名称/機種|ライブラリ|電圧(V)|
|---|---|---|---|
|フルカラー|[GIGA Display Shield][GigaDisplayShield]|[Giga display library][Arduino_GigaDisplay_GFX]|3.3|
|フルカラー|[ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶][MSP2807]|[Adafruit ILI9341 Arduino Library][Adafruit ILI9341 Arduino Library]|3.3|

<!-- |モノクロ|[Grove OLED  v1.1][GroveOLEDv1.1]|3.3～5.5| -->

<!-- GIGA Display Shield -->
[GigaDisplayShield]:https://docs.arduino.cc/hardware/giga-display-shield/
<!-- ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶 MSP2807 -->
[MSP2807]:https://akizukidenshi.com/catalog/g/g116265/
<!-- Grove OLED  v1.1 -->
[GroveOLEDv1.1]:https://wiki.seeedstudio.com/ja/Grove-OLED_Display_0.96inch/

<!-- LCD Wiki of MSP2807 -->
[MSP2807_Wiki]:https://www.lcdwiki.com/2.8inch_SPI_Module_ILI9341_SKU:MSP2807

<!-- Arduino_GigaDisplay_GFX -->
[Arduino_GigaDisplay_GFX]:https://github.com/arduino-libraries/Arduino_GigaDisplay_GFX

<!-- Arduino_GigaDisplay_GFX -->
[Adafruit GFX Library]:https://github.com/adafruit/Adafruit-GFX-Library

<!-- Adafruit ILI9341 Arduino Library -->
[Adafruit ILI9341 Arduino Library]:https://github.com/adafruit/Adafruit_ILI9341

<!-- Bodmer/TFT_eSPI -->
[Bodmer_TFT_eSPI]:https://github.com/Bodmer/TFT_eSPI

<!-- ST touch GFX -->
[RGB565]:https://support.touchgfx.com/ja/docs/basic-concepts/color-formats


<!-- Arduino 本体 -->


|機種名|コア|MCU|動作電圧|
|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|Xtensa LX6|ESP32-S3|3.3V|
|[Arduino Mega 2560][Mega2560]|AVR|ATmega2560|5V|
|[Arduino M0 pro][M0Pro]|ARM Cortex-M0+|ATSAMD21G18|3.3V|
|[Arduino UNO R4 WiFi][UnoR4WiFi]|ARM Cortex-M4|RA4M1|5V|
|[Arduino UNO R4 Minima][UnoR4Minima]|ARM Cortex-M4|RA4M1|5V|
|[Arduino Nano 33 IoT][Nano33IoT]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|ARM Cortex-M7|STM32H747XI|3.3V|
|[Arduino MKR WiFi 1010][MKRWiFi1010]|ARM Cortex-M0+|SAMD21|3.3V|
|[Ardino MKR Zero][MKRZero]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|ARM Cortex-M0+|Raspberry Pi RP2040|3.3V|

<!-- Arduino Nano ESP32 -->
[NanoESP32]:https://docs.arduino.cc/hardware/nano-esp32/
<!--Arduino Mega 2560-->
[Mega2560]:https://docs.arduino.cc/hardware/mega-2560/
<!--Arduino M0 pro-->
[M0Pro]:https://docs.arduino.cc/retired/boards/arduino-m0-pro/
<!--Arduino UNO R4 WiFi-->
[UnoR4WiFi]:https://docs.arduino.cc/hardware/uno-r4-wifi/
<!--Arduino UNO R4 Minima-->
[UnoR4Minima]:https://docs.arduino.cc/hardware/uno-r4-minima/
<!--Arduino Nano 33 IoT-->
[Nano33IoT]:https://docs.arduino.cc/hardware/nano-33-iot/
<!--Arduino Giga R1 Wifi-->
[GigaR1WiFi]:https://docs.arduino.cc/hardware/giga-r1-wifi/
<!--Arduino MKR WiFi 1010-->
[MKRWiFi1010]:https://docs.arduino.cc/hardware/mkr-wifi-1010/
<!--Ardino MKR Zero-->
[MKRZero]:https://docs.arduino.cc/hardware/mkr-zero/
<!--Arduino Nano RP2040 Connect-->
[NanoRP2040Connect]:https://docs.arduino.cc/hardware/nano-rp2040-connect/




<!--- コメント
[Adafruit Unified Sensor Driver][AdafruitUSD]
[Groveシールド][shield]
[Arduino M0 Pro][M0Pro]
[Arduino Due][Due]
[Arduino Uno R3][Uno]
[Arduino Mega2560 R3][Mega]
[Arduino Leonardo Ethernet][LeonardoEth]
[Arduino Pro mini 328 - 3.3V/8MHz][ProMini]
[ESpr one][ESPrOne]
[ESPr one 32][ESPrOne32]
[Grove][Grove]
[Seed Studio][SeedStudio]
[Arduino][Arduino]
[Sparkfun][Sparkfun]
[スイッチサイエンス][SwitchScience]
--->
