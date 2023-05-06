/*********
  Complete project details at https://randomnerdtutorials.com
  
  This is an example for our Monochrome OLEDs based on SSD1306 drivers. Pick one up today in the adafruit shop! ------> http://www.adafruit.com/category/63_98
  This example is for a 128x32 pixel display using I2C to communicate 3 pins are required to interface (two I2C and one reset).
  Adafruit invests time and resources providing this open source code, please support Adafruit and open-source hardware by purchasing products from Adafruit!
  Written by Limor Fried/Ladyada for Adafruit Industries, with contributions from the open source community. BSD license, check license.txt for more information All text above, and the splash screen below must be included in any redistribution. 
*********/

//#include <SPI.h>
//#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
//
//#define SCREEN_WIDTH 128 // OLED display width, in pixels
//#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//
//// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//
//void OLEDdisplay(char *percent=nullptr, char *volts=nullptr, char *timeTaken=nullptr) {
//  if (percent && timeTaken) {
//    // DISPLAY FOR PERCENT
//    display.setCursor(30, 5);
//    display.setTextColor(WHITE, BLACK); //BG color can be set by passing another parameter
//    display.setTextSize(3);
//    display.print(percent);
//    display.print("%");
//  
//    // DISPLAY FOR TIMETAKEN
//    display.setCursor(40, 45);
//    display.setTextColor(WHITE, BLACK);
//    display.setTextSize(1);
//    display.print(timeTaken);
//    // display.print(" TT");
//  }
//  
//  // DISPLAY FOR VOLTS
//  display.setCursor(55, 35);
//  display.setTextColor(WHITE, BLACK);
//  display.setTextSize(1);
//  display.print(volts);
//  display.print("V");
//
//
//  display.display();
//}
//
//
//void setup() {
//  Serial.begin(115200);
//
//  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
//  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
//    Serial.println(F("SSD1306 allocation failed"));
//    for(;;); // Don't proceed, loop forever
//  }
//
//  // Show initial display buffer contents on the screen --
//  // the library initializes this with an Adafruit splash screen.
//  display.display();
//  delay(2000); // Pause for 2 seconds
//
//  // Clear the buffer
//  display.clearDisplay();
//
//}
//
//void loop() {
//  OLEDdisplay("100", "42", "02:54:00");
//}
