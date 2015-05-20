#include<iostream>//swap1与swap2都可以实现两数的交换 
int main()
{
    extern void swap1(int*,int*);
    extern void swap2(int&,int&);
    int a=10;
    int b=100;
    int c=10;
    int d=100;
    swap1(&a,&b);//注意此处绝对不能为swap(a,b) 
    swap2(c,d);//区别swap1与swap2的差别 
    std::cout<<"a="<<a<<"\nb="<<b<<"\n";
    std::cout<<"c="<<c<<"\nd="<<d<<"\n";
    
    system("pause");
    return 0;
} 
void swap1(int* p,int* q)//交换p、q值的函数 
{
     int t=*p;
     *p=*q;
     *q=t;
}
void swap2(int &p,int &q)//交换p、q值的函数 
{
     int t=p;
     p=q;
     q=t;
}

