
/* Graphic Display */
//#define USE_GIGA_DISPLAY_GFX
//#define USE_BODMER_TFT_ESPI
#define USE_ADAFRUIT_GFX

#define TFT_ILI9341_TYPE_1
//#define TFT_ILI9341_TYPE_2

/*
 * NanoやMKRをClassic (UNO)のシールドを使えるようにするための変換基板を使うか否かの選択
 */
//#define USE_CONVERTER




#include "detectArduinoHardware.h"

#ifdef USE_CONVERTER
#include "ArduinoShieldConverter.h"
#endif /* USE_CONVERTER */

/*
 * 接続ピンの定義
 *   注意事項 : LEDのピンは，PMWが可能なポートに接続すること
 */

#ifdef USE_CONVERTER
#define TFT_ILI9341_PIN_DC    DIGITAL_4
#define TFT_ILI9341_PIN_RST   DIGITAL_5
#define TFT_ILI9341_PIN_CS    DIGITAL_6


//#define TFT_ILI9341_PIN_DC    DIGITAL_4
//#define TFT_ILI9341_PIN_RST   DIGITAL_5
//#define TFT_ILI9341_PIN_CS    DIGITAL_6
#define TFT_ILI9341_PIN_MOSI  DIGITAL_8
#define TFT_ILI9341_PIN_MISO  DIGITAL_10
#define TFT_ILI9341_PIN_CLK   DIGITAL_9
#else /* USE_CONVERTER */
//#define TFT_ILI9341_PIN_DC    9
//#define TFT_ILI9341_PIN_RST   7
//#define TFT_ILI9341_PIN_CS    10
//#define TFT_ILI9341_PIN_MOSI  11
//#define TFT_ILI9341_PIN_MISO  12
//#define TFT_ILI9341_PIN_CLK   13
#define TFT_ILI9341_PIN_DC    4
#define TFT_ILI9341_PIN_RST   3
#define TFT_ILI9341_PIN_CS    2
//#define TFT_ILI9341_PIN_DC    4
//#define TFT_ILI9341_PIN_RST   5
//#define TFT_ILI9341_PIN_CS    6
//#define TFT_ILI9341_PIN_MOSI  8
//#define TFT_ILI9341_PIN_MISO  10
//#define TFT_ILI9341_PIN_CLK   9
#endif /* USE_CONVERTER */

#include "UnifiedGraphicDisplay.h"
#include "HennyPenny-Regular_16.h"
#include "cat.h"


#define MAX_TEST 8

#ifdef USE_GIGA_DISPLAY_GFX
#define DISPLAY_WIDTH 480
#define DISPLAY_HEIGHT  800


GigaDisplay_GFX tft; // create the object
//int giga_display_num = -1;
//int giga_display_type = GRAPHIC_DISPLAY_TYPE_GIGA_DISPLAY;

UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_GIGA_DISPLAY_GFX);
#endif /* USE_GIGA_DISPLAY_GFX */

#ifdef USE_BODMER_TFT_ESPI
#define DISPLAY_WIDTH
#define DISPLAY_HEIGHT


TFT_eSPI tft = TFT_eSPI();
//int bodmer_tft_num = -1;
//int bodmer_tft_type = GRAPHIC_DISPLAY_TYPE_BODMER_TFT;

UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_BODMER_TFT_ESPI);
#endif /* USE_BODMER_TFT_ESPI */

#ifdef USE_ADAFRUIT_GFX
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT  320


#ifdef TFT_ILI9341_TYPE_1
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_ILI9341_PIN_CS, TFT_ILI9341_PIN_DC);
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_ILI9341_PIN_CS, TFT_ILI9341_PIN_DC, TFT_ILI9341_PIN_RST);
#endif /* TFT_ILI9341_TYPE_1 */
#ifdef TFT_ILI9341_TYPE_2
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_ILI9341_PIN_CS, TFT_ILI9341_PIN_DC, TFT_ILI9341_PIN_MOSI, TFT_ILI9341_PIN_CLK, TFT_ILI9341_PIN_RST, TFT_ILI9341_PIN_MISO);
#endif /* TFT_ILI9341_TYPE_2 */
//int adafruit_gfx_num = -1;
//int adafruit_gfx_type = GRAPHIC_DISPLAY_TYPE_ADAFRUIT_GFX;

