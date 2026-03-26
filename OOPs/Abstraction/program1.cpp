#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
  string color;

public:
  Shape(string color)
  {
    this->color = color;
  }

  virtual double area() = 0;

  string getColor()
  {
    return color;
  }

  virtual ~Shape() {} // We make the base class destructor virtual to ensure that the correct (derived) destructor is called when deleting an object through a base class pointer.
};

class Rectangle : public Shape
{
  double length, width;

public:
  Rectangle(string color, double length, double width) : Shape(color)
  {
    this->length = length;
    this->width = width;
  }
  double area() override
  {
    return length * width;
  }
};

int main()
{
  Shape *s = new Rectangle("Yellow", 2, 4);

  cout << "Rectangle color is " << s->getColor() << " and area is : " << s->area() << endl;
  return 0;
}