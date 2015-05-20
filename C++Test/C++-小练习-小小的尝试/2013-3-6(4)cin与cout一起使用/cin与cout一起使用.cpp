#include<iostream>
using namespace std;
int main()
{
    cout <<"please enter your name and age:" <<endl;
    char name[10];
    int age;
    cin >>name;//注意输入字符串的语句的格式
    cin >>age;
    cout <<"your name is:" <<name <<endl;
    cout <<"your age is:" <<age <<endl; 
    
    system("pause");
    return 0;
} 
