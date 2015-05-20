#include<iostream>
void f1(int val,int &ref)//第一个形参为值调用，第二个为引用调用 
{
    val++;
    ref++;
}

void f2(int *val,int &ref)//第一个为另一种值调用，第二个为引用调用 
{                             //不过该种函数形式有错 
     val++;
     ref++;
} 

int main()
{
    int i=1;
    int j=1;
    f1(i,j);
    std::cout<<i<<"\n"<<j<<"\n";
    f1(i,j);
    std::cout<<i<<"\n"<<j<<"\n";//值调用与引用调用的区别 
    
    f1(2,j);
    //f1(1,2);这种用函数的形式错误，因为按f1()中定义要求第一个实参为int型，第二个为int&型，这样用造成实参形参不匹配 
    
    
    int a=1;
    int b=1; 
    f2(&a,b);
    std::cout<<a<<"\n"<<b<<"\n";
    f2(&a,b);
    std::cout<<a<<"\n"<<b<<"\n";//另一种值调用与引用调用的区别 
    
    system("pause");
    return 0;
} 
