# UnifiedGraphicDisplay

このHardware Abstraction Layer(HAL)は，Arduinoに[GIGA Display Shield][GigaDisplayShield]の
ようなグラフィックディスプレイとSD(やマイクロSD)を接続し，SD上に保存された
イメージとコマンドで送られた文字列を表示することで，スライドショーのようなものを
実現するためのものである．

今のところ，統合を目指しているグラフィックディスプレイ用ライブラリは以下の3種類．
- [GIGA Display Shield用ライブラリ][Arduino_GigaDisplay_GFX]
- [TFT_eSPI Library][TFT_eSPI]
- [Adafruit ILI9341 Arduino Library][ILI9341Lib]

## 動作確認済みデバイス
現状，動作が確認できているのは以下のディスプレイのみ．
- [GIGA Display Shield][GigaDisplayShield]

## 使い方
このHALは設定を変更しないと，3種類のグラフィックディスプレイ用のデバイスドライバを
取り込んでしまうため，メモリの無駄が発生する．これを防止するためには，
```UnifiedGraphicDisplay_config.h```の```#undef```を使い，使用するライブラリのみを
取り込むようにする．以下の例は，[GIGA Display Shield][GigaDisplayShield]のみを
使う設定．

```C:UnifiedGraphicDisplay_config.h
//#undef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
#undef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
#undef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
```


<!-- 以下は，外部リンクの定義 
- Adafruit Unified Sensor Driver - [https://github.com/adafruit/Adafruit_Sensor][AdafruitUSD]
-->


<!-- Arduino_GigaDisplay_GFX Library -->
[Arduino_GigaDisplay_GFX]:https://github.com/arduino-libraries/Arduino_GigaDisplay_GFX
<!-- GIGA Display Shield -->
[GigaDisplayShield]:https://docs.arduino.cc/hardware/giga-display-shield/
<!-- Adafruit ILI9341 Arduino Library -->
[ILI9341Lib]:https://github.com/adafruit/Adafruit_ILI9341
<!-- TFT_eSPI Library -->
[TFT_eSPI]:https://github.com/Bodmer/TFT_eSPI


<!-- 以下は，外部リンクの定義 -->
[GroveBarometerSensorBMP180]:http://wiki.seeedstudio.com/Grove-Barometer_Sensor-BMP180/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[AdafruitUSD]:https://github.com/adafruit/Adafruit_Sensor
[shield]:https://www.seeedstudio.com/Base-Shield-V2-p-1378.html
[M0Pro]:https://store.arduino.cc/usa/arduino-m0-pro
[Due]:https://store.arduino.cc/usa/arduino-due
[Uno]:https://store.arduino.cc/usa/arduino-uno-rev3
[UnoWiFi]:https://store.arduino.cc/usa/arduino-uno-wifi-rev2
[Mega]:https://store.arduino.cc/usa/arduino-mega-2560-rev3
[LeonardoEth]:https://store.arduino.cc/usa/arduino-leonardo-eth
[ProMini]:https://www.sparkfun.com/products/11114
[ESPrDev]:https://www.switch-science.com/catalog/2652/
[ESPrDevShield]:https://www.switch-science.com/catalog/2811/
[ESPrOne]:https://www.switch-science.com/catalog/2620/
[ESPrOne32]:https://www.switch-science.com/catalog/3555/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[Arduino]:http://https://www.arduino.cc/
[Sparkfun]:https://www.sparkfun.com/
[SwitchScience]:https://www.switch-science.com/
[AusExGrove3AxisDigitalAccelerometer1_5g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/
[AusExGrove3AxisDigitalAccelerometer16g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/
[AusExGrove3AxisDigitalGyro]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Gyro/
[AusExGroveI2cTouchSensor]:http://wiki.seeedstudio.com/Grove-I2C_Touch_Sensor/
[AusExGroveAnalog1AxisGyro]:http://wiki.seeedstudio.com/Grove-Single_Axis_Analog_Gyro/
[AusExGroveAnalogCurrentSensor]:http://wiki.seeedstudio.com/Grove-Electricity_Sensor/
[AusExGroveAnalogTemperatureSensor]:http://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
[AusExGroveGsr]:http://wiki.seeedstudio.com/Grove-GSR_Sensor/
[AusExGroveRotaryAngleSensor]:http://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/
[AusExGroveSimpleLight]:http://wiki.seeedstudio.com/Grove-Light_Sensor/
[AusExGroveSimpleMoisture]:http://wiki.seeedstudio.com/Grove-Moisture_Sensor/
[AusExGroveSimpleSound]:http://wiki.seeedstudio.com/Grove-Loudness_Sensor/
[AusExDigitalSwitch]:http://wiki.seeedstudio.com/Grove-Switch-P/
[AusExGroveDustSensor]:http://wiki.seeedstudio.com/Grove-Dust_Sensor/
[AusExGroveInfraredDistanceSensor]:http://wiki.seeedstudio.com/Grove-IR_Distance_Interrupter_v1.2/
[AusExGroveInfraredReflectiveSensor]:http://wiki.seeedstudio.com/Grove-Infrared_Reflective_Sensor/
[AusExGroveTouchSensor]:http://wiki.seeedstudio.com/Grove-Touch_Sensor/
[AusExGroveUltrasonicRanger]:http://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/
[AusExGroveWaterSensor]:http://wiki.seeedstudio.com/Grove-Water_Sensor/
[AusExGrovePirSensor]:http://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/


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
