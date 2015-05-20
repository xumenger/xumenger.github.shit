#include<iostream>
#include<cmath>
#include<cassert>
using namespace std;

class Vec4
{
    float v[4];
    public:
           Vec4(float fv1=0.0,float fv2=0.0,float fv3=0.0,float fv4=0.0)//这是一个技巧，很好！ 
           {//这样定义的Vec4的构造函数，可以用户自己用例Vec4 a(1,2,3,4)的形式输入向量值，也可以直接Vec4 a，则a默认为(0,0,0,0)，还可以例如Vec4 a(1,2,3)，少输入一个，则a默认为(1,2,3,0) 
               v[0]=fv1;
               v[1]=fv2;
               v[2]=fv3;
               v[3]=fv4;
           }
           ~Vec4(){};
           float& operator[](int);
           Vec4& operator+(float);//这是定义Vec4向量与数字相加的加法 
           Vec4& operator+(Vec4&);//这是定义Vec4向量与另一个Vec4向量相加的加法，两个可以一起实现，下面的减都可以类似实现 
           Vec4& operator-(float);
           Vec4& operator*(float);//乘也可以同时实现向量与向量的乘法，不过与向量与向量的加法不同 
           Vec4& operator/(float);
           Vec4& operator=(float);
           Vec4& operator+=(float);
           Vec4& operator-=(float);
           Vec4& operator*=(float);
           Vec4& operator/=(float);
           void print()
           {
                cout<<v[0]<<","<<v[1]<<","<<v[2]<<","<<v[3]<<endl;
           }
};

float& Vec4::operator[](int i)
{
       assert(0<=i&&i<4);//assert函数的功能：如果括号里的表达式为假，整个程序将退出，并输出一条错误信息。如果表达式的值为真则继续执行后面的语句 
       return v[i];
}

Vec4& Vec4::operator+(Vec4& x)//注意加减乘除的运算符实现的格式 
{
      v[0]=v[0]+x.v[0];
      v[1]=v[1]+x.v[1];
      v[2]=v[2]+x.v[2];
      v[3]=v[3]+x.v[3];
      return *this;
} 

Vec4& Vec4::operator+(float x)
{
      v[0]=v[0]+x;
      v[1]=v[1]+x;
      v[2]=v[2]+x;
      v[3]=v[3]+x;
      return *this;
} 

Vec4& Vec4::operator-(float x)
{
      v[0]=v[0]-x;
      v[1]=v[1]-x;
      v[2]=v[2]-x;
      v[3]=v[3]-x;
      return *this;
}

Vec4& Vec4::operator*(float x)
{
      v[0]=v[0]*x;
      v[1]=v[1]*x;
      v[2]=v[2]*x;
      v[3]=v[3]*x;
      return *this;
}

Vec4& Vec4::operator/(float x)
{
      if(fabs(x)<=1.0e-4)//fabs针对浮点数求绝对值，而abs针对整数求绝对值 
      {
           cout<<"error"<<endl;
           return *this; 
      } 
      else
      {
          v[0]=v[0]/x;
          v[1]=v[1]/x;
          v[2]=v[2]/x;
          v[3]=v[3]/x;
          return *this;
      }
}

Vec4& Vec4::operator=(float x)
{
      v[0]=x;
      v[1]=x;
      v[2]=x;
      v[3]=x;
      return *this;
}

Vec4& Vec4::operator+=(float x)
{
      v[0]+=x;
      v[1]+=x;
      v[2]+=x;
      v[3]+=x;
      return *this;
}

Vec4& Vec4::operator-=(float x)
{
      v[0]-=x;
      v[1]-=x;
      v[2]-=x;
      v[3]-=x;
      return *this;
}

Vec4& Vec4::operator*=(float x)
{
      v[0]*=x;
      v[1]*=x;
      v[2]*=x;
      v[3]*=x;
      return *this;
}

Vec4& Vec4::operator/=(float x)
{
      v[0]/=x;
      v[1]/=x;
      v[2]/=x;
      v[3]/=x;
      return *this;
}


int main()
{
    cout<<"功能："<<endl;
    cout<<"     先输入d向量的前三个值（第四个默认为0），同时程序自定义了a，b，c的值，依次做b=b+a、a=a+1、d=d+b的运算，最后输出a、b、c、d"<<endl;
    
    float i,j,k;
    cin>>i>>j>>k;
    Vec4 d(i,j,k); 
    Vec4 a(23.0,45.0,34.0),b(0.0,8.0,9.0,4.0),c;//a虽然只给了三个赋值，但之前所写的Vec4的构造函数默认剩下的为最后一个且默认赋值0 
    b=b+a;
    a=a+1.0;
    d=d+b;//如果写成d=b+d则不行，因为在定义+时，就隐式地定义了顺序，坚决不能变，否则出错 
    
    
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
    cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[3]<<endl;
    
    system("pause");
    return 0;
}
