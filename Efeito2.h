class Efeito2 {

public:
Efeito2(){};

#define NUM_LEDS MATRIX_WIDTH*MATRIX_HEIGHT-1

struct CRGB ledsB[NUM_LEDS];    



#define BRIGHTNESS  200
#define DENSITY     200

void setup() {
  FastLED.setBrightness(200);
  FastLED.addLeds<NEOPIXEL, LED_PIN>(ledsB, NUM_LEDS);
  memset(ledsB, 0,  NUM_LEDS * sizeof(struct CRGB));
}


boolean loop(){

  //softtwinkles();



  if (SerialBT.available())
    {
      char keyPress = (char)SerialBT.read();
      FastLED.clear();
      Serial.println(keyPress);  
      switch (keyPress)
      {    
            //Menu
          case 'm':
            currentApp = -1;
            return false;
  

             
            //Sobre
         // case 'm':
          //  currentApp = 0;
         //   return false;
         //   break;

             
            //Screensaver
          case '!':
            currentApp = 1;
            return false;
            break;
            
          //alfabeto
         case 'l':
            currentApp = 2;
            return false;
            break;

            //Numeros
          case 'n':
            currentApp = 3;
            return false;
            break;

              //Formas
          case 'f':
            currentApp = 4;
            return false;
            break;
            
            //Cores
          case 'c':
            currentApp = 5;
            return false;
            break;
            
             //Padroes
          case 'p':
            currentApp = 6;
            return false;
            break;
            
            //Efeitos1
         case '<':
            currentApp = 7;
            return false;
            break;

                 //Efeitos2
         case '>':
             currentApp = 8;
            return false;
            break;

                 //Efeitos3
         case '[':
             currentApp = 9;
            return false;
            break;

            //Livre
         case '?':
             currentApp = 10;
            return false;
            break;  
            
            //Tetris
          case 't':
            currentApp = 11;
            return false;
            break;

             //breakout
          case 'x':
            currentApp = 12;
            return false;
            break;
            
            //Snake
          case 'q':
            currentApp = 13;
            return false;
            break;
      }
    }
      
  FastLED.show();     
  FastLED.delay(20);
  return true;

}


//  This function loops over each pixel, calculates the 
//  adjusted 'clock' that this pixel should use, and calls 
//  "CalculateOneTwinkle" on each pixel.  It then displays
//  either the twinkle color of the background color, 
//  whichever is brighter.
private:
void softtwinkles() {

  const CRGB lightcolor(8,7,1);
  
  for( int i = 0; i < NUM_LEDS; i++) {
    if( !ledsB[i]) continue; // skip black pixels
    if( ledsB[i].r & 1) { // is red odd?
      ledsB[i] -= lightcolor; // darken if red is odd
    } else {
      ledsB[i] += lightcolor; // brighten if red is even
    }
  }
  
  // Randomly choose a pixel, and if it's black, 'bump' it up a little.
  // Since it will now have an EVEN red component, it will start getting
  // brighter over time.
  if( random8() < DENSITY) {
    int j = random16(NUM_LEDS);
    if( !ledsB[j] ) ledsB[j] = lightcolor;
  }
}



};
