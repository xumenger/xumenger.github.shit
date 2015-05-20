#include<iostream>
using namespace std;

int ctoi(char c);
int square(int i,int base);
int atoi(char* c,int base);

int main()
{
    char c[100];
    int n;
    int base;
    
    cout<<"请输入数字字符串：";
    cin>>c;
    
    cout<<"该数为多少进制的数：";
    cin>>base;
    
    if(atoi(c,base)==-1)
        cout<<"ERROR!"<<endl;
    else
    {
        n=atoi(c,base);
        cout<<"该数转化为十进制的数为："<<n<<endl;
    }
    
    
    system("pause");
    return 0;
}

int ctoi(char c)//把字符转换为对应的数字 
{
    int i;
    switch(c)//case语句一定要放在switch的{}里面，否则出错！ 
    {
       case '0': i=0;break;
       case '1': i=1;break;
       case '2': i=2;break;
       case '3': i=3;break;
       case '4': i=4;break;
       case '5': i=5;break;
       case '6': i=6;break;
       case '7': i=7;break;
       case '8': i=8;break;
       case '9': i=9;break;
       case 'a':
       case 'A': i=10;break;
       case 'b': 
       case 'B': i=11;break;
       case 'c': 
       case 'C': i=12;break;
       case 'd': 
       case 'D': i=13;break;
       case 'e': 
       case 'E': i=14;break;
       case 'f':
       case 'F': i=15;break;
       default : return -1;
    }
       
       return i;
       
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

int atoi(char* c,int base)
{
    int i; 
    int e;
    int len=strlen(c);
    for(i=0;i<len;i++)
    {
        if((ctoi(c[i])>base-1)||(ctoi(c[i])==-1))  
        {   
           
           e=-1;
           return -1;
        }          
    }
    
    int n=0;
    if(e!=-1)
    {
        for(i=0;i<len;i++)
            n=n+ctoi(c[i])*square(len-i-1,base);
    
        return n;
    }
} 
