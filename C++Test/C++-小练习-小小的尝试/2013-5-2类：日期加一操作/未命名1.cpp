#include<iostream>
using namespace std;
class date
{
      int year,month,day;
      public:
             int is_leap_year();
             int number_of_days();
             void set(int y,int m,int d);
             void addday();
};

int date::is_leap_year()
{
     return((year%4==0&&year%100!=0)||year%400==0);
}

void date::set(int y,int m, int d)
{
      year=y,month=m, day=d;
}

int date::number_of_days()
{//定义了判断月的天数的函数 
    int days;
    int days_ptr_month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(is_leap_year()&&(month==2))
        days=29;
    else
        days=days_ptr_month[month];
    
    return days;
}

void date::addday()
{
     if(day>number_of_days()||month>12||month<1||year>9999||day<1)
         cout<<"error"<<endl;
     else
     {
         if(day!=number_of_days()&&day<number_of_days())
         {//定义了判断月的天数的函数，在这里直接使用就会很方便 
             day=day+1;
             month=month;
             year=year; 
         }
         else if(month==12)
         {
              day=1;
              month=1;
              year=year+1;
         }
         else
         {
             day=1;
             month=month+1;
             year=year;
         }
         cout<<"Tomorrow'date is:"<<day<<'/'<<month<<'/'<<year<<endl;
     }    
}

int main()
{
    date d;
    d.set(2001,12,12);
    d.addday();
    system("pause");
    return 0;
}
