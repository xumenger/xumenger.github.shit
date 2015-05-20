#include<iostream>
using namespace std; 

class Shape
{
    public:
           virtual bool closed()=0;
           virtual void rotate(int)=0;
           virtual void draw()=0;
};
class Point
{
      friend class Shape;//
      int x;
      int y;
      public:
             Point(int i=0,int j=0):x(i),y(j){}//这是什么格式 
};
class Circle:public Shape
{
    int radius;//半径 
    Point center;//圆心 
    public:
           Circle(int r=0,int i=0,int j=0):radius(r),center(i,j)//
           {
               cout<<"it is a circle!\n";
           } 
           bool closed()
           {
                cout<<"it is closed!\n";
                return 1;
           }
           void rotate(int u)
           {
                cout<<"the circle rotate!\n";
           }
           void draw()
           {
               cout<<"using circle draw!\n";
           }
};
class Square:public Shape
{
    int length;
    public:
           Square(int i):length(i){cout<<"it is a square!\n";}
           bool closed()
           {
                cout<<"it is closed!\n";
                return 1;
           }
           void rotate(int u)
           {
                cout<<"the square is not rotate!\n"; 
           }
           void draw()
           {
                cout<<"using square draw!\n";
           }
};
class Triangle:public Shape
{
      int line1;
      int line2;
      int line3;
      public:
             Triangle(int i=0,int j=0,int k=0):line1(i),line2(j),line3(k)
             {
                 cout<<"it os a triangle!\n";    
             }
             bool closed()
             {
                  cout<<"it is closed!\n";
                  return 1;
             }
             void rotate(int u)
             {
                  cout<<"the triangle is not rotate!\n"; 
             }
             void draw()
             {
                  cout<<"using triangle draw!\n";
             }
};
bool intersect(Shape *a,Shape *b)
{
     a->draw();
     b->draw();
     return 1;
}


int main()
{
    Circle c1(3,4,5);
    Circle c2(7,8);
    Circle *pc=&c2;
    Square s1(5);
    Square s2(6);
    Square *ps=&s2;
    Triangle t1(6,10,8);
    Triangle t2(5,3,4);
    Triangle *pt=&t2;
    intersect(ps,pt); 
    intersect(pc,pt); 
    intersect(&c1,&s1); 
    intersect(&s1,&t1); 
    
    system("pause");
    return 0;
} 
