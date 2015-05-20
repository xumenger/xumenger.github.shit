#include<iostream>
#include<string>
using namespace std;

char *months_of_year[13]={"","January","February","Match",
"April","May","June","July","Auguest","September","October",
"November","December"}; 

int days_of_month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Months_and_days
{
    char *month;
    int day;
};
      
int main()
{
    Months_and_days array[13]={{"",0},{"January",31},{"February",28},{"Match",31},
    {"April",30},{"May",31},{"June",30},{"July",31},{"Auguest",31},{"September",30},
    {"October",31},{"November",30},{"December",31}};
    
    //Using a char array and an int array
    for(int i=1;i<13;i++)
    {
        cout<<months_of_year[i]<<"   "<<days_of_month[i]<<endl;
    
    }
    cout<<endl;
    
    //Using struct
    for(int j=1;j<13;j++)
    {
        cout<<array[j].month<<"    "<<array[j].day<<endl;
    
    }
    
    system("pause");
    return 0;
}
