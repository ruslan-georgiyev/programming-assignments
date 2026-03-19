#include <iostream>
#include <fstream>
#include <stdio.h>

class Point
{
private:
  int x, y;
public:
  void setX(int value){
    x = value;
  }
  void setY(int value){
    y = value;
  }
  int getX(void){
    return x;
  }
  int getY(void){
    return y;
  }

  Point(int x, int y){
    this->x=x;
  }
};

int main(void)
{
  Point a(10,20);
  a.setX(5); a.setY(8);
  printf("%d %d\n",a.getX(),a.getY());
  return 0;
}
