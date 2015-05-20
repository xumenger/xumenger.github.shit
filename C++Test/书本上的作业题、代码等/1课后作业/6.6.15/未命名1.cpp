#include<iostream>
using namespace std;
void send(int*,int*,int);

int main()
{
    int *to;
    int *from;
    int count=10;
    send(to,from,count);
    cout<<*to<<endl<<*from<<endl<<count<<endl;
    
    system("pause");
    return 0;
} 

void send(int* to,int* from,int count)
{
     int n=(count+7)/8;
     switch(count%8){
     case 0:  do{  *to++=*from++;
     case 7:       *to++=*from++;
     case 6:       *to++=*from++;
     case 5:       *to++=*from++;
     case 4:       *to++=*from++;
     case 3:       *to++=*from++;
     case 2:       *to++=*from++;
     case 1:       *to++=*from++;
          }while(--n>0);
     }     
}
