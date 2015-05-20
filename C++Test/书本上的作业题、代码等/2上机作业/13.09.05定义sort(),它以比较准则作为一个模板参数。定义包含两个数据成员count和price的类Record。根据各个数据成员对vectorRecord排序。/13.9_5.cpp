#include<iostream>
#include<vector>
#include<cstddef>
using namespace std;

typedef int (*CFT)(const void*,const void*);

struct Record
{
       int count;
       double price;
       Record(int countt=12,double pricee=12.12):count(countt),price(pricee)
       {}
       friend ostream& operator<<(ostream& os,Record& record)
       {
              os<<record.count<<" "<<record.price;
              return os;
       }
};

double compare0(const void* p,const void* q)
{
    return static_cast<const Record*>(p)->count-static_cast<const Record*>(q)->count;
}

double compare1(const void* p,const void* q)
{
    return static_cast<const Record*>(p)->price-static_cast<const Record*>(q)->price;
}

//sort
template<class T,class X>void sort(vector<T>& v,X cmp)
{
       const size_t n=v.size();
       for(int gap=n/2;0<gap;gap/=2)
               for(int i=gap;i<n;i++)
                        for(int j=i-gap;0<=j;j-=gap)
                            if(cmp(&v[j+gap],&v[j])<0)
                            {
                                     T temp=v[j];
                                     v[j]=v[j+gap];
                                     v[j+gap]=temp;
                            }
                            
}
int main()
{
    vector<Record> x2(10);
    Record x3(2,20.4);
    Record x4(22,447.34);
    Record x5(2,44.67);
    Record x6(78,45.89);
    x2.push_back(x3);
    x2.push_back(x4);
    x2.push_back(x5);
    x2.push_back(x6);
    vector<Record>::iterator item=x2.begin();
    sort(x2,compare0);
    for(;item!=x2.end();item++)
          cout<<*item<<endl;
    cout<<endl;
    sort(x2,compare1);
    item=x2.begin();
    for(;item!=x2.end();item++)
          cout<<*item<<endl;
    system("pause");
    return 0;
}
    
                                                      
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
            
