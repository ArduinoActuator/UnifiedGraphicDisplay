#include "UnifiedGraphicDisplay.h"

#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
UnifiedGraphicDisplay::UnifiedGraphicDisplay(GigaDisplay_GFX *tft, UnifiedDisplayType type):
  _tft(tft),
  _type(type)
{}
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */

#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
UnifiedGraphicDisplay::UnifiedGraphicDisplay(TFT_eSPI *tft, UnifiedDisplayType type):
  _tft(tft),
  _type(type)
{}
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */

#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
UnifiedGraphicDisplay::UnifiedGraphicDisplay(Adafruit_ILI9341 *tft, UnifiedDisplayType type):
  _tft(tft),
  _type(type)
{}
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */

int UnifiedGraphicDisplay::fillScreen(uint16_t color) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->fillScreen(color);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->fillScreen(color);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->fillScreen(color);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::setTextColor(uint16_t fg, uint16_t bg) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setTextColor(fg, bg);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setTextColor(fg, bg);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setTextColor(fg, bg);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::setCursor(int16_t x, int16_t y){
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setCursor(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setCursor(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setCursor(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::setTextWrap(bool w) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setTextWrap(w);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setTextWrap(w);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setTextWrap(w);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::setTextSize(uint8_t s) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setTextSize(s);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setTextSize(s);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setTextSize(s);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}
int UnifiedGraphicDisplay::setTextSize(uint8_t x, uint8_t y) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setTextSize(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setTextSize(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setTextSize(x, y);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::setFont(const GFXfont *f) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->setFont(f);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->setFont(f);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->setFont(f);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], int16_t w, int16_t h){
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, int16_t w, int16_t h) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[], const uint8_t mask[], int16_t w, int16_t h) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

int UnifiedGraphicDisplay::drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h){
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      _tft->drawRGBBitmap(x,y,bitmap,mask,w,h);
      return 0;
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return -1;
}

uint16_t UnifiedGraphicDisplay::width(void) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      return _tft->width();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      return _tft->width();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      return _tft->width();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return 0;
}

uint16_t UnifiedGraphicDisplay::height(void) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      return _tft->height();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      return _tft->height();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      return _tft->height();
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return 0;
}

size_t UnifiedGraphicDisplay::write(uint8_t c) {
  switch(_type) {
#ifdef GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX
    case DISPLAY_TYPE_GIGA_DISPLAY_GFX: {
      return _tft->write(c);
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_GIGA_DISPLAY_GFX */
#ifdef GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI
    case DISPLAY_TYPE_BODMER_TFT_ESPI: {
      return _tft->write(c);
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_BODMER_TFT_ESPI */
#ifdef GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX
    case DISPLAY_TYPE_ADAFRUIT_GFX: {
      return _tft->write(c);
    }
#endif /* GRAPHIC_DISPLAY_HAL_USE_ADAFRUIT_GFX */
  }
  return 0;
}