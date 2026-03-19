#include <iostream>
#include <string>
using namespace std;


class Triangle
{
public:
  int x, y, z;
  Triangle(int a, int b, int c)
  {
    x = a;
    y = b;
    z = c;
  }
  Triangle(int a){
    x = a;
    y = a;
    z = a;
  }
  Triangle(){

  }
  void print(){
    cout<<x<<" "<<y<<" "<<" "<<z<<endl;
}
  int per(){
    return x+y+z;
  }
};


int main(){


Triangle triangle1(12,13,14);
Triangle triangle2(10);
triangle1.print();
triangle2.print();
cout<<triangle1.per()<<endl;
cout<<triangle2.per()<<endl;

return 0;
}