UnifiedGraphicDisplay display = UnifiedGraphicDisplay(&tft,DISPLAY_TYPE_ADAFRUIT_GFX);
#endif /* USE_ADAFRUIT_GFX */

#define MAX_BUFF_SIZE 256

struct testResultEntity {
  bool result;
  //String about;
  char about[MAX_BUFF_SIZE];
  //String comment;
  char comment[MAX_BUFF_SIZE];
} testResult[MAX_TEST];

void printStartMessage(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
  }
  sprintf(message,"Wait for start test No.%d (%s)",testNumber+1, about.c_str());
  Serial.println(message);
}

void waitForStart(void){
  while (true) {
    if (Serial.available()) {
      char input = Serial.read();
    } else {
      break;
    }
  }
  Serial.print("Please press Enter key to start test : ");
  while (true) {
    if (Serial.available()) {
      String input = Serial.readStringUntil('\n');  // Read until newline
      if (0==input.compareTo("")) {
        Serial.println("");
        break;
      } else {
        Serial.println("");
        Serial.println("Please press **Enter key Only** to start test : ");
      }
    }
  }
}

void checkTestResult(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
    testResult[testNumber].about[i]=0;
    testResult[testNumber].comment[i]=0;
  }
  sprintf(message,"Please input the failure of test No.%d (%s), if the test is succeeded, press Enter : ",testNumber+1, about.c_str());
  sprintf(testResult[testNumber].about,"%s", about.c_str());
  testResult[testNumber].result = true;
  Serial.print(message);
  int count =0;
  while (true) {
    if (Serial.available() > 0) {
      char input = Serial.read();
      if ((input != -1) && (input != '\n')) {
        testResult[testNumber].comment[count]=input;
        testResult[testNumber].result = false;
        count++;
        Serial.print(input);
      }
      if ((count == MAX_BUFF_SIZE-2) || (input == '\n')) break;
    }
  }
  Serial.println("");
}

void sumTestResult(void){
  int count = 0;
  Serial.println("======== summary of tests ========");
  for (int i=0 ; i<MAX_TEST ; i++ ) {
    char message[MAX_BUFF_SIZE];
    for (int i=0; i<MAX_BUFF_SIZE; i++) {
      message[i]=0;
    }
    if (testResult[i].result) {
      sprintf(message,"Test result of test No.%d (%s) : Success.",i+1, testResult[i].about);
    } else {
      count++;
      sprintf(message,"Test result of test No.%d (%s) : %s",i+1, testResult[i].about, testResult[i].comment);
    }
    Serial.println(message);
  }
  Serial.println("");
  char finalMessage[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE; i++) {
    finalMessage[i]=0;
  }
  sprintf(finalMessage, "Test result : all(%d) , success(%d) , fail(%d)", MAX_TEST, MAX_TEST-count, count);
  Serial.println(finalMessage);
  Serial.println("");
}


enum functionList {
  FUNCTION_FILL_SCREEN = 0,
  FUNCTION_SET_TEXT_COLOR,
  FUNCTION_SET_CURSOR,
  FUNCTION_SET_TEXT_WRAP,
  FUNCTION_SET_TEXT_SIZE,
  FUNCTION_SET_FONT,
  FUNCTION_DRAW_RGB_BITMAP
};

String functionName[7] = {
  "fillScreen()",
  "setTextColor()",
  "setCursor()",
  "setTextWrap()",
  "setTextSize()",
  "setFont()",
  "drawRGBBitmap()"
};

void checkReturnValue(graphicFunctionReturnValue val, uint8_t funcType) {
  char buff[MAX_BUFF_SIZE];
  memset(buff,0,MAX_BUFF_SIZE);
  if (val == GFX_FUNCTION_UNSUPPORTED) {
    Serial.println("");
    sprintf(buff,"executed function \"%s\" is unsupported.",functionName[funcType].c_str());
    Serial.println(buff);
    return;
  }
  if (val == GFX_FUNCTION_FAIL) {
    Serial.println("");
    sprintf(buff,"executed function \"%s\" is failed.",functionName[funcType].c_str());
    Serial.println(buff);
    return;
  }
}

