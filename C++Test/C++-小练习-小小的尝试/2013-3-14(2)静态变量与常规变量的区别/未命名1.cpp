#include<iostream>//静态变量与常规变量的区别 
void f(int a)
{
     while(a--)
     {
         static int n=0;//静态变量 
         int x=0;//常规变量 
         std::cout<<"n=="<<n++<<",x=="<<x++<<'\n';
     }
}
int main()
{
    f(3);
    
    system("pause");
    return 0;
} 
