class Efeito1 {

public:
Efeito1(){};


uint8_t hue;
int16_t counter;


void setup() {   
    FastLED.clear();
      hue = 0;
  counter = 0;
  }



  

  boolean loop() {

    EfeitoRainbow();

    if (receptor.decode(&resultado))  
  {  
    Serial.print("Codigo do botao: ");  
    Serial.println(resultado.value, HEX);  
    codigo = resultado.value; 
    switch (codigo)  
    {  
      case (0x1FE58A7):   
          currentApp = -1;
          return false;
      }
       receptor.resume();  
    }

    
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
   return true; 

  }


  void EfeitoRainbow() {

        // Rainbow background
    int16_t sx, sy, x, y;
  uint8_t h;

  FastLED.clear();
  
  h = hue;
  if (counter < 1125)
  {
    // ** Fill LED's with diagonal stripes
    for (x=0; x<(leds.Width()+leds.Height()); ++x)
    {
      leds.DrawLine(x - leds.Height(), leds.Height() - 1, x, 0, CHSV(h, 255, 255));
      h+=16;
    }
  }
  else
  {
    // ** Fill LED's with horizontal stripes
    for (y=0; y<leds.Height(); ++y)
    {
      leds.DrawLine(0, y, leds.Width() - 1, y, CHSV(h, 255, 255));
      h+=16;
    }
  }
  hue+=4;

  if (counter < 125)
    ;
  else if (counter < 375)
    leds.HorizontalMirror();
  else if (counter < 625)
    leds.VerticalMirror();
  else if (counter < 875)
    leds.QuadrantMirror();
  else if (counter < 1125)
    leds.QuadrantRotateMirror();
  else if (counter < 1250)
    ;
  else if (counter < 1500)
    leds.TriangleTopMirror();
  else if (counter < 1750)
    leds.TriangleBottomMirror();
  else if (counter < 2000)
    leds.QuadrantTopTriangleMirror();
  else if (counter < 2250)
    leds.QuadrantBottomTriangleMirror();

  counter++;
  if (counter >= 2250)
    counter = 0;
  FastLED.show();
  }

  void DrawOneFrame( byte startHue8, int8_t yHueDelta8, int8_t xHueDelta8)
  {
    byte lineStartHue = startHue8;
    for( byte y = 0; y < leds.Height(); y++) {
      lineStartHue += yHueDelta8;
      byte pixelHue = lineStartHue;      
      for( byte x = 0; x < leds.Width(); x++) {
        pixelHue += xHueDelta8;
        leds(x, y)  = CHSV( pixelHue, 255, 255);
      }
    }
  }

 
};
