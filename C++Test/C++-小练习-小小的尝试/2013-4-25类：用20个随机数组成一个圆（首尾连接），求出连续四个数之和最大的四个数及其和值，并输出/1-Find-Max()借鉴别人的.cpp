#include<iostream>
using namespace std;

class Circle
{
      public:
             Circle();//圆盘类的
             void Find_Max();//圆盘类的主要操作，寻找符合条件的（和为最小）连续的4个数 
             void Show(void);//输出圆盘类的整个数列、最大的四个数及其和值
          
      private:
              int num[20];//存放生成的20个随机数
              int Max[4];//存放20个随机数中连续4个数之和中最大的那4个连续的数
              int sum_max;//存放20个随机数中连续4个数之和中最大的和 

} ;

int main()
{
    Circle *cir=new Circle();
    cir->Find_Max();
    cir->Show();
    delete cir;
    cir=NULL;
    
    system("pause");
    return 0;
} 

Circle::Circle()
{
    for (int i(0);i<20;i++)
        num[i]=rand();
}

void Circle::Show(void)
{
     cout<<"圆盘类的整个数列："<<endl;
     for(int i(0);i<20;i++)
         cout<<" "<<num[i];
         
     cout<<endl<<"最大的四个数："<<endl;
     for(int i(0);i<4;i++)
         cout<<" "<<Max[i];
     
     cout<<endl<<"和值:"<<sum_max<<endl; 
     
}
void Circle::Find_Max()
{
    int max_index(0);
 
    for(int i(0);i<20;i++)
    {
        int acc(0);
        for(int k(0);k<4;k++)
        {
            int n=i+k;
            if( n >= 20)
            {
                n-=20;
            }
            // 连续4个数之和
            acc += num[n];
        } // for k
        if(i==0)
        {
            sum_max = acc;
            
        }
        else
        {
            
            if( sum_max < acc) 
            {
                sum_max = acc;
                max_index = i;
            }
        }
    } // for i
    for(int k(0);k<4;k++)
    {
            int n;
        // 存放20个随机数中连续4个数之和中最大的那4个连续的数 
            n=max_index+k;
            if( n >= 20)
            {
                n-=20;
            }
        Max[k] = num[n];
    } // for k
     
     
}












