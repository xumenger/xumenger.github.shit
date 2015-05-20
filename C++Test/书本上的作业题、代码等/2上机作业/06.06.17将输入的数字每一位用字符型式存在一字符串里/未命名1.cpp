#include<iostream>
using namespace std;

void itoa(int i,char b[]);
int square10(int i); 
int weishu(int i);

int main()
{
    
    int ii;
    cout<<"请输入一个数字：";
    cin>>ii;
    int j=weishu(ii);
    char bb[j+1];
    itoa(ii,bb);
    cout<<"输出字符串为：";
    int k;
    for(k=0;k<j;k++)
       cout<<bb[k];
    cout<<endl;
    
    system("pause");
    return 0;
} 
void itoa(int i,char b[])
{
     int j=weishu(i);
     int k;
     int t;
     int m=0;
     for(k=j;k>0;k--)
     {
         t=i/square10(k-1);
         b[m]='1'+t-1;
         i=i-t*square10(k-1);
         m++;
     }
     
}

int square10(int i)//计算 10 的 i 次方 
{
    int k;
    int end=1;
    for(k=0;k<i;k++)
    {
        end=end*10;
    }
    return end;
}

int weishu(int i)//此处是为了求出i的位数，用j存储 
{
    int j;
     for(j=0;;)
     {
         if(i-square10(j)<0)
            break;
         else
            j++;
     }
     return j;
}












