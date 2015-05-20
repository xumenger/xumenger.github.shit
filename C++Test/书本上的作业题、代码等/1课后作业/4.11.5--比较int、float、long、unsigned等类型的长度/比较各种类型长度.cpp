#include<iostream>
int main()
{
    int i[8];
    i[0]=sizeof(char);
    i[1]=sizeof(short);
    i[2]=sizeof(int);
    i[3]=sizeof(long);
    i[4]=sizeof(float);
    i[5]=sizeof(double);
    i[6]=sizeof(long double);
    i[7]=sizeof(unsigned);
    
    int j;
    int t=0;
    for(j=0;j<8;j++)
    {
        
        if(t<i[j])
            t=i[j];
    } 
    std::cout<<t<<'\n';
    
    system("pause");
    return 0;
}
