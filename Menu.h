class Menu
{
  cLEDText ScrollingMsg;
  
  unsigned char txtMenu[10];
  
  int menuItem;

public:
  Menu()
  {
    menuItem = 0;
  };

  uint8_t hue;
  int16_t counter;

  void setup()
  {
    Serial.print("menu");
    sprintf((char *)txtMenu, "");
    ScrollingMsg.SetFont(MatriseFontData);
    ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight()+1, 1, 9);
   //ScrollingMsg.SetBackgroundMode(BACKGND_DIMMING);
   //ScrollingMsg.SetScrollDirection(SCROLL_UP);
  // ScrollingMsg.SetFrameRate(5);
  
   FastLED.setBrightness(255);
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_GRAD_AV, 0xee, 0x33, 0x33, 0xff,0x99,0x00 );
    FastLED.clear();   
   
    hue = 0;
    counter = 0;
    
    menuChanged(0);
  }

  boolean loop()
  {

  

   displayMenu();

if (receptor.decode(&resultado))  
  {  
     Serial.print("Codigo do botao: ");  
     Serial.println(resultado.value, HEX);  
    codigo = resultado.value; 
    delay(100);
    switch (codigo)  
    {  
      case (0x1FE40BF):   
       if(--menuItem < 0 ) menuItem = 2;
            menuChanged(menuItem);
            break;   
      case (0x1FEC03F): 
             menuItem = ++menuItem % 13;
            menuChanged(menuItem);
            break;
      case (0x1FE20DF): 
            currentApp = 3;
            return false;
      case (0x1FE807F): 
            currentApp = menuItem;
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
            break;

             
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
      
   return true;
   

  
  }
  

private:

  void menuChanged(int menuItem)
  {
    switch (menuItem)
    {
      case 0:  
      sprintf((char *)txtMenu, "   MENU   ");
      break;
      
    case 2:  
      sprintf((char *)txtMenu, " ALFABETO ");
      break;
      
    case 3:
      sprintf((char *)txtMenu, " NUMEROS! ");
      break;
     
    case 4:    
      sprintf((char *)txtMenu, "  FORMAS  ");
      break;
      
    case 5:  
      sprintf((char *)txtMenu, "  CORES!  ");
      break;
      
    case 6:
      sprintf((char *)txtMenu, " PADROES! ");
      break;
      
    case 7:
      currentApp = menuItem;
      sprintf((char *)txtMenu, " RAINBOW! ");
      break;
      
    case 8:
      currentApp = menuItem;
      sprintf((char *)txtMenu, "  SONORO  ");
      break;
      
    case 9:
      currentApp = menuItem;
      sprintf((char *)txtMenu, "   ONDAS  ");
      break;
      
    case 10:
      currentApp = menuItem;
      sprintf((char *)txtMenu, "  LIVRE!  ");
      break;
   
    case 11:
      currentApp = menuItem;
      sprintf((char *)txtMenu, "  TETRIS  ");
      break;
      
    case 12:
      currentApp = menuItem;
      sprintf((char *)txtMenu,  " BREAKOUT ");
      break;
      
    case 13:
      currentApp = menuItem;
      sprintf((char *)txtMenu, "   SNAKE  ");
      break;
 
    }
    currentApp = menuItem;
    ScrollingMsg.SetText((unsigned char *)txtMenu, sizeof(txtMenu) - 1);
  }

  void displayMenu()
  {
    ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight()+1, 1, 9);
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_GRAD_AV, 0xee, 0x33, 0x33, 0xff,0x99,0x00 );
    if (ScrollingMsg.UpdateText() == -1)
      ScrollingMsg.SetText((unsigned char *)txtMenu, sizeof(txtMenu) - 1);
     
    else
      FastLED.show();
  }


};
