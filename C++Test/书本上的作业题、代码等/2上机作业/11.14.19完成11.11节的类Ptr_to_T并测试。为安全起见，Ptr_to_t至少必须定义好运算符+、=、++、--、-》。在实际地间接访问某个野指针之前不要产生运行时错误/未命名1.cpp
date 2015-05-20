#include<iostream>
#include<locale>
using namespace std;

class out_of_bounds{
};

template<class T>//
class Ptr_to_T
{
      T* p;
      T* array; 
      int size;
      public:
             Ptr_to_T(T* p,T* array,int s);
             Ptr_to_T(T* p);
             
             Ptr_to_T<T>& operator++();//前缀++过载 
             Ptr_to_T<T> operator++(int);//后缀++过载
             
             Ptr_to_T<T>& operator--(); 
             Ptr_to_T<T> operator--(int);
             
             T& operator*(); 
};

template<class T>Ptr_to_T<T>::Ptr_to_T(T* p,T*v,int s)
{
    this->p=p;
    this->array=v;
    this->size=s;
}

template<class T>Ptr_to_T<T>::Ptr_to_T(T* p)
{
    this->p=p;
    this->array=p;
    this->size=1;
}

template<class T>Ptr_to_T<T>& Ptr_to_T<T>::operator++()
{
    ++p;
    return *this;
}

template<class T>Ptr_to_T<T> Ptr_to_T<T>::operator++(int)
{
    p++;
    return *this;
}

template<class T>Ptr_to_T<T>& Ptr_to_T<T>::operator--()
{
    --p;
    return *this;
}

template<class T>Ptr_to_T<T> Ptr_to_T<T>::operator--(int)
{
    p--;
    return *this;
}

template<class T>T& Ptr_to_T<T>::operator*()
{
    if(p<array||p>=array+size)
        throw out_of_bounds();//
    
    return *p;
}

int main()
{
    int v[200];
    Ptr_to_T<int> p(&v[0],v,200);
    p.operator--(0);
    
    try//
    {
         p.operator*()=0;
         cout<<p.operator*()<<endl; 
    } 
    
    catch(out_of_bounds)//
    {
        cerr<<"out_of_bounds"<<endl;
    }
    
    p.operator++();
    try
    {
        p.operator*()=1;
        cout<<p.operator*()<<endl;
    }
    
    catch(out_of_bounds)
    {
        cerr<<"out_of_bounds"<<endl;
    }
    
    
    system("pause");
    return 0;
}
