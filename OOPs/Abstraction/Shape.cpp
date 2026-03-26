#include <bits/stdc++.h>
using namespace std;

// ---------------- Base Class ----------------
class Shape
{
protected:
  string color;

public:
  Shape(string c) : color(c) {}

  virtual void draw() = 0;
  virtual double area() = 0;

  virtual ~Shape() {}
};

// ---------------- Circle ----------------
class Circle : public Shape
{
  double r;

public:
  Circle(double r, string c) : Shape(c), r(r) {}

  void draw() override
  {
    cout << "Drawing Circle of color " << color << endl;
  }

  double area() override
  {
    return 3.14 * r * r;
  }
};

// ---------------- Rectangle ----------------
class Rectangle : public Shape
{
  double l, b;

public:
  Rectangle(double l, double b, string c) : Shape(c), l(l), b(b) {}

  void draw() override
  {
    cout << "Drawing Rectangle of color " << color << endl;
  }

  double area() override
  {
    return l * b;
  }
};

// ---------------- Triangle ----------------
class Triangle : public Shape
{
  double b, h;

public:
  Triangle(double b, double h, string c) : Shape(c), b(b), h(h) {}

  void draw() override
  {
    cout << "Drawing Triangle of color " << color << endl;
  }

  double area() override
  {
    return 0.5 * b * h;
  }
};

// ---------------- Main ----------------
int main()
{
  vector<Shape *> shapes;

  shapes.push_back(new Circle(5, "Red"));
  shapes.push_back(new Rectangle(4, 6, "Blue"));
  shapes.push_back(new Triangle(3, 4, "Green"));

  for (auto s : shapes)
  {
    s->draw();
    cout << "Area: " << s->area() << endl;
  }

  // cleanup
  for (auto s : shapes)
  {
    delete s;
  }
}