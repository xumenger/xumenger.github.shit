#include<iostream> 
using namespace std;

class Date
{
      int d,m,y;
      static Date default_date;
public:
       enum Month{jan=1,feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
       class Bad_date{};
       Date(int dd=0,Month mm=Month(0),int yy=0);
       int day() const;
       Month month() const;
       int year() const;
       static void set_default(int,Month,int);
       Date& add_year(int n);
       Date& add_month(int n);
       Date& add_day(int n);
       
       int leapyear(int);
} ;

Date::Date(int dd,Month mm,int yy)
{
    if(yy==0) 
        yy=default_date.year();
    if(mm==0)
        mm=default_date.month();
    if(dd==0)
        dd=default_date.day();
    int max;
    switch(mm)
    {
        case feb :
             max=28+leapyear(yy);
             break;
        case apr: case jun: case sep: case nov:
             max=30;
             break;
        case jan: case mar: case may: case jul: case aug: case oct: case dec:
             max=31;
             break;
        default:
             throw Bad_date();  
             //throw的用法 
    }
    if(dd<1||max<dd)
        throw Bad_date();
    y=yy;
    m=mm;
    d=dd;
}
Date Date::default_date(1,Month(1),1970);

int Date::day() const//这是什么格式，有什么作用
{
    return d;
} 
Date::Month Date::month()const
{
    return (Month)m; 
}
int Date::year() const
{
    return y;
}

void Date::set_default(int yy,Month mm,int dd)
{
     int max;
     switch(mm)
     {
         case feb:
              max=28+default_date.leapyear(yy);
              break;
         case apr: case jun: case sep: case nov:
             max=30;
             break;
         case jan: case mar: case may: case jul: case aug: case oct: case dec:
             max=31;
             break;
         default:
             throw Bad_date();  
     }
     if(dd<1||max<dd) throw Bad_date();
     default_date.y=yy;
     default_date.m=mm;
     default_date.d=dd;
}
Date& Date::add_year(int n)
{
      y+=n;
      return *this;
}
Date& Date::add_month(int n)
{
      if(n==0) return *this;
      if(n>0)
      {
           int delta_y=n/12;
           int mm=m+n%12;
           if(12<mm)
           {
               delta_y++;
               mm-=12;
           }
           y+=delta_y;
           m=Month(mm);
           return *this;
           //this的类型、作用、性质 
      }
      return *this;
}
Date& Date::add_day(int n)
{
      while(n>365)
      {
          if(d<=28&&m<=2&&leapyear(y)||leapyear(y+1))
          {
              y++;
              n-=366;
          }
          n-=365;
      } 
      while(n)
      {
          switch(m)
          {
              case jan:
              case mar:
              case may:
              case jul:
              case aug:
              case oct:
              case dec:
                   if(d+n>31)
                   {
                       m++;
                       if(m>12)
                       {
                           m=1;
                           y++;
                       }
                       n-=(32-d);
                       d=1; 
                   }   
                   else 
                   {
                        d+=n;
                        n=0;
                   }  
                   break;
              case apr:
              case jun:
              case sep:
              case nov:
                   if(d+n>30)
                   {
                       m++;
                       n-=(31-d);
                       d=1;
                   }
                   else
                   {
                       d+=n;
                       n=0;
                   }
                   break;
              default:
                    if(d+n>28+leapyear(y))
                    {
                         m++;
                         n-=(28+leapyear(y)+1-d);
                         d=1;                 
                    }  
                    else
                    {
                        d+=n;
                        n=0;
                    }
          }
      } 
      return *this;
} 
int Date::leapyear(int yy)
{
    if(yy%400==0||(yy%4==0&&yy%100!=0))
        return 1;
    else 
        return 0;
}

int main()
{
    int yx,mx,dx,count=0;
    Date mydate;
    cout<<"请输入一个日期："<<endl; 
    cin>>yx>>mx>>dx;
    while(!(mydate.day()==dx)||!(mydate.month()==mx)||!(mydate.year()==yx))
    {
        mydate.add_day(1);
        count++;
    }
    cout<<"距1970.1.1差"<<count<<"天"<<endl;
    system("pause");
    return 0;
}