void test1() {
  String about = "test1";
  printStartMessage(about, 0);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.print("check display size : ");
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE; i++) {
    message[i]=0;
  }
  sprintf(message, "Width = %d, Height = %d.", DISPLAY_WIDTH,DISPLAY_HEIGHT);
  Serial.println(message);
  Serial.println("");
  waitForStart();
  Serial.println("start : test1");

  for (int i=0; i<MAX_BUFF_SIZE; i++) {
    message[i]=0;
  }
  sprintf(message, "program output: Width = %d, Height = %d", display.width(), display.height());
  Serial.println(message);
  checkTestResult(about, 0);
  Serial.println("");
  Serial.println("");
}

#define COLOR16BIT_WHITE  0xffff
#define COLOR16BIT_GRAY   0x8410
#define COLOR16BIT_BLACK  0x0
#define COLOR16BIT_RED    0xf800
#define COLOR16BIT_GREEN  0x07e0
#define COLOR16BIT_BLUE   0x001f

void test2() {
  String about = "test2";
  printStartMessage(about, 1);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("paint with color: white, gray, red, green, blue, black");
  Serial.println("");
  waitForStart();
  Serial.println("start : test2");

  graphicFunctionReturnValue value;

  uint16_t colors[6] = {COLOR16BIT_WHITE, COLOR16BIT_GRAY, COLOR16BIT_RED, COLOR16BIT_GREEN, COLOR16BIT_BLUE, COLOR16BIT_BLACK};
  for (int i=0; i<6; i++) {
    value = display.fillScreen(colors[i]);
    checkReturnValue(value,FUNCTION_FILL_SCREEN);
    delay(3000);
  }
  checkTestResult(about, 1);
  Serial.println("");
  Serial.println("");
}

#define TEXT_SIZE_BASE 20


