#include<iostream>
using namespace std;
int main()
{
    int max(int x,int y);//对max函数做声明 
    int a,b,c;
    cin >>a >>b;
    c=max(a,b);//调用max函数 
    cout <<"max=" <<c <<"\n";
    system("pause");
    return 0;
} 

int max(int x,int y)//定义max函数 
{
    int z;
    if(x>y)
       z=x;
    else
       z=y;
    return z;
}
