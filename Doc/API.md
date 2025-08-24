# API

本APIはAdafruits GFXライブラリと，その系列のライブラリを用いるカラーディスプレイを対象としたものである．

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


## クラスオブジェクトの作成と初期化


### [GIGA Display Shield][GigaDisplayShield]の場合

[Arduino_GigaDisplay_GFX][Arduino_GigaDisplay_GFX]ライブラリを用い，GigaDisplay_GFXクラスの
オブジェクトを作成し，そのオブジェクトとディスプレイの種別を引数として，本APIのクラスオブジェクトを作成する．

```
UnifiedGraphicDisplay(GigaDisplay_GFX *tft, UnifiedDisplayType type);
```

ディスプレイの種別は，以下の``enum``の``DISPLAY_TYPE_GIGA_DISPLAY_GFX``を用いる．
```
enum UnifiedDisplayType {
  DISPLAY_TYPE_GIGA_DISPLAY_GFX =1,
  DISPLAY_TYPE_ADAFRUIT_GFX,
  DISPLAY_TYPE_BODMER_TFT_ESPI
};
```
下は利用例
```
GigaDisplay_GFX tft; // create the object
UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_GIGA_DISPLAY_GFX);
```

### 他の場合の例

[ILI9341搭載ディスプレイ][MSP2807]の場合の利用例は以下の通り．
```
#define TFT_ILI9341_PIN_DC    4
#define TFT_ILI9341_PIN_RST   5
#define TFT_ILI9341_PIN_CS    6

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_ILI9341_PIN_CS, TFT_ILI9341_PIN_DC, TFT_ILI9341_PIN_RST);
UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_ADAFRUIT_GFX);
```

もし，SPIのピンを特別なものを利用する場合は下のようにピン番号を指定する．

```
#define TFT_ILI9341_PIN_DC    4
#define TFT_ILI9341_PIN_RST   5
#define TFT_ILI9341_PIN_CS    6
#define TFT_ILI9341_PIN_MOSI  8
#define TFT_ILI9341_PIN_MISO  10
#define TFT_ILI9341_PIN_CLK   9

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_ILI9341_PIN_CS, TFT_ILI9341_PIN_DC, TFT_ILI9341_PIN_MOSI, TFT_ILI9341_PIN_CLK, TFT_ILI9341_PIN_RST, TFT_ILI9341_PIN_MISO);
UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_ADAFRUIT_GFX);
```

## 一色での塗りつぶし

```
graphicFunctionReturnValue fillScreen(uint16_t color);
```

``color``の値は「RGB565」フォーマット(16bitRGB)で指定します．技術的な内容は[参考文献][RGB565]を参照してください．

- 返り値 : 0(成功), -1(失敗)

## テキストの色設定
テキストを画面に印字する場合，1文字分の領域(四角形)全てが塗られるため，文字色と背景色の両方を指定する．
この時の色は``fillScreen()``と同じく，[RGB565][RGB565]フォーマットの16bitの値で指定する．
```
graphicFunctionReturnValue setTextColor(uint16_t fg, uint16_t bg);
```

- 返り値 : 0(成功), -1(失敗)

## 文字印字のためのカーソル位置指定
画面上の位置(x軸,y軸)の値を引数として本メンバ関数を用いる．
```
graphicFunctionReturnValue setCursor(int16_t x, int16_t y);
```

- 返り値 : 0(成功), -1(失敗)

## テキスト折り返しの設定
画面上に文字列を印字する場合に，画面の端まで到達した場合に折り返して印字を続けるか否かを設定する．
```
graphicFunctionReturnValue setTextWrap(bool w);
```

- 返り値 : 0(成功), -1(失敗)


## テキストサイズ設定(等倍)
テキスト(フォント)のサイズを引数として利用する．

```
graphicFunctionReturnValue setTextSize(uint8_t s);
```


- 返り値 : 0(成功), -1(失敗)



## テキストサイズ設定
テキスト(フォント)のサイズを引数として利用する．縦横のサイズは比例してなくて良い．

```
graphicFunctionReturnValue setTextSize(uint8_t sx, uint8_t sy);
```

- 返り値 : 0(成功), -1(失敗)



## フォント選択
独自に作成したフォントを用いることができるため，そのフォントを指定するためのインターフェイス．
```
graphicFunctionReturnValue setFont(const GFXfont *f=NULL);
```

- 返り値 : 0(成功), -1(失敗)


フォントの生成とそれをArduinoで使う場合は以下の参考文献を参照してください．
- [参考文献](https://qiita.com/tama326/items/c255bd6a58e4092f5508)

## ビットマップイメージの描画
印字位置，印字サイズ，ビットマップイメージと画像に対するマスク値を指定して描画するが，マスクの有無やビットマップイメージのデータの持ち方などで
4種類にある．
```
int drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h);
int drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h);
int drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h);
int drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h);
```

- 返り値 : 0(成功), -1(失敗)

使い方は[Adafruit GFX Library][Adafruit GFX Library]と同じなので，この
[参考文献](https://qiita.com/caa45040/items/9be0f54507e03ccc8a0f)を参照してください．


## 画面サイズの取得
画面サイズ(縦横)を返す．
```
uint16_t width(void);
uint16_t height(void);
```

## テキスト(1文字)の印字
カーソル位置に1文字印字．
```
size_t write(uint8_t c);
```

<!-- グラフィックディスプレイ -->

|種類|名称/機種|電圧(V)|
|---|---|---|
|フルカラー|[GIGA Display Shield][GigaDisplayShield]|3.3|
|モノクロ|[Grove OLED  v1.1][GroveOLEDv1.1]|3.3～5.5|

<!-- GIGA Display Shield -->
[GigaDisplayShield]:https://docs.arduino.cc/hardware/giga-display-shield/

<!-- ILI9341搭載2.8インチSPI制御タッチパネル付TFT液晶 MSP2807 -->
[MSP2807]:https://akizukidenshi.com/catalog/g/g116265/

<!-- Grove OLED  v1.1 -->
[GroveOLEDv1.1]:https://wiki.seeedstudio.com/ja/Grove-OLED_Display_0.96inch/

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
