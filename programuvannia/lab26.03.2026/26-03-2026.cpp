#include <iostream>
using namespace std;

class Square
{
public:
  double length; // Довжина квадрата
  double width;  // Ширина квадрата
  
  Square(double l, double w) // Конструктор
  {
    length = l;
    width = w;
    cout<<"constructor"<<endl;
  }
  
  double Area()
  {
    return length * width;
  }
  ~Square(){
    cout<<"desctructor"<<endl;
  }
};

int main(void)
{
  Square a(2.0, 3.0), b(6.5, 7.2), *c;

  c = &a;
  cout<< c->Area()<<endl;
  //cout<<(*c).Area(); // Альтернативний запис
  c = &b;
  cout<< c->Area()<<endl;
  Square d(4.5,3.7);
  return 0;
}
