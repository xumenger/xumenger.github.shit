#include<iostream>
using namespace std;

struct date
{
    int year,month,day;
};
typedef struct date DATE;

void Input_Date(DATE &D)//输入日期 
{//改成 void Input_Date(DATE D)试试 
     cout<<"请输入年、月、日:"; 
     cin>>D.year>>D.month>>D.day;
}

void Output_Date(DATE D)//输出日期 
{
     cout<<"\n您输入的年、月、日为：";
     cout<<D.year<<"年"<<D.month<<"月"<<D.day<<"日"<<'\n'; 
}

void Initial_Date(DATE &D)//初始化日期
{
     D.year=2013;
     D.month=3;
     D.day=16;
} 

int Judge_Date(DATE D)//判断输入的日期格式是否正确 
{
    if((D.year>0)&&(D.month>0)&&(D.month<13)&&(D.day>0))
    {
        if(((D.month==1)||(D.month==3)||(D.month==5)||(D.month==7)||(D.month==8)||(D.month==10)||(D.month==12))&&(D.day<32))
           return 1;
        else if(((D.month==4)||(D.month==6)||(D.month==9)||(D.month==11))&&(D.day<31))
           return 1;
        else if(((D.year%4!=0)||(D.year%400==0))&&(D.month==2)&&(D.day<29))
           return 1;
        else if(((D.year%4==0)&&(D.year%400!=0))&&(D.month==2)&&(D.day<30))
           return 1;
        else 
           return 0;                                               
    }
    else
        return 0;
} 

void add_day(DATE &D)//对日期进行日加一操作 ,因为日加一操作在下面会多次用到，所以单独分出来实现 ，方便多次使用 
{
                 if(D.month==1||D.month==3||D.month==5||D.month==7||D.month==8||D.month==10)
                 {
                     if(D.day>=1&&D.day<=30)
                        D.day++;
                     else if(D.day==31)
                     {
                         D.day=1;
                         D.month++;
                     }
                 }
                 else if(D.month==4||D.month==6||D.month==9||D.month==11)
                 {
                     if(D.day>=1&&D.day<=29)
                        D.day++;
                     else if(D.day==30)
                     {
                         D.day=1;
                         D.month++;
                     }
                 }
                 else if(D.month==12)
                 {
                      if(D.day>=1&&D.day<=30)
                          D.day++;
                      else if(D.day==31)
                      {
                           D.day=1;
                           D.month=1;
                           D.year++;
                      }
                 }
                 else if(D.month==2)
                 {
                     if(((D.year%4==0)&&(D.year%100!=0))||(D.year%400==0))//闰年
                      {
                          if(D.day>=1&&D.day<=28)
                             D.day++;
                          else if(D.day==29)
                          {
                               D.month++;
                               D.day=1;
                           }
                      } 
                      else//非闰年 
                      {
                          if(D.day>=1&&D.day<=27)
                             D.day++;
                          else if(D.day==28)
                          {
                               D.month++;
                               D.day=1;
                           }
                      }
                      
                 }
}

void add(DATE &D)//要想在引用函数后实参的值改变，就要用到&，否则只是形参变，实参不变，就没法实现希望的功能 
{
    if(Judge_Date(D))
    {
        char c;
        cout<<"输入a，年加一;输入b，月加一;输入c，日加一"<<endl;
        cin>>c;
        switch(c)
        {
            case 'a':
            {
                if((D.year%4==0)&&(D.year%400!=0)&&(D.month==2)&&(D.day==29))
                {//考虑闰年的2.29加一年是次年的3.1 
                    D.year++;
                    D.month++;
                    D.day=1;
                }
                else 
                    D.year++;
                
                break;   
            } 
            case 'b':
            {
                if((((D.year%4==0)&&(D.year%100!=0))||(D.year%400==0))&&(D.month==1)&&(D.day==31))
                {
                    D.month++;
                    D.day=29; 
                } 
                else if(D.year%4!=0)
                
                break;            
            }
            case 'c':
            {
                 add_day(D); 
                 
                 break;
            }
            default:
            cout<<"输入错误！\n";
        }
        
        
    }
    else
    {
       cout<<"您输入的日期格式错误！"<<endl;
    }
}

int Day(DATE D)//以公元2013年4月8日为基准，该日是星期一 
{//注意分为基准日之前和基准日之后两种情况讨论，用k值记录是之前还是之后！，两种不同！ 
     int i=0;
     int j=0;
     int k;
     DATE DD;
     DD.year=2013;
     DD.month=4;
     DD.day=8;
     if(D.year>=DD.year||(D.year==DD.year&&D.month>=DD.month)||(D.year==DD.year&&D.month==DD.month&&D.day>=DD.day))
     {
         k=1;
         for(i=0;;i++)
         {
         
             if(D.year==DD.year&&D.month==DD.month&&D.day==DD.day)
                break;
             add_day(DD);
         }
     }
     else
     {
         k=2;
         for(j=0;;j++)
         {
             add_day(D);
             if(D.year==DD.year&&D.month==DD.month&&D.day==DD.day)
                break;
              
         }
     }
     
     if(k==1)
     {
         i=i%7;
         if(i!=6)
         { 
            cout<<"该日是星期"<<i+1<<endl; 
            return i+1; 
         } 
         else
         {
            cout<<"该日是星期日"<<endl;
            return 7;
         }
     }
     else if(k==2)
     {
          j=j%7;
          if(j!=0)
          {
             cout<<"该日是星期"<<7-j<<endl;
             return 7-j;
          } 
          else
          {
              cout<<"该日是星期日"<<endl;
              return 7;
          }
     }
}

void Next_monday(DATE D)
{
     int i=Day(D);
     int j=0;
     for(j=0;j<8-i;j++)
     {
         add_day(D);
     }
     cout<<"接下来的星期一的日期为："<<D.year<<" "<<D.month<<" "<<D.day<<endl; 
}

int main()
{
    DATE D;
    Initial_Date(D);
    Input_Date(D);
    cout<<"输入1，判断日期是否正确;输入2，年或月或日加一;输入3，判断星期几;输入4，求该日后的星期一的日期"<<endl;
    char c;
    cin>>c; 
    switch(c)
    {
        case '1':
        {
             if(Judge_Date(D))
                 cout<<"您输入的日期格式正确\n";
             else
                 cout<<"您输入的日期格式有误\n";
             break;
         }
         case '2':
         {
              add(D);
              cout<<D.year<<" "<<D.month<<" "<<D.day<<endl;
              break;
         } 
         case '3':
         {
             Day(D);
             break;
         }
         case '4':
         {
              Next_monday(D);
              break;
         }
         
         default:
            cout<<"输入错误！"<<endl;
             
    } 
    
    
    system("pause");
    return 0;
} 
