#include<iostream>
using namespace std;

int main()
{
    int j;
    cin>>j; 
    string st[j];
    int i;
    for(i=0;i<j;i++)
        cin>>st[i];
  
    for(i=0;i<j;i++)
        cout<<"Hello,"<<st[i]<<endl;
    
    system("pause");
    return 0;
} 


/*Ô­À´µÄ
int main(int i,char *c[])
{
      if(i<2)
         cout<<"WRONG!"<<endl;
      else
         for(int j=1;j<i;j++)
             cout<<"Hello,"<<c[j]<<endl;
      
      return 0;
} 
*/
