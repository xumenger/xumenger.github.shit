#include<iostream>
#include <cstring>
#include <cassert>
using namespace std;

char* cat(const char* str1,const char* str2)
{
    assert(str1!=NULL && str2!=NULL);
    int len1=strlen(str1);
    int len2=strlen(str2);
    char *str=new char(len1+len2+1);
    if(str==NULL)
        cout<<"ÄÚ´æ·ÖÅäÊ§°Ü\n";
    strcpy(str,str1);
    strcpy(str+len1,str2);
    assert(strlen(str)==len1+len2);
    return str;
}

int main()
{
    char str1[]="pefect ";
    char str2[]="world";
    char* str=cat(str1,str2);
    cout<<str<<endl;
    delete str;
    
    system("pause");
    return 0;
} 
