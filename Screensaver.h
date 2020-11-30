class Screensaver{
  
  cLEDText Msg;
  
unsigned char hora[9];

const char* ssid     = "iPhone de George";
const char* password = "123456789";
  
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = -3600*3;
  
  
  public:
  Screensaver(){};

void setup()
  {
    delay(100);
    Serial.println("Relogio");
    
    
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  
  // Init and get the time
  configTime(gmtOffset_sec, daylightOffset_sec, "pool.ntp.br", "pool.ntp.br", "pool.ntp.br");
  printLocalTime();

  //disconnect WiFi as it's no longer needed
  
    sprintf((char *)hora, "      ");
    Msg.SetFont(MatriseFontData);
    Msg.Init(&leds, leds.Width(), Msg.FontHeight() + 1, 6, 9);
    Msg.SetTextColrOptions(COLR_RGB | COLR_GRAD_AH, 0x00,  0x66,  0xbb);
    FastLED.clear();   
  }


boolean loop() {


  if (receptor.decode(&resultado))  
  {  
    Serial.print("Codigo do botao: ");  
    Serial.println(resultado.value, HEX);  
    codigo = resultado.value; 
    delay(100);
    switch (codigo){     
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

    
  
 delay(100);
 
 printLocalTime();
 displayMenu();

 return true;

}

private:

void displayMenu()
  {    
    Msg.Init(&leds, leds.Width(), Msg.FontHeight() + 1,6, 9);
    Msg.SetTextColrOptions(COLR_RGB | COLR_GRAD_AH, 0x00, 0x66,  0xbb);
    if (Msg.UpdateText() == -1)
      Msg.SetText((unsigned char *)hora, sizeof(hora) - 1);
    else
      FastLED.show();
  }

void printLocalTime(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  Serial.println(timeHour);

  char timeSec[3];
  strftime(timeSec,3, "%S", &timeinfo);
  Serial.println(timeSec);
  
  char timeMin[3];
  strftime(timeMin,3, "%M", &timeinfo);
  Serial.println(timeMin);

  
  char timeWeekDay[10];
  strftime(timeWeekDay,10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();

  sprintf((char *)hora, "%S:%S:%S", timeHour, timeMin, timeSec );
  
}

 
};
