#include <ssd1306xled.h>
void setup() {
  // put your setup code here, to run once:
  SSD1306.ssd1306_init();
  DDRB = DDRB | 0b00010000;
  DDRB = DDRB & 0b11010101;
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(5, 3);
  SSD1306.ssd1306_string_font6x8("Frequency: ");
}

void loop() {
  SSD1306.ssd1306_setpos(60, 3);
  SSD1306.ssd1306_numdecp(80);
  // put your main code here, to run repeatedly:
  Sound(80, 100);
  delay(500);

  
  for (uint8_t t = 155; t < 255; t++) {
            SSD1306.ssd1306_setpos(60, 3);
            SSD1306.ssd1306_numdecp(2 + t);
            Sound(2 + t, 2);
            SSD1306.ssd1306_setpos(60, 3);
            SSD1306.ssd1306_numdecp(25 + t);
            Sound(25 + t, 1);
          }
  delay(500);

  for (uint8_t t = 0; t < 5; t++) {
            SSD1306.ssd1306_setpos(60, 3);
            SSD1306.ssd1306_numdecp(100);
            Sound (100, 100);
            SSD1306.ssd1306_setpos(60, 3);
            SSD1306.ssd1306_numdecp(1);
            Sound (1, 100);
          }
  delay(500);

  
            
}

void Sound(uint8_t freq, uint8_t dur) {
  for (uint8_t t = 0; t < dur; t++) {
    if (freq != 0) PORTB = PORTB | 0b00010000;
    for (uint8_t t = 0; t < (255 - freq); t++) {
      _delay_us(1);
    }
    PORTB = PORTB & 0b11101111;
    for (uint8_t t = 0; t < (255 - freq); t++) {
      _delay_us(1);
    }
  }
}
