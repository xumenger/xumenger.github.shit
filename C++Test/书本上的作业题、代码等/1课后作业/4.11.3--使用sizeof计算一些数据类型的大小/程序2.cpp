#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    enum Day{Sunday,Monday,Tuesday,Wednesday,Thursay,Friday,Saturday};
    cout<<setw(20)<<right<<"bool    "<<sizeof(bool)<<endl;//setw(20)表示空20格，right表示输出靠右 
    cout<<setw(20)<<right<<"short    "<<sizeof(short)<<endl;
    cout<<setw(20)<<right<<"int    "<<sizeof(int)<<endl;
    cout<<setw(20)<<right<<"int*    "<<sizeof(int*)<<endl;
    cout<<setw(20)<<right<<"long    "<<sizeof(long)<<endl;
    cout<<setw(20)<<right<<"float    "<<sizeof(float)<<endl;
    cout<<setw(20)<<right<<"float*    "<<sizeof(float*)<<endl;
    cout<<setw(20)<<right<<"double    "<<sizeof(double)<<endl;
    cout<<setw(20)<<right<<"double*    "<<sizeof(double*)<<endl;
    cout<<setw(20)<<right<<"long double    "<<sizeof(long double)<<endl;
    cout<<setw(20)<<right<<"long double*    "<<sizeof(long double*)<<endl;
    cout<<setw(20)<<right<<"enum Day    "<<sizeof(enum Day)<<endl;
    
    system("pause");
    return 0;
}
