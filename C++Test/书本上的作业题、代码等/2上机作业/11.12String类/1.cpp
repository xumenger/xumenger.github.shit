/**-----------------------------------------------------------------------------
*  String类的实现
*------------------------------------------------------------------------------
*/
#pragma once

#include<iostream>
#include<cstring>
#includ <cassert>

using namespace std;

inline void SafeRelease_Array( const char* s )
{
 if( s != NULL )
 {
  delete []s;
  s = NULL;
 }
};

class String
{
public:
 String(void);
 String( unsigned size );
 String( const char* );
 String( const String& ss );
 String( unsigned count, const char& ch );
 ~String(void);
protected:
 char* m_str;
 unsigned m_uCount;
public:
 // --  功能函数部分  -------------------      -==---------->>>
 void clear();
 unsigned size();
 bool empty();
 const char* c_str() const;
 void insert( unsigned , const char& );
 void insert( unsigned , const String& );
 void push_back( const char& );
 void push_front( const char& );
 bool erase( const unsigned& );
 bool erase( const unsigned&,const unsigned& );
 
 // --  重载操作符号  -------------------      o(∩_∩)o...哈哈 ---- >>>
 String& operator = ( const String& );
 String& operator += ( const String& );
 String operator + ( const String& );
 bool operator == ( const String& );
 bool operator < ( const String& );
 bool operator > ( const String& );
 // 取值
 char& operator []( unsigned n );
public:
 extern friend ostream& operator << ( ostream& os, const String& ss );
 extern friend istream& operator >> ( istream& is, String& ss );
};
/**-----------------------------------------------------------------------------
*  String类的实现
*------------------------------------------------------------------------------
*/
#include "String.h"

/**-----------------------------------------------------------------------------
*  默认构造函数
*------------------------------------------------------------------------------
*/
String::String(void):m_str(NULL),m_uCount(0)
{
}

/**-----------------------------------------------------------------------------
*  构造指定大小的对象
*------------------------------------------------------------------------------
*/
String::String( unsigned size ):m_str(NULL),m_uCount(size)
{
 if(size)
 {
  m_str = new char[ size ];
 }
}
/**-----------------------------------------------------------------------------
*  按const char* 构造
*------------------------------------------------------------------------------
*/
String::String( const char* str ):m_str(NULL)
{
 unsigned n = static_cast<unsigned>(strlen(str));
 m_uCount = n;
 if( n )
 {
  m_str = new char[ n ];
  strcpy_s( m_str,n+1 ,str );
 }
}

/**-----------------------------------------------------------------------------
*  拷贝构造函数
*------------------------------------------------------------------------------
*/
String::String( const String& ss ):m_str(NULL)
{
 m_uCount = ss.m_uCount;
 if( m_uCount )
 {
  m_str = new char[ m_uCount ];
  strcpy_s( m_str,m_uCount+1 ,ss.m_str );
 }
}
/**-----------------------------------------------------------------------------
*  用count个ch构造对象
*------------------------------------------------------------------------------
*/
String::String(unsigned int count, const char &ch):m_str(NULL),m_uCount(count)
{
 if( count )
 {
  m_str = new char[count];
  for(unsigned i = 0; i<count;i++)
  {
   *( m_str+i ) = ch;
  }  
  *( m_str + count ) = '\0';
 }
}
/**-----------------------------------------------------------------------------
*  析构函数  --==> 直接调用clear()函数清空
*------------------------------------------------------------------------------
*/
String::~String(void)
{
 clear();
}

/**-----------------------------------------------------------------------------
*  删除字符串 将大小置零
*------------------------------------------------------------------------------
*/
void String::clear()
{
 if( !m_str ) // = m_str != NULL
 {
  delete []m_str;
  m_str = NULL;
 }
 m_uCount = 0;
}

/**-----------------------------------------------------------------------------
*  返回大小
*------------------------------------------------------------------------------
*/
unsigned String::size()
{
 return m_uCount;
}

