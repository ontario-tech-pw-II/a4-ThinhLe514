#include <iostream>
#include <cmath>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print() const;
    double area() const;

    double operator+(const Circle &) const;

    Circle & operator++(); // prefix
    Circle operator++(int); // postfix

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int X, int Y, double R)
{
  // Initialize the object here
  x = X;
  y = Y;
  r = R;
}

double Circle::area() const {
  // Return the area of a circle
  return 4*M_PI*pow(r, 2);
}

double Circle::operator+(const Circle & c) const
{
   // + Return the area of two circles  
   return this->area() + c.area();
}

Circle & Circle::operator++()
{
  // Increment the radius by 1
  r++;
  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  
  //increment the radius by 1
  r++;
  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  // print a circle in the out stream (the format is the same as print())
  out << "Circle =(" << c.x << "," << c.y << "," << c.r << ")" << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
 
  // Read a circle information form the in stream
  int tempX, tempY;
  double tempR;

  cout << "\tX: ";
  in >> tempX;

  cout << "\tY: ";
  in >> tempY;

  cout << "\tR: ";
  in >> tempR;

  c = Circle(tempX, tempY, tempR);

  return in;
}


void Circle::print() const
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
   Circle a;
   Circle b(2,3,3.0);

   a.print();
   b.print();
  
   cout << "The area a + b is: " << a+b << endl;
   (++a).print();
   a.print();

   (a++).print();
   a.print();

   cout << a;

   cin >> a;
   cout << a;

  return 0;

}
