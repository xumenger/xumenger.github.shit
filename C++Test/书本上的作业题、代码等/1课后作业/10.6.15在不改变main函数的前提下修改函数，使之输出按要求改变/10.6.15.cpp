#include<iostream>
using namespace std;

class out{
public:
    out(){cout<<"Initialize"<<endl;}
    ~out(){cout<<"Clear up"<<endl;}
};

out oo;

int main()
{
    cout<<"Hello,world"<<endl;
    system("pause"); 
    return 0;
}