/**-----------------------------------------------------------------------------
*  判断是否为空
*------------------------------------------------------------------------------
*/
bool String::empty()
{
 return !m_uCount;
}

/**-----------------------------------------------------------------------------
*  转换
*------------------------------------------------------------------------------
*/
const char* String::c_str() const
{
 return m_str;
}

/**-----------------------------------------------------------------------------
*  插入字符char
*------------------------------------------------------------------------------
*/
void String::insert( unsigned pos, const char& ch )
{
 assert( pos <= m_uCount );

 char* t = new char[m_uCount]; // 先暂时将原有字符串放在临时对象中
 strcpy_s( t,m_uCount+1,m_str ); 

 m_str = new char[m_uCount +2]; // 重新分配内存

 strncpy_s(m_str,m_uCount+2,t,pos);  //将前t个字符复制到数组中

 *(m_str+pos) = ch;  // 插入值

 *(m_str+pos+1) = '\0';
 /*strcat_s(m_str,m_uCount+2,tmp+pos);*/
 strncat_s(m_str,m_uCount+2,t,m_uCount - pos );

 m_uCount++;

 /*SafeRelease_Array(t);*/  //--==>>一个为解决的bug
}
/**-----------------------------------------------------------------------------
*  插入string
*------------------------------------------------------------------------------
*/
void String::insert( unsigned pos, const String& ss )
{
 assert( pos <= m_uCount );

 char* t1 = new char[ pos +1 ];
 strncpy_s(t1,pos+1,m_str,pos);

 char* t2 = new char[ m_uCount - pos + 1 ];
 strncpy_s(t2,m_uCount-pos+1,m_str+pos,m_uCount - pos );
 
 m_str = new char[m_uCount + ss.m_uCount + 1];
 strcpy_s(m_str,pos+1,t1);
 SafeRelease_Array( t1 );

 strcat_s(m_str,ss.m_uCount + m_uCount + 1,ss.m_str);
 strcat_s(m_str,ss.m_uCount + m_uCount + 1,t2 );
 m_uCount += ss.m_uCount;

 SafeRelease_Array( t2 );
}
/**-----------------------------------------------------------------------------
*  push_back
*------------------------------------------------------------------------------
*/
void String::push_back( const char& ch )
{
 insert( m_uCount, ch );
}

/**-----------------------------------------------------------------------------
*  push_front
*------------------------------------------------------------------------------
*/
void String::push_front( const char& ch )
{
 insert( 0, ch );
}
/**-----------------------------------------------------------------------------
*  删除单个位置
*------------------------------------------------------------------------------
*/
bool String::erase( const unsigned& pos )
{
 /*assert( pos < m_uCount );*/
 if( pos >= m_uCount )
 {
  return false;
 }
 char* t = new char[m_uCount+1];
 strcpy_s(t,m_uCount+1,m_str);
 
 SafeRelease_Array(m_str);

 m_str = new char[m_uCount];
 strncpy_s(m_str,m_uCount,t,pos);
 strncat_s(m_str,m_uCount,t+pos+1,m_uCount-pos-1);
 
 m_uCount--;
 SafeRelease_Array( t );

 return true;
}

/**-----------------------------------------------------------------------------
*  删除连续位置
*------------------------------------------------------------------------------
*/
bool String::erase( const unsigned& begin,const unsigned& end ) // 注意，区间是闭区间，和string类不同，string类是[ )半开半闭区间
{
 assert( begin <= end );
 if(end>=m_uCount)
  return false;
 if( begin == end )
 {
  erase( begin );
 }
 else
 {
  unsigned gap = end - begin;
  char* t = new char[m_uCount+1];
  strcpy_s(t,m_uCount+1,m_str);
  SafeRelease_Array(m_str);
  int size = m_uCount - gap;
  m_str = new char[size];
  strncpy_s(m_str,size,t,begin);
  strncat_s(m_str,size,t+end+1,size - end-1);

  m_uCount -= (gap+1);

  SafeRelease_Array( t );
 }
 
 return true;
}

