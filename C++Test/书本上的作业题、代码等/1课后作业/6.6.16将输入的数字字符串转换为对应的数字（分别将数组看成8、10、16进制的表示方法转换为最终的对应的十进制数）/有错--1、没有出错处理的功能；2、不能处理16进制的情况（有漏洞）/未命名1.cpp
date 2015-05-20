#include<iostream>
#include<cstring>
using namespace std;

int atoi(char* ,int);
int square(int i,int base);

int main()
{
    char c[100];
    int n;
    int base;
    
    cout<<"请输入数字字符串：";
    cin>>c;
    
    cout<<"该数为多少进制的数：";
    cin>>base;
    
    n=atoi(c,base);
    cout<<"该数转化为十进制的数为："<<n<<endl;
    
    
    system("pause");
    return 0;
} 

int atoi(char* c,int base)
{
    int i=strlen(c);
    int m[i];
    int k;
    for(k=0;k<i;k++)
    {
        m[k]=c[k]-'0';
    } 
    int n=0;
    for(k=0;k<i;k++)
        n=n+m[k]*square(i-k-1,base);
    
    return n;
    
}
int square(int i,int base)//计算 base 的 i 次方 
{
    int k;
    int end=1;
    for(k=0;k<i;k++)
    {
        end=end*base;
    }
    return end;
}
