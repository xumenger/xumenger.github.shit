#include<iostream>
#include<cstring>
using namespace std;
struct STR
{
    char c[100];
    
};
typedef struct STR str;
int main()
{
    str st1[100];
    str st2[100];
    int i=0;
    cin>>st1[0].c;
    while(strcmp(st1[i].c,"Quit")!=0) 
    {
        i++;
        cin>>st1[i].c;
        
    }
    
    cout<<"输出单词为（不重复输出）："<<endl;
    int k=i;
    int j=0;
    int t;
    st2[0]=st1[0];
    int b;
    cout<<st1[0].c<<endl;
    for(i=1;i<k;i++)
    {
        for(t=0;t<=j;t++)
        {
            if(strcmp(st1[i].c,st2[t].c)==0)
            {
                b=1; 
            } 
        }
        if(b!=1)
        {
            cout<<st1[i].c<<endl;   
                   
            j++;
            st2[j]=st1[i];
            b=0;
        }
        
    }
    system("pause");
    return 0;
} 
