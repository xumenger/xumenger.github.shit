#include<iostream>
#include<memory>
using namespace std;

class Histogram
{
    private:
        int minval,maxval;
        int gap;
        int * bin;
        int n_too_small,n_too_large;
     public:
        Histogram(int minval,int gap,int n);
        ~Histogram(){delete[] bin;}
        void record(int);
        void output();  
};

Histogram::Histogram(int minval,int gap,int n)
{
    this->minval=minval;
    this->gap=gap;
    this->maxval=maxval+n*gap-1;
    this->bin=new int[n];
    if(!bin)
    {
        cerr<<"error"<<endl;
        exit(1);
        
    }
    memset(bin,0,sizeof(int)*n);
    this->n_too_large=this->n_too_small=0;
}

void Histogram::record(int t)
{
    if(t<minval)
        n_too_small++;
    else if(t>maxval)
        n_too_large++;
    else
        ++bin[(t-minval)/gap];
}

void Histogram::output()
{
    cout<<"the number which<"<<"is:"<<n_too_small<<endl;
    for(int left=minval;left<maxval;left+=gap)
        cout<<left<<"......"<<left+gap<<":"<<bin[(left-minval)/gap]<<endl;
         
}

int main()
{
    Histogram ht(0,2,4);
    for(int i=-1;i<11;i+=2)
        ht.record(i);
    
    ht.output();
    
    system("pause");
    return 0;
}
