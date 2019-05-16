
/*snake.ino
 * by: Taiyo Endo
 */

#include <MeggyJrSimple.h>

int x,y;
int color;
int xapple;
int yapple;
boolean gotApple=false;
int dir;

void setup() 
{
  MeggyJrSimpleSetup();
  x=0;
  y=3;
  color=1;
  xapple=random(8);
  yapple=random(8);
  dir=0;
}




void loop() 
{
 drawsnake();
 spawn();
 moveapple();
 movesnake();
 direction();
 borders();
 
 DisplaySlate();
 ClearSlate(); 
}




void direction()
{
  if (dir==0)
  {
    y++;
    delay(500);
  }
  if (dir==90)
  {
    x--;
    delay(500);
  }
  if (dir==180)
  {
    y--;
    delay(500);
  }
  if (dir==270)
  {
    x++;
    delay(500);
  }
}




void drawsnake()
{
 DrawPx(x,y,Blue); 
}




void spawn()
{
 DrawPx(xapple,yapple,Red);
}




void moveapple()
{
  if (x==xapple && y==yapple)
  {
    gotApple=true;
  }
  if (gotApple==true)
  {
   Tone_Start(ToneDs5,100);
   xapple=random(8);
   yapple=random(8);
   gotApple=false; 
  }
}




void movesnake()
{
  CheckButtonsPress();
  if (Button_Left)
  {
    dir=90;
  }
  if (Button_Right)
  {
    dir=270;
  }
  if (Button_Up)
  {
    dir=0;
  }
  if (Button_Down)
  {
    dir=180;
  }
}




void borders()
{
  if (x<0)
  {
    x=7;
  }
  if (x>7)
  {
    x=0;
  }
   if (y<0)
  {
    y=7;
  }
  if (y>7)
  {
    y=0;
  }  
}
