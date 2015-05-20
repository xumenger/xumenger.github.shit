#include<iostream>
int main()
{
    char c[1000];
    int i=0;
    int j;
    while(1)
    {
       std::cin>>c[i];
       
       if(i>=3&&c[i]=='t'&&c[i-1]=='i'&&c[i-2]=='u'&&c[i-3]=='Q')
       {
           for(j=0;j<=i;j++)
              std::cout<<c[j];
           break;
       }
       else
           i++; 
    }
    
    system("pause");
    return 0;
}
