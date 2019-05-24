
/*snake.ino
 * by: Taiyo Endo
 */

#include <MeggyJrSimple.h>

struct Point 
{
  int x;
  int y;
};
Point s1 = {1,4};
Point s2 = {2,4};
Point s3 = {3,4};
Point s4 = {4,4};
Point snakeArray[64] = {s1,s2,s3,s4};


int x,y;
int color;
int xapple;
int yapple;
boolean gotApple=false;
int dir = 0;
int applesEaten = 0;
int setAuxLEDs = applesEaten - 1;
int marker = 5;
int t = 500;
int Color;

void setup() 
{
  MeggyJrSimpleSetup();
  x = 4;
  y = 4;
  color = 1;
  xapple = random(8);
  yapple = random(8);
  applesEaten = 0;
}


void loop() 
{
 drawsnake();
 spawnapple();
 DisplaySlate();
 delay(100);
 ClearSlate(); 
 moveapple();
 direction();
 movesnake();
 borders();
 eating();
 updatesnake();
}

void delaytime()  //tried to make a code that makes the snake faster when applesEaten increases
{
  if (applesEaten < 2)
  {
    t = 500;
  }
  if (applesEaten >= 2)
  {
    if (applesEaten < 4)
    {
      t = 200;     
    }
  }
  if (applesEaten >= 4)
  {
    t = 100;
  }
  delay(t);
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
 for (int i = 1; i < marker; i++)
 {
   DrawPx(snakeArray[i].x,snakeArray[i].y,Blue); 
 }
 for (int i = 0; i < 1; i++)
 {
  DrawPx(snakeArray[i].x,snakeArray[i].y,Green);
 }
}




void eating()
{
  if (gotApple == true)
  {
    applesEaten++;
  }
  SetAuxLEDs(applesEaten - 1);
}



void direction()
{
  if (dir == 0)
  {
    snakeArray[0].y++;
  }
  if (dir == 90)
  {
    snakeArray[0].x--;
  }
  if (dir == 180)
  {
    snakeArray[0].y--;
  }
  if (dir == 270)
  {
    snakeArray[0].x++;
  }
}





void spawnapple()
{
 DrawPx(xapple,yapple,Red);
}




void moveapple()
{
  if (snakeArray[0].x == xapple && snakeArray[0].y == yapple)
  {
    gotApple = true;
  }
  if (gotApple == true)
  {
   Tone_Start(ToneDs5,100);
   xapple = random(8);
   yapple = random(8);
   gotApple = false;
   marker++;
  }
}




void borders()
{
  if (snakeArray[0].x < 0)
  {
    snakeArray[0].x = 7;
  }
  if (snakeArray[0].x > 7)
  {
    snakeArray[0].x = 0;
  }
   if (snakeArray[0].y < 0)
  {
    snakeArray[0].y = 7;
  }
  if (snakeArray[0].y > 7)
  {
    snakeArray[0].y = 0;
  }  
}
