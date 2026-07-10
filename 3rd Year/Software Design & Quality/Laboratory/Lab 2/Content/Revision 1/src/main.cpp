#include <iostream>
#include <math.h> // for M_PI 

using namespace std;
 
// Base class
class Shape 
{
public:
   // pure virtual function providing interface framework.
   virtual int getArea() = 0;
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
   void setRadius(int r) {
      radius = r;
   }
protected:
   int width;
   int height;
   int radius;
};
 
class Triangle: public Shape
{
public:
   int getArea()
   { 
      return (width * height)/2; 
   }
};

class Circle: public Shape
{
public:
   int getArea()
   { 
      return (M_PI * radius * radius);
   }
};
 
int main(void)
{
   Triangle  Tri;
   Circle Circ;

   Circ.setRadius(10);

   Tri.setWidth(5);
   Tri.setHeight(7);
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl;
   cout << "Circle Area: " << Circ.getArea() << endl; 

   return 0;
}