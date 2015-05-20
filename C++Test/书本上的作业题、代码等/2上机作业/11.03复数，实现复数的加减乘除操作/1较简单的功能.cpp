#include<iostream>
using namespace std;
class complex
{
      private:
              float real;
              float imag;
      public:
             complex();
             complex(float re,float im);
             complex operator+(complex &c);
             complex operator-(complex &c);
             complex operator*(complex &c);
             complex operator/(complex &c);
             void getvalue();
};
int main()
{
    complex c1=complex(1,1);
    complex c2=complex(1,-1);
    complex c3;
    c3=c1+c2;
    c3.getvalue();
    c3=c1-c2;
    c3.getvalue();
    c3=c1*c2;
    c3.getvalue();
    c3=c1/c2;
    c3.getvalue();
    
    system("pause");
    return 0; 
}

complex::complex()
{
    real=0;
    imag=0;
}

complex::complex(float re,float im)
{
    real=re;
    imag=im;
}

complex complex::operator+(complex &c)
{
    complex x;
    x.real=real+c.real;
    x.imag=imag+c.imag;
    return x;
}

complex complex::operator-(complex &c)
{
    complex x;
    x.real=real-c.real;
    x.imag=imag-c.imag;
    return x;
}

complex complex::operator*(complex &c)
{
    complex x;
    x.real=real*c.real-imag*c.imag;
    x.imag=imag*c.real+c.imag*real;
    return x;
}

complex complex::operator/(complex &c)
{
    complex x;
    x.real=(real*c.real-imag*(-c.imag))/(c.real*c.real+c.imag*c.imag);
    x.imag=(real*(-c.imag)+imag*c.real)/(c.real*c.real+c.imag*c.imag);
    return x;
}

void complex::getvalue()
{
     cout<<real<<"+"<<imag<<"i"<<endl;
}
