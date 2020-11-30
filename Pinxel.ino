
#include <WiFi.h>         // Built-in for ESP32


#include <time.h>

// Change to your WiFi credentials and select your time zone

#include <FastLED.h>
#include <LEDMatrix.h>
#include <LEDSprites.h>
#include <LEDText.h>
#include <FontMatrise.h>
#include <Font12x16.h>
#include <FontRobotron.h>
#include "BluetoothSerial.h"
#include <IRremote.h>




#define LED_PIN 5
#define COLOR_ORDER GRB
#define CHIPSET WS2812B
#define MATRIX_WIDTH 61
#define MATRIX_HEIGHT 25
#define MATRIX_TYPE HORIZONTAL_ZIGZAG_MATRIX
//#define NUM_LEDS MATRIX_WIDTH*MATRIX_HEIGHT

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))




#define APP_MENU -1

#define APP_SOBRE 0
#define APP_SCREENSAVER 1

#define APP_ALFABETO 2
#define APP_NUMEROS 3
#define APP_FORMAS 4
#define APP_CORES 5

#define APP_PADROES 6

#define APP_EFEITO1 7
#define APP_EFEITO2 8
#define APP_EFEITO3 9

#define APP_LIVRE 10

#define APP_TETRIS 11
#define APP_BREAKOUT 12
#define APP_SNAKE 13


IRrecv receptor(23);
 
decode_results resultado;
int codigo;


int currentApp = APP_MENU;

cLEDMatrix<MATRIX_WIDTH, -MATRIX_HEIGHT, MATRIX_TYPE> leds;
BluetoothSerial SerialBT;

// Bluetooth input
enum btnInput
{
  NONE,
  UP,
  DOWN,
  LEFT,
  RIGHT
};

btnInput currentInput = NONE;


#include "Menu.h"
#include "Sobre.h"
#include "Screensaver.h"

#include "Alfabeto.h"
#include "Numeros.h"
#include "Formas.h"
#include "Cores.h"

#include "Padroes.h"

#include "Efeito1.h"
#include "Efeito2.h"
#include "Efeito3.h"

#include "Livre.h"

#include "Tetris.h"
#include "Breakout.h"
#include "Snake.h"



void setup()
{
  Serial.begin(115200);

  receptor.enableIRIn();
  SerialBT.begin("Pinxel");
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 40000);
  FastLED.setBrightness(200);
  FastLED.clear(true);
  FastLED.show();
  currentApp = 0;
}

void loop()
{
      
  //UpdateLocalTime(Time_format);
  //Serial.println(Date_str);
  ////Serial.println(Time_str);
  //Serial.println();
  //delay(1000);

  
  switch (currentApp)
  {
  case APP_MENU:
    runMenu();
    break;
  case APP_ALFABETO:
    runAlfabeto();
    break;
  case APP_NUMEROS:
    runNumeros();
    break;
  case APP_FORMAS:
    runFormas();
    break;
  case APP_CORES:
    runPadroes();
    break;
  case APP_LIVRE:
    runLivre();
    break;
  case APP_EFEITO1:
    runEfeito1();
    break;
  case APP_EFEITO2:
    runEfeito2();
    break;
  case APP_EFEITO3:
  runEfeito3();
   break;
  case APP_SOBRE:
    runSobre();
    break;
  case APP_TETRIS:
    runTetris();
    break;
  case APP_BREAKOUT:
    runBreakout();
    break;
  case APP_SNAKE:
    runSnake();
    break;
  case APP_SCREENSAVER:
    runScreensaver();
    break;
  case APP_PADROES:
    runPadroes();
    break;
  }
}

void runMenu()
{
  bool isRunning = true;
  Menu menu = Menu();
  menu.setup();
  while (isRunning)
  {
    isRunning = menu.loop();
  }
}

void runAlfabeto()
{
  bool isRunning = true;
  Alfabeto alfabeto = Alfabeto();
  alfabeto.setup();
  while (isRunning)
  {
    isRunning = alfabeto.loop();
  }
}

void runNumeros()
{
  bool isRunning = true;
  Numeros numeros = Numeros();
  numeros.setup();
  while (isRunning)
  {
    isRunning = numeros.loop();
  }
}

void runFormas()
{
  bool isRunning = true;
  Formas formas = Formas();
  formas.setup();
  while (isRunning)
  {
    isRunning = formas.loop();
  }
}

void runPadroes()
{
  bool isRunning = true;
  Padroes padroes = Padroes();
  padroes.setup();
  while (isRunning)
  {
    isRunning = padroes.loop();
  }
}

void runLivre()
{
  bool isRunning = true;
  Livre livre = Livre();
  livre.setup();
  while (isRunning)
  {
    isRunning = livre.loop();
  }
}

void runEfeito1()
{
  bool isRunning = true;
  Efeito1 efeito1 = Efeito1();
  efeito1.setup();
  while (isRunning)
  {
    isRunning = efeito1.loop();
  }
}

void runEfeito2()
{
   bool isRunning = true;
  Efeito2 efeito2 = Efeito2();
  efeito2.setup();
  while (isRunning)
  {
    isRunning = efeito2.loop();
  }
}

void runEfeito3()
{
  bool isRunning = true;
  Efeito3 efeito3 = Efeito3();
  efeito3.setup();
  while (isRunning)
  {
    isRunning = efeito3.loop();
  }
}

void runSobre()
{
  bool isRunning = true;
  Sobre sobre = Sobre();
  sobre.setup();
  while (isRunning)
  {
    isRunning = sobre.loop();
  }
}


void runTetris()
{
  bool isRunning = true;
  Tetris tetris = Tetris();
  tetris.setup();
  while (isRunning) 
  {
    isRunning = tetris.loop();
  }
}


void runBreakout()
{
  bool isRunning = true;
  Breakout breakout = Breakout();
  breakout.setup();
  while (isRunning) 
  {
    isRunning = breakout.loop();
  }
}

void runSnake()
{
  bool isRunning = true;
  Snake snake = Snake();
  snake.setup();
  while (isRunning) 
  {
    isRunning = snake.loop();
 }
}


void runScreensaver()
{
  bool isRunning = true;
  Screensaver screensaver = Screensaver();
  screensaver.setup();
  while (isRunning) 
  {
    isRunning = screensaver.loop();
 }
}



void respostaBT(){


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
          
            break;

             
            //Sobre
         // case 'm':
          //  currentApp = 0;
         //   return false;
         //   break;

             
            //Screensaver
          case '!':
            currentApp = 1;
           
            break;
            
          //alfabeto
         case 'l':
            currentApp = 2;
            
            break;

            //Numeros
          case 'n':
            currentApp = 3;
            
            break;

              //Formas
          case 'f':
            currentApp = 4;
            
            break;
            
            //Cores
          case 'c':
            currentApp = 5;
            
            break;
            
             //Padroes
          case 'p':
            currentApp = 6;
           
            break;
            
            //Efeitos1
         case '<':
            currentApp = 7;
           
            break;

                 //Efeitos2
         case '>':
             currentApp = 8;
          
            break;

                 //Efeitos3
         case '[':
             currentApp = 9;
            
            break;

            //Livre
         case '?':
             currentApp = 10;
           
            break;  
            
            //Tetris
          case 't':
            currentApp = 11;
            
            break;

             //breakout
          case 'x':
            currentApp = 12;
          
            break;
            
            //Snake
          case 'q':
            currentApp = 13;
          
            break;
      }
    }
   
}










 
