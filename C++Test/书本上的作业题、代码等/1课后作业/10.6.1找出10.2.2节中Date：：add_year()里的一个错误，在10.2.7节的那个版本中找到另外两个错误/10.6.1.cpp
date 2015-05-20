#include<iostream>
using namespace std;

class Date{
      int d;
      int m;
      int y;
public:
       void init(int dd,int mm,int yy);//初始化
       
       void add_year(int n);//加n年
       //void add_month(int n);//加n月
       //void add_day(int n);//加n天
       void printdate();
};

inline void Date::init(int dd,int mm,int yy)
{
    d=dd;
    m=mm;
    y=yy;
    cout<<d<<"  "<<m<<"  "<<y<<endl;
}

inline void Date::add_year(int n)
{
    y+=n;
    
} 

void Date::printdate()
{
    cout<<d<<"  "<<m<<"  "<<y<<endl;
}

int main()
{
    Date D;
    D.init(10,4,2013);
  
    D.add_year(10);
    D.printdate();
    
    
    system("pause");
    return 0;
}
