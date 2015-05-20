#include<iostream>
int main()
{
    int i1,i2,i3,i4,i5,i6,i7,i8;
    i1=sizeof(int);
    i2=sizeof(long);
    i3=sizeof(char);
    i4=sizeof(int *);
    i5=sizeof(float *);
    i6=sizeof(char *);
    enum e1{a,b,c};
    enum e2{x=3,y=5,z=8};
    i7=sizeof(e1);
    i8=sizeof(e2);
    std::cout<< i1 <<'\n';
    std::cout<< i2 <<'\n';
    std::cout<< i3 <<'\n';
    std::cout<< i4 <<'\n'; 
    std::cout<< i5 <<'\n'; 
    std::cout<< i6 <<'\n'; 
    std::cout<< i7 <<'\n';
    std::cout<< i8 <<'\n';
    
    system("pause");
}
