#include<iostream>
#include<string>
int main()
{
    int i,j,t,k;
    k=0;
    char c[2];
    char s[1000];
    std::cout<<"输入一字符串:";
    std::cin>>s;
    std::cout<<"输入要找的一对字符:";
    for(i=0;i<2;i++)
       std::cin>>c[i];
    j=strlen(s);
    for(t=0;t<j-1;t++)
    {
        if(s[t]==c[0]&&s[t+1]==c[1])
            k++;
    }
    std::cout<<"在该字符串中找到"<<k<<"对"<<'\n';
    
    
    system("pause");
    return 0;
}
