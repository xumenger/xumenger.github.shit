#include<cctype>
#include<iostream>
#include<cstring>
using namespace std;

class Expr 
{
public:
       enum CH{NUMBER,END,PLUS='+',MINUS='-',MUL='*',DIV='/' };
       Expr(const char*);
       enum CH;
       CH getexpr();
       int evaluate(bool);
       int term(bool);
       int primary(bool);
       void print(int b,int s);
private:
        CH getalpha;
        char str[100];
        int index,value;
};



Expr::Expr(const char*p)
{
    index=0;
    strcpy(str,p);
}
Expr::CH Expr::getexpr()
{
    switch(str[index])
    {
        case 0:
             return getalpha = END;
        case'0': case'1': case'2': case'3': case'4':
        case'5': case'6': case'7': case'8': case'9':
                 value=0;
                 while(str[index]>='0'&&str[index]<='9')
                 {
                     value*=10;
                     value+=str[index]-'0';
                     index++;
                 }
                 return getalpha=NUMBER;
        case'+': case'-': case'*': case'/':
                 return getalpha=(CH)str[index++];
        default:
                ;
    } 
} 
int Expr::evaluate(bool get)
{
    int left=term(get);
    for(;;)
    {
           switch(getalpha)
           {
               case PLUS:
                    left += term(true);
                    break;
               case MINUS:
                    left -= term(true);
               default:
                    return left;
           }
    }
}
int Expr::term(bool get)
{
    int left=primary(get);
    for(;;)
    {
        switch(getalpha)
        {
            case MUL:
                 left*=term(true);
                 break;
            case DIV:
                 left/=term(true);
             default:
                     return left;            
        }
    }
}
int Expr::primary(bool get)
{
    if(get)
        getexpr();
    switch(getalpha)
    {
        case NUMBER:
             {
                 int v=value;
                 getexpr();
                 return v;
             }
        case MINUS:
             return -primary(true);
    }
}
/*void Expr::print(int b,int s)
{
    int i,j,k;
    for(i=s;i>b;i--)
        if(str[i]=='+'||str[i]=='-')
            break;
    if(i>b)
    {
        cout<<"(";
        print(b,i-1);
        cout<<str[i];
        print(i+1,s);
        cout<<")";
    }
    else
    {
        for(j=s;j>b;j--)
            if(str[j]=='*'||str[j]=='/')
                break;
        if(j>b)
        {
            cout<<"(";
            print(b,j-1);
            cout<<str[i];
            print(j+1,s);
            cout<<")";
        }
        else
        {
            int ta=0;
            for(k=b;k<=s;k++)
            {
                if(str[k]=='-'&&k==0)
                {
                    cout<<"(";
                    ta=1;
                }
                cout<<str[k];
            }
            if(ta)
                cout<<")";
        }
    }
}
*/
void Expr::print(int b,int s)
{
     int i,j,k;
     for(i=s;i>b;i--)
          if(str[i]=='+'||str[i]=='-')
               break;
     if(i>b)
     {
            cout<<"(";
            print(b,i-1);
            cout<<str[i];
            print(i+1,s);
            cout<<")";
     }
     else
     {
         for(j=s;j>b;j--)
             if(str[j]=='*'||str[j]=='/')
                   break;
         if(j>b)
         {
                cout<<"(";
                print(b,j-1);
                cout<<str[j];
                print(j+1,s);
                cout<<")";
         }
         else
         {
                int ta=0;
                for(k=b;k<=s;k++)
                {
                     if(str[k]=='-'&&k==0)
                     {
                           cout<<"(";
                           ta=1;
                     }
                     cout<<str[k];
                }
                if(ta)
                      cout<<")";
         }
     }
}

int main()
{
    char s[80];
    
    while(cin>>s&&strcmp(s," "))
    {
        Expr x(s);
        cout<<"x="<<x.evaluate(true)<<endl;
        cout<<"´òÓ¡:"; 
        x.print(0,strlen(s)-1);
        cout<<endl;
    }
    
    system("pause");
    return 0;
}
