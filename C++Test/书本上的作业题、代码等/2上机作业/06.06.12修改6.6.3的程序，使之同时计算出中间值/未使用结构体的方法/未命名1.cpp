#include<iostream>//此例程暂时以处理不到100组数据为例 
#include<cstring>
using namespace std;

void mppx(float a[],int N); 

int main()
{
    int i=0;
    int j;
    float a1[100];      //记录每个原始输入的名字对应的数值 
    float a2[100];      //记录整理后没有重复的名字对应的值 
    int a3[100];        //记录整理后的那些名字重复的次数 
    for(i=0;i<100;i++)
        a3[i]=1; 
        
    int b[100];
    char str1[100][100];
    char str2[100][100];
    
    for(i=0;;i++)
    {
       cin>>str1[i];
       cin>>a1[i];
       b[i]=1;          //做标记 
       if(strcmp(str1[i],"end")==0)
           break;
    } 
    
    int m=i;
    int k=0;
    for(i=0;i<m;i++)
    {
        if(b[i]==1)
        {
            strcpy(str2[k],str1[i]);
            a2[k]=a1[i];
            
            for(j=i+1;j<m;j++)
            {
                if(strcmp(str1[i],str1[j])==0)
                {
                    
                    a2[k]=a2[k]+a1[j];
                    a3[k]++;
                    
                    b[j]=0;
                }
            }
            k++;
        }
    }
    cout<<"以下为每个名字的所有值之和及平均值："<<endl;
    int x;
    for(x=0;x<k;x++)
    {
        
        cout<<str2[x]<<"    "<<a2[x]<<"      "<<a2[x]/a3[x]<<endl;
    }
    
    cout<<endl<<"以下输出所有的名字的和及平均值："<<endl;
    float a=0;
    for(i=0;i<m;i++)
       a=a+a1[i];
    float ave=a/m;
    cout<<a<<"     "<<ave<<endl; 
    
    cout<<endl<<"以下输出整理好重复名字后（同名的数字进行了相加）的中间值："<<endl;//对str2和a2进行操作 
    mppx(a2,k); 
    if(k%2==1)
       cout<<a2[k/2]<<endl;
    else
    {
        float b=(a2[k/2-1]+a2[k/2])/2;
        cout<<b<<endl;
    }
    
    system("pause");
    return 0;
} 

void mppx(float a[],int N)//冒泡排序 
{
     int i,j;
     float tmp1;
     for(i=0;i<N;i++)
     {
        for(j=0;j<N-i;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp1=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp1;
                
            } 
        }
     }
 }