/**-----------------------------------------------------------------------------
*  重载 = 
*------------------------------------------------------------------------------
*/
String& String::operator = ( const String& ss )
{
 clear();
 unsigned n = ss.m_uCount;
 if( n )
 {
  m_str = new char[ n + 1 ];
  strcpy_s( m_str,n+1,ss.m_str );
  m_uCount = ss.m_uCount;
 }
 
 return *this;
}
/**-----------------------------------------------------------------------------
*  重载+=
*------------------------------------------------------------------------------
*/
String& String::operator += ( const String& ss )
{
 // 这里有一个小bug,如果自己+自己就会崩溃，如： ss += ss; 修改后问题解决
 //if( ss.m_uCount )
 //{
 // char* tmp = new char[ m_uCount + 1 ];
 // strcpy_s(tmp,m_uCount+1,m_str);

 // delete []m_str;
 // m_str = new char[ m_uCount + ss.m_uCount + 1];
 // strcpy_s( m_str,m_uCount+1,tmp );
 // delete []tmp;
 // strcat_s( m_str,m_uCount+ss.m_uCount+1,ss.m_str );

 // m_uCount += ss.m_uCount;
 //}
 if( ss.m_uCount )
 {
  String temp1(*this);
  String temp2(ss);
  m_uCount += ss.m_uCount;

  delete []m_str;
  m_str = new char[ m_uCount + 1 ];
  strcpy_s( m_str,temp1.m_uCount+1,temp1.m_str );
  strcat_s( m_str,m_uCount + 1,temp2.m_str );  
 }

 return *this;
}
/**-----------------------------------------------------------------------------
*  重载 +
*------------------------------------------------------------------------------
*/
String String::operator + ( const String& ss )
{
 if( !ss.m_uCount )  // 如果ss为空则直接返回
 {
  return *this;
 }
 else  // 充分利用已经存在的+=，^_^   。。。
 {
  String temp(*this);
  temp += ss;

  return temp;
 }
}
/**-----------------------------------------------------------------------------
*  重载 ==
*------------------------------------------------------------------------------
*/
bool String::operator == ( const String& ss )
{
 if( !strcmp( m_str,ss.m_str ) )
 {
  return true;
 }
 else
  return false;
 //貌似这样有个警告：
 //warning C4800: “int”: 将值强制为布尔值“true”或“false”(性能警告)
 /*return !static_cast<bool>( strcmp( m_str,ss.m_str ) );*/
}

/**-----------------------------------------------------------------------------
*  重载 <
*------------------------------------------------------------------------------
*/
bool String::operator < ( const String& ss )
{
 int mark = strcmp( m_str,ss.m_str );
 if( mark < 0 )
  return true;
 else
  return false;
}

/**-----------------------------------------------------------------------------
*  重载 >
*------------------------------------------------------------------------------
*/
bool String::operator > ( const String& ss )
{
 // 下面这样是不严密的。。。
 //return !( *this < ss );
 int mark = strcmp( m_str,ss.m_str );
 if( mark > 0 )
  return true;
 else
  return false;
}

/**-----------------------------------------------------------------------------
*  取值 重载[]
*------------------------------------------------------------------------------
*/
char& String::operator [] ( unsigned n )
{
 assert( n < m_uCount );

 return *(m_str+n);
}
/**-----------------------------------------------------------------------------
*  重载输出运算符
*------------------------------------------------------------------------------
*/
ostream& operator << ( ostream& os, const String& ss )
{
 os<<ss.m_str;

 return os;
}
/**-----------------------------------------------------------------------------
*  重载输入运算符
*------------------------------------------------------------------------------
*/
istream& operator >> ( istream& is, String& ss )  // 输入时请勿包含空格
{
 ss.clear();
 is>>ss.m_str;

 ss.m_uCount = static_cast<unsigned>(strlen( ss.m_str ));

 return is;
}
