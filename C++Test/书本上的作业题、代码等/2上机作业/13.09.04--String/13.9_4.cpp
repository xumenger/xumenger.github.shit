#include<iostream>
#include<cstring>
using namespace std;

template<class T>
class MyString
{
      struct Srep
      {
             T* s;
             int sz;
             int n;
             Srep(int nsz,const T* p)
             {
                      n=1;
                      sz=nsz;
                      s=new char[sz+1];
                      strcpy(s,p);
             }
             
             ~Srep()
             {
                    delete[] s;
             }
             
             Srep* get_own_copy()
             {
                   if(n==1)
                           return this;
                   n--;
                   return new Srep(sz,s);
             }
             
             void assign(int nsz,const T* p)
             {
                  if(sz!=nsz)
                  {
                             delete[] s;
                             sz=nsz;
                             s=new char[sz+1];
                  }
                  strcpy(s,p);
             }
      private:
              Srep(const Srep&);
              Srep& operator=(const Srep&);
      };
      
      Srep *rep;
public:
       class Cref
       {
             friend class MyString;
             MyString& s;
             int i;
             Cref(MyString& ss,int ii):s(ss),i(ii){}
       public:
              operator char() const
              {
                       return s.read(i);
              }
              void operator=(char c){s.write(i,c);}
       };
       
       class Range{};
       MyString();
       MyString(const T*);
       MyString(const MyString&);
       MyString& operator=(const T*);
       MyString& operator=(const MyString&);
       ~MyString();
       
       void check(int i)const
       {
            if(i<0||rep->sz<=i)
                               throw Range();
       }
       
       T read(int i)const
       {
                  return rep->s[i];
       }
       
       void write(int i,T c)
       {
            rep=rep->get_own_copy();
            rep->s[i]=c;
       }
       
       Cref operator[](int i)
       {
            check(i);
            return Cref(*this,i);
       }
       
       T operator[](int i)const
       {
             check(i);
             return rep->s[i];
       }
       
       int size() const
       {
           return rep->sz;
       }
       
       MyString& operator+=(const MyString&);
       MyString& operator+=(const T*);
       
       friend ostream& operator<<(ostream& os,const MyString& s)
       {
              os<<s.rep->s;
              return os;
       }
       friend istream& operator>>(istream& is,MyString& s)
       {
             is>>s.rep->s;
             return is;
       }
       
       friend bool operator==(const MyString& x,const T* s)
       {
              return strcmp(x.rep->s,s)==0;
       }
       friend bool operator==(const MyString& x,const MyString& y)
       {
              return strcmp(x.rep->s,y.rep->s)==0;
       }
       
       friend bool operator!=(const MyString& x,const T* s)
       {
              return strcmp(x.rep->s,s)!=0;
       }
       friend bool operator!=(const MyString& x,const MyString& y)
       {
              return strcmp(x.rep->s,y.rep->s)!=0;
       }
};
template<class T>
MyString<T> operator+(const MyString<T>& a,const MyString<T>& b)
{
            MyString<T> c;
            return c;
}

template<class T>
MyString<T> operator+(const MyString<T>&,const T*)//////////!!!!
{
            MyString<T> c;
            return c;
}

template<class T>
MyString<T>::MyString()
{
             rep=new Srep(0,"");
}
template<class T>
MyString<T>::MyString(const MyString& x)
{
             x.rep->n++;
             rep=x.rep;
}
template<class T>
MyString<T>::MyString(const T* s)
{
             rep=new Srep(strlen(s),s);
}
template<class T>
MyString<T>::~MyString()
{
             if(--rep->n==0)
                            delete rep;
}
template<class T>
MyString<T>& MyString<T>::operator=(const MyString& x)
{
          x.rep->n++;
          if(--rep->n==0)
                         delete rep;
          rep=x.rep;
          return *this;
}
template<class T>
MyString<T>& MyString<T>::operator=(const T* s)
{
             if(rep->n==1)
                          rep->assign(strlen(s),s);
             else 
             {
                  rep->n--;
                  rep=new Srep(strlen(s),s);
             }
             return *this;
}

//test 
int main()
{
    MyString<char>temp("Hello World!");
    cout<<temp<<endl;
    system("pause");
    return 0;
}














                         
             
             
             
             
             
             
             
                      
              