void test3() {
  String about = "test3";
  printStartMessage(about, 2);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println(" |0123456789");
  Serial.println("0|1   2   3 | black/white ,   red/gray  , blue/red");
  Serial.println("1|  4   5   | black/blue  ,   red/green");
  Serial.println("2|    6   7 | green/gray  , white/black");
  Serial.println("");
  waitForStart();
  Serial.println("start : test3");

  graphicFunctionReturnValue value;

  value = display.setTextSize(2,2);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  value = display.setTextColor(COLOR16BIT_BLACK,COLOR16BIT_WHITE);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('1');
  value = display.setTextColor(COLOR16BIT_RED,COLOR16BIT_GRAY);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(4*TEXT_SIZE_BASE,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('2');
  value = display.setTextColor(COLOR16BIT_BLUE,COLOR16BIT_RED);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(8*TEXT_SIZE_BASE,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('3');
  value = display.setTextColor(COLOR16BIT_BLACK,COLOR16BIT_BLUE);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(2*TEXT_SIZE_BASE,1*TEXT_SIZE_BASE);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('4');
  value = display.setTextColor(COLOR16BIT_RED,COLOR16BIT_GREEN);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(6*TEXT_SIZE_BASE,1*TEXT_SIZE_BASE);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('5');
  value = display.setTextColor(COLOR16BIT_GREEN,COLOR16BIT_GRAY);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(4*TEXT_SIZE_BASE,2*TEXT_SIZE_BASE);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('6');
  value = display.setTextColor(COLOR16BIT_WHITE,COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(8*TEXT_SIZE_BASE,2*TEXT_SIZE_BASE);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.write('7');


  checkTestResult(about, 2);
  Serial.println("");
  Serial.println("");


  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);

}

void test4() {
  String about = "test4";
  printStartMessage(about, 3);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("print text with NO text wrap: abc....z");
  Serial.println("print text with text wrap: abc....z");
  Serial.println("");
  waitForStart();
  Serial.println("start : test4");

  graphicFunctionReturnValue value;

  value = display.setTextSize(3,3);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  value = display.setTextColor(COLOR16BIT_WHITE,COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.print("abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz ");


  value = display.setCursor(0,20);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  display.print("abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz ");
  checkTestResult(about, 3);
  Serial.println("");
  Serial.println("");

  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);
  value = display.setTextSize(1,1);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
}

#define TEXT_SIZE_1 1
#define TEXT_SIZE_2 2
#define TEXT_SIZE_3 3
#define TEXT_SIZE_4 4
#define TEXT_SIZE_5 5
#define TEXT_SIZE_6 6
#define TEXT_SIZE_7 7
#define TEXT_SIZE_8 8
#define NUM_OF_FONTS5 8

void test5() {
  String about = "test5";
  printStartMessage(about, 4);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("print A with font size 1,2,3,4,5,6,7,8");
  Serial.println("");
  waitForStart();
  Serial.println("start : test5");

  graphicFunctionReturnValue value;

  uint8_t fontSizeArray[NUM_OF_FONTS5] = {TEXT_SIZE_1,TEXT_SIZE_2,TEXT_SIZE_3,TEXT_SIZE_4,TEXT_SIZE_5,TEXT_SIZE_6,TEXT_SIZE_7,TEXT_SIZE_8};

  value = display.setTextColor(COLOR16BIT_WHITE,COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);

  int16_t pos_of_x = 0;

  for (int i=0; i<NUM_OF_FONTS5; i++) {
    value = display.setTextSize(fontSizeArray[i]);
    checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
    display.print("A");
    pos_of_x = pos_of_x + fontSizeArray[i]*10;
    value = display.setCursor(pos_of_x,0);
    checkReturnValue(value,FUNCTION_SET_CURSOR);
    delay(1000);
  }
  checkTestResult(about, 4);
  Serial.println("");
  Serial.println("");

  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);
  value = display.setTextColor(COLOR16BIT_WHITE,COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
}

void test6() {
  String about = "test6";
  printStartMessage(about, 5);
  // テスト内容の説明
  Serial.println("=== 1st action ===");
  Serial.println("print A with 4 font size: 4x1, 4x2, 4x3, 4x4");
  Serial.println("=== 2nd action ===");
  Serial.println("print A with 4 font size: 4x5, 4x6, 4x7, 4x8");
  Serial.println("");
  waitForStart();
  Serial.println("start : test6");

  graphicFunctionReturnValue value;

  //value = display.setTextColor(COLOR16BIT_RED,COLOR16BIT_GRAY);
  //checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  // 1st action
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,1);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(30,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,2);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(60,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,3);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(90,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,4);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  // 2nd action
  value = display.setCursor(0,30);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,5);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(30,30);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,6);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(60,30);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,7);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");
  value = display.setCursor(90,30);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,8);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("A");

  checkTestResult(about, 5);
  Serial.println("");
  Serial.println("");

  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);
  value = display.setTextColor(COLOR16BIT_WHITE,COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_SET_TEXT_COLOR);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(14,14);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
}

void test7() {
  String about = "test7";
  printStartMessage(about, 6);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("print hello with normal font");
  Serial.println("print hello with custom font");
  waitForStart();
  Serial.println("start : test7");

  graphicFunctionReturnValue value;

  value = display.setCursor(0,20);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(4,4);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  display.print("Hello World!");

  value = display.setCursor(100,200);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
  value = display.setTextSize(1,1);
  checkReturnValue(value,FUNCTION_SET_TEXT_SIZE);
  value = display.setFont( &HennyPenny_Regular16pt7b );
  checkReturnValue(value,FUNCTION_SET_FONT);
  display.print("Hello World!");

  checkTestResult(about, 6);
  Serial.println("");
  Serial.println("");

  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
}



void test8() {
  String about = "test8";
  printStartMessage(about, 7);
  // テスト内容の説明
  Serial.println("=== action ===");
  Serial.println("print illastration of cat.");
  Serial.println("");
  waitForStart();
  Serial.println("start : test8");

  graphicFunctionReturnValue value;

  value = display.drawRGBBitmap(0, 0, cat_cat, 206, 206);
  checkReturnValue(value,FUNCTION_DRAW_RGB_BITMAP);

  checkTestResult(about, 7);
  Serial.println("");
  Serial.println("");
  value = display.fillScreen(COLOR16BIT_BLACK);
  checkReturnValue(value,FUNCTION_FILL_SCREEN);
  value = display.setCursor(0,0);
  checkReturnValue(value,FUNCTION_SET_CURSOR);
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Serial.println("");
  Serial.println("");

  tft.begin();

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  sumTestResult();
}

void loop() {

}
 