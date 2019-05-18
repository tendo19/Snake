
/*snake.ino
 * by: Taiyo Endo
 */

#include <MeggyJrSimple.h>

struct Point 
{
  int x;
  int y;
};
Point s1 = {4,4};
Point s2 = {3,4};
Point s3 = {2,4};
Point s4 = {1,4};
Point s5 = {0,4};
Point snakeArray[64] = {s1};


int x,y;
int color;
int xapple;
int yapple;
boolean gotApple=false;
int dir = 0;
int applesEaten = 0;
int setAuxLEDs = applesEaten - 1;
int marker = 1;

void setup() 
{
  MeggyJrSimpleSetup();
  x = 4;
  y = 4;
  color = 1;
  xapple = random(8);
  yapple = random(8);
}


void loop() 
{
 drawsnake();
 spawn();
 moveapple();
 direction();
 movesnake();
 borders();
 eating();

 DisplaySlate();
 ClearSlate(); 
 delay(100);
}


void updatesnake()
{
  for (int i = marker - 1; i > 0; i--)
  {
    snakeArray[i].x = snakeArray[i-1].x;
    snakeArray[i].y = snakeArray[i-1].y;    
  }
}


void movesnake()
{
  CheckButtonsDown();
  if (Button_Left)
  {
    dir = 90;
  }
  if (Button_Right)
  {
    dir = 270;
  }
  if (Button_Up)
  {
    dir = 0;
  }
  if (Button_Down)
  {
    dir = 180;
  }
}



void drawsnake()
{
 if (gotApple == true)
 {
  marker++;
 }
 
 for (int i = 0; i < marker; i++)
 {
   DrawPx(snakeArray[i].x,snakeArray[i].y,Blue); 
 }
}




void followdot()
{
  Point s1 = {3,4};
  Point s2 = {4,4};
}



void eating()
{
  if (gotApple == true)
  {
    applesEaten++;
  }
  setAuxLEDs = applesEaten - 1;
}



void direction()
{
  if (dir == 0)
  {
    y++;
  }
  if (dir == 90)
  {
    x--;
  }
  if (dir == 180)
  {
    y--;
  }
  if (dir == 270)
  {
    x++;
  }
}





void spawn()
{
 DrawPx(xapple,yapple,Red);
}




void moveapple()
{
  if (x == xapple && y == yapple)
  {
    gotApple = true;
  }
  if (gotApple == true)
  {
   Tone_Start(ToneDs5,100);
   xapple = random(8);
   yapple = random(8);
   gotApple = false; 
  }
}




void borders()
{
  if (x < 0)
  {
    x = 7;
  }
  if (x > 7)
  {
    x = 0;
  }
   if (y < 0)
  {
    y = 7;
  }
  if (y > 7)
  {
    y = 0;
  }  
}
