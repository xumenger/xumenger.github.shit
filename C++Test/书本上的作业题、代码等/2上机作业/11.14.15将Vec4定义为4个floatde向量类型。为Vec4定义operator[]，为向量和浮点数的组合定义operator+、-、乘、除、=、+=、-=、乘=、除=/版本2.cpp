#include<iostream>
using namespace std;

class Vec4
{
      float s[4];
      class Error{};//
      public:
             Vec4(float a=0.0,float b=0.0,float c=0.0,float d=0.0)
             {
                 s[0]=a;
                 s[1]=b;
                 s[2]=c;
                 s[3]=d;
             }
             void check(int i)
             {
                  if(i<0||i>4)
                  throw Error();//
             } 
             float operator[](int i)
             {
                   check(i);
                   return s[i];
             }
             friend Vec4 operator+(const Vec4& a,const Vec4& b)//
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]+b.s[0];
                    sa.s[1]=a.s[1]+b.s[1];
                    sa.s[2]=a.s[2]+b.s[2];
                    sa.s[3]=a.s[3]+b.s[3];
                    return sa;
             }
             friend Vec4 operator-(const Vec4& a,const Vec4& b)
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]-b.s[0];
                    sa.s[1]=a.s[1]-b.s[1];
                    sa.s[2]=a.s[2]-b.s[2];
                    sa.s[3]=a.s[3]-b.s[3];
                    return sa;
             }
             friend Vec4 operator*(const Vec4& a,const Vec4& b)
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]*b.s[0];
                    sa.s[1]=a.s[1]*b.s[1];
                    sa.s[2]=a.s[2]*b.s[2];
                    sa.s[3]=a.s[3]*b.s[3];
                    return sa;
             }
             friend Vec4 operator/(const Vec4& a,const Vec4& b)
             {
                    for(int i=0;i<4;i++)
                    {
                        if(b.s[i]==0)
                            throw Error();
                    }
                    
                    Vec4 sa;
                    sa.s[0]=a.s[0]/b.s[0];
                    sa.s[1]=a.s[1]/b.s[1];
                    sa.s[2]=a.s[2]/b.s[2];
                    sa.s[3]=a.s[3]/b.s[3];
                    return sa;
             }
             friend Vec4 operator+(const Vec4& a,float f)//
             {
                    Vec4 sa;
                    sa.s[0]=a.s[0]+f;
                    sa.s[1]=a.s[1]+f;
                    sa.s[2]=a.s[2]+f;
                    sa.s[3]=a.s[3]+f;
                    return sa;
             }
             /*Vec4& operator=(Vec4& a)
             {
                   s[0]=a.s[0];
                   s[1]=a.s[1];
                   s[2]=a.s[2];
                   s[3]=a.s[3];
                   
                   return *this;
             }
             Vec4& operator=(float a)
             {
                   s[0]=a;
                   s[1]=a;
                   s[2]=a;
                   s[3]=a;
                   
                   return *this;
             }*/
             //不要赋值号，程序可以运行，有了赋值号，程序反而不能运行了，为什么 
             Vec4 operator+=(Vec4& a)
             {
                  s[0]+=a.s[0];
                  s[1]+=a.s[1];
                  s[2]+=a.s[2];
                  s[3]+=a.s[3];
                  
                  return *this;
             }
             Vec4 operator-=(Vec4& a)
             {
                  s[0]-=a.s[0];
                  s[1]-=a.s[1];
                  s[2]-=a.s[2];
                  s[3]-=a.s[3];
                  
                  return *this;
             }
             Vec4 operator*=(Vec4 &a)
             {
                  s[0]*=a.s[0];
                  s[1]*=a.s[1];
                  s[2]*=a.s[2];
                  s[3]*=a.s[3];
                  
                  return *this;
             }
             Vec4 operator/=(Vec4& a)
             {
                  for(int i=0;i<4;i++)
                  {
                      if(a.s[i] == 0)
                          throw Error();
                  }
                  s[0]/=a.s[0];
                  s[1]/=a.s[1];
                  s[2]/=a.s[2];
                  s[3]/=a.s[3];
                  return *this;
             }
             
};

int main()
{
    cout<<"功能："<<endl;
    cout<<"     先输入d向量的前三个值（第四个默认为0），同时程序自定义了a，b，c的值，依次做b=b+a、a=a+1、d=d+b的运算，最后输出a、b、c、d"<<endl;
    
    int i,j,k;
    cin>>i>>j>>k;
    Vec4 d(i,j,k); 
    Vec4 a(23,45,34),b(0,8,9,4),c;//a虽然只给了三个赋值，但之前所写的Vec4的构造函数默认剩下的为最后一个且默认赋值0 
    b=b+a;
    a=a+1;
    d=b+d;
    c=a+b; 
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
    
    system("pause");
    return 0;
}
