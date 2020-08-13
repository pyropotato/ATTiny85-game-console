#include <ssd1306xled.h>
int x = 10;
void setup() {
  // put your setup code here, to run once:
  SSD1306.ssd1306_init();
  DDRB = DDRB | 0b00010000;
  DDRB = DDRB & 0b11010101;
  SSD1306.ssd1306_fillscreen(0x00);
  SSD1306.ssd1306_setpos(0, 1);
  SSD1306.ssd1306_string_font6x8("ADC Value");
  SSD1306.ssd1306_setpos(20, 3);
  SSD1306.ssd1306_numdecp(x);
  ADMUX |= (0 << REFS0);  //using Vin as voltage reference
  ADMUX |= (1 << MUX0);   //
  ADMUX |= (1 << MUX1);   //sets ADC3 as analog input channel
  ADMUX |= (1 << ADLAR);   //left adjusts for 8-bit resolution
  ADCSRA |= (1 << ADEN);   //enables the ADC
  ADCSRA |= (1 << ADPS2);   //set division factor-128 = 125kHz   
  ADCSRA |= (1 << ADPS1);   
  ADCSRA |= (1 << ADPS0);   
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //x = analogRead(A3);
  ADCSRA |= (1 << ADSC); 
  x = ADCH;
  SSD1306.ssd1306_setpos(20, 3);
  SSD1306.ssd1306_numdecp(x);
}
