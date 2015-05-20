#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Books//用栈存储图书信息 
{
    int num;//编号 
    char location[50];
    char name[50];//书名 
    char writer[50];//图书作者 
    char ISBN[50];//ISBN号 
    char press[50];//图书出版社 
    int borrow_or_not;//记录图书是否被借出，只能赋值为"1"表示已借出   和"0"表示未借出  
    float price;   //价格 
    struct Books *next;
};

struct Users//用栈存储用户信息 
{
    char ID[20];//用户编号 
    char name[20];//用户名 
    char contact[20];//联系方式 
    int amount;//借的书的数量
    int b_amount;//借了但未还的书的数量 
    struct Users *next;
};

struct BookList 
{
    struct Books *tail;
    int totalBooks;
    struct Books *head;
};

struct UserList
{
    struct Users *tail;
    int totalUsers;
    struct Users *head;
};

void write_in(FILE *,struct BookList,struct Books *);
void search_by_location(struct Books *,char []);  
void search_by_name(struct Books *,char []);
void search_by_writer(struct Books *,char []);
void search_by_ISBN(struct Books *,char []);
void search_by_press(struct Books *,char []);
void Search(struct Books *);
//注意函数原型的形式
void return_book(struct BookList,struct Books *,FILE *,struct UserList,struct Users *,FILE *); 
void Delete(struct BookList,struct Books *);
void borrow_book(struct UserList,struct Users *,struct BookList,struct Books *,FILE *,FILE *);
void login(FILE *,struct Users*,struct UserList); 
void search_user(struct Users *,struct UserList);
int test_ID(char ID[]); 

int main()
{
    
    FILE *fp,*fpp;;
    fp=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\books.dat","r+");
    fpp=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\users.dat","r+");
    if(fp==NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    if(fpp==NULL)
    {
        printf("文件打开失败！\n");
        exit(0);
    }
    
    struct Books *books;
    struct BookList link;
    struct Users *users;
    struct UserList linkk;
    
    link.head=NULL;
    linkk.head=NULL;
    link.tail=NULL;
    linkk.tail=NULL;
    link.totalBooks=linkk.totalUsers=0;
    
    int i,j;
    while(1)
    {
        books=new Books;
        
//fscanf(fp,"%d%s%s%s%s%s%d%f",&books->num,books->location,books->name,books->writer,books->ISBN,books->press,&books->borrow_or_not,&books->price);                     
        
        if(fscanf(fp,"%d%s%s%s%s%s%d%f",&books->num,books->location,books->name,books->writer,books->ISBN,books->press,&books->borrow_or_not,&books->price)==EOF)
        {
//本if语句中的fscanf既完成了判断，又实现了读取信息的功能，所以就
//没必要再在上面写一个scanf了，重复了！！！ 
            delete books;
            break;
        }
//这个if判断句很重要，我第一次没写这个，就出现编译错误！！ 
        books->next=NULL;
        
        if(link.tail==NULL)
            link.head=link.tail=books;
        else
        {
            link.tail->next=books;
            link.tail=books;
        }
//注意if和else语句，注意向链表中添加结点时，若原来链表中已有结点，与原来链表中无结点的区别 
        link.totalBooks++;
    }
    
    while(1)
    {
        users=new Users;               
        
        if(fscanf(fpp,"%s%s%s%d%d",users->ID,users->name,users->contact,&users->amount,&users->b_amount)==EOF)
        {
            delete users;
            break;
        }
        users->next=NULL;
        
        if(linkk.tail==NULL)
            linkk.head=linkk.tail=users;
        else
        {
            linkk.tail->next=users;
            linkk.tail=users;
        }
        linkk.totalUsers++;
    }
    
       
    
    while(1)
//通过while(1)的语句，可以实现再完成一项功能后，用户可以继续选择，而不是程序自动退出！！！ 
    {
        users=linkk.head;
        books=link.head;
//这句books=link.head千万不能忘，使指针指向表头，否则底下的search_by_的各个函数无法使用;users同                                                                                     
    
        printf("          *******************************************************\n");
        printf("          *******************************************************\n");
        printf("          **1.查询图书(通过位置、书名、作者、ISBN号、出版社)   **\n");
        printf("          **2.录入新的图书信息                                 **\n");
        printf("          **3.借书                                             **\n");
        printf("          **4.还书                                             **\n");
        printf("          **5.查询你的借书情况                                 **\n");
        printf("          **6.注册新用户                                       **\n");
        printf("          **0退出程序                                          **\n");
        printf("          *******************************************************\n");
        printf("          *******************************************************\n");
    
        printf("\n输入对应序号选择对应的功能:");
    
        scanf("%d",&j);
 


        if(j==1)
        {
            Search(books);
            printf("\n请您继续\n\n");
        }   
        
        else if(j==2)
        { 
            write_in(fp,link,books);
            printf("\n请您继续\n\n"); 
        } 
        
        else if(j==3)
        {
             fclose(fp);
             fclose(fpp);
//因为借书的函数中会再打开文件进行操作，所以这里最好是先把主函数中打开的文件给关闭，下面的调用return_book函数也一样！！！
//对于文件的操作一定要规范 
             borrow_book(linkk,users,link,books,fp,fpp);
             printf("\n请您继续\n\n"); 
        }
        else if(j==4)
        {
             fclose(fp);
             fclose(fpp);
             return_book(link,books,fp,linkk,users,fpp);
             printf("\n请您继续\n\n");
        }
        
        else if(j==5)
        {
             search_user(users,linkk);
             printf("\n请您继续\n\n");
        }
        
        else if(j==6)
        {
             login(fpp,users,linkk);
             printf("\n请您继续\n\n");
        }
           
        else if(j==0)
            break;  
//这里最好使用if语句，因为要通过break来实现退出程序，而如果用switch语句，因为case要含有自己的break，最后不能实现推出的功能，也不知到底为什么          
        else
            printf("\n对不起，输入错误\n请您继续\n\n");
    }   
    
    Delete(link,books);//程序结束后删除链表信息 
    
    fclose(fp);
    fclose(fpp);
//最后若对文件操作完成了之后，一定要关闭文件！！！！ 
              
    system("pause");
    return 0; 
} 


void write_in(FILE *file,struct BookList link,struct Books *book)//实现写入功能 
{
     printf("按顺序依次输入书的序号(int)、位置(string)、书名(string)、作者(string)、ISBN号(string)、出版社(string)、书是否被借出的情况(赋值为1表示已借出   和0表示未借出 )、价格(float)\n");
     printf("当输入的书的价格为负数时则停止输入！！\n");
     while(1)
     {
         book=new Books; 
          
         scanf("%d%s%s%s%s%s%d%f",&book->num,book->location,book->name,book->writer,book->ISBN,book->press,&book->borrow_or_not,&book->price);
         if(book->price>0)
         {
             fprintf(file,"\n%d   %s     %s      %s      %s      %s     %d     %f",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);
     
             book->next=NULL;
         }
         else
         {
            delete book;
            break;
         }
         if(link.tail==NULL)
            link.head=link.tail=book;
         else
         {
            link.tail->next=book;
            link.tail=book;
         }
         
         
      }
      printf("录入成功！！\n");
} 
//注意其中if语句的使用适当输入书的价格为负数时，停止输入，同时又不把价格为负数的书的信息写到文件中！！ 



void search_by_location(struct Books *book,char locations[])//通过输入的书的位置寻找  
{
     int t1=0;
//通过定义 t1以及下面对t1的相关操作，可以实现：在未查到与输入信息相关的书时，输出对用户的提醒语句
//下面的t2、t3、t4、t5是同样的道理
//第一次没有考虑到“无书与输入信息对应”的情况，犯了错！！！！ 
//这是一个很好的技巧！！！！！ 
     while(book!=NULL)
     {
           
          if(strcmp(book->location,locations)==0)  
          {
              printf("%d   %s   %s   %s   %s   %s    %d   %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);         
              t1++;
          }
          book=book->next;       
     }
     if(t1==0)
        printf("对不起，没有相关书籍！！\n");
}

void search_by_name(struct Books *book,char names[])//通过输入的书的名称寻找 
{      
     int t2=0;
     while(book!=NULL)
     {
           
          if(strcmp(book->name,names)==0) 
          { 
              printf("%d   %s   %s   %s   %s    %s    %d   %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);         
              t2++;
          }
          book=book->next;       
     }
     if(t2==0)
        printf("对不起，没有相关书籍！！\n");
}

void search_by_writer(struct Books *book,char writers[])//通过输入的书的作者寻找 
{ 
     int t3=0;
     while(book!=NULL)
     {
          
          if(strcmp(book->writer,writers)==0) 
          { 
              printf("%d   %s   %s   %s   %s   %s    %d   %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);         
              t3++;
          }
          book=book->next;       
     }
     if(t3==0)
        printf("对不起，没有相关书籍！！\n");
} 

void search_by_ISBN(struct Books *book,char ISBNs[])//通过输入的书的ISBN号寻找 
{
     int t4=0;
     while(book!=NULL)
     {
           
          if(strcmp(book->ISBN,ISBNs)==0)
          {  
              printf("%d   %s   %s   %s   %s   %s    %d    %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);   
              t4++;
          }      
          book=book->next;       
     }
     if(t4==0)
        printf("对不起，没有相关书籍！！\n");
}

void search_by_press(struct Books *book,char presss[])//通过输入的书的出版社寻找 
{ 
     int t5=0;
     while(book!=NULL)
     {
          
          if(strcmp(book->press,presss)==0)  
          {
              printf("%d   %s   %s   %s   %s   %s    %d    %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);         
              t5++;
          }
          book=book->next;       
     }
     if(t5==0)
        printf("对不起，没有相关书籍！！\n");
}

void Search(struct Books *book)
{
     
     char location1[50];
     char name1[50];
     char writer1[50];
     char ISBN1[50];
     char press1[50];
     int c; 
     
     printf("\n");
     printf("***********************1.按位置搜索\n");
     printf("***********************2.按书名搜索\n");
     printf("***********************3.按作者姓名搜索\n");
     printf("***********************4.按ISBN号搜索\n");
     printf("***********************5.按出版社搜索\n");
     
     printf("\n***********************输入对应序号选择对应的功能:");
     
     scanf("%d",&c);
//和上边的main函数里一样这里我也忘了写输入语句scanf ，犯了个大错 
     printf("\n"); 
     
     if(c==1)
     {
         printf("***********************请输入要查的书的位置：");
         scanf("%s",location1);
         search_by_location(book,location1);
     }    
     else if(c==2)
     {
         printf("***********************请输入要查的书的名称：");
         scanf("%s",name1);
         search_by_name(book,name1);
     }  
     else if(c==3)
     {
         printf("***********************请输入要查的书的作者：");
         scanf("%s",writer1);
         search_by_writer(book,writer1);
     }
     else if(c==4)
     {
         printf("***********************请输入要查的书的ISBN号：");
         scanf("%s",ISBN1);
         search_by_ISBN(book,ISBN1);
     }
     else if(c==5)
     {
         printf("***********************请输入要查的书的出版社：");
         scanf("%s",press1);
         search_by_press(book,press1);
     }
     else
         printf("\n对不起，输入错误，请重新开始\n");
     
}

//为什么若要把c定义为char型，输入'a'，'b'，'c'等这样的字符，其他不变就不能正常运行 ？
//而如果把c定义为int型，输入数字1,2,3等就可以运行了，为什么？ 

void Delete(struct BookList link,struct Books *book)//最后要删除链表结点占用的空间，不删也不影响其他功能的实现，但不是一个好习惯，可能时间长了，程序出现问题！！！ 
{
     while(link.head!=NULL)
     {
         book=link.head;
         link.head=book->next;
         delete book;
     }
}

void return_book(struct BookList link,struct Books *book,FILE *file,struct UserList linkk,struct Users *user,FILE *file2)//实现还书，并更改文件中关于图书是否借出的信息，以及更改用户借书的数量的信息 
{
     char IDs[20];
     printf("请输入你的学号：");
     scanf("%s",IDs);
 
     int t9=0;
     int ii=0;
     int i9;
     while(user!=NULL)
     {
          
          if(strcmp(user->ID,IDs)==0)  
          {     
              t9++; 
//t9放在 if(user->b_amount==0){}的前面，可以保证若执行该if里面的语句，包含break，可以先完成对t9++的操作，进行记录。
//若放在 if(user->b_amount==0){}后面，执行了该if语句，但因为有break，则不会执行t9++，那么再下面的就不会与真实情况匹配。会出错 
              if(user->b_amount==0)
              {
                 ii++;
//通过对ii的操作，结合else if(t9!=0&&ii!=0){}的语句处理，可以解决在“用户存在，但没有未还的书”的情况时提醒用户，并不再需要下面的还书操作                 
                 break;
              }  
              
              break;
          }
          user=user->next;       
     }
         
     if(t9==0)
     {
         printf("对不起，你的学号有误！！\n");   
     }
     else if(t9!=0&&ii!=0)
     {
         printf("你已归还所有图书，不需再进行还书操作！\n"); 
     }
     else 
     {
         char ISBN2[50];
         printf("请输入要还的书的ISBN号：");
         scanf("%s",ISBN2);
         book=link.head;
         int tt=0; 
         while(book!=NULL)
         {
           
              if(strcmp(book->ISBN,ISBN2)==0)
              {
                  if(book->borrow_or_not==1)
                  {
                        book->borrow_or_not=0;
                        printf("还书成功！\n");
                        i9=1;
                  }
                  else
                     printf("对不起，输入有误，该书未被借出过\n");
                  tt++; 
              }
              book=book->next;       
         }
     
         if(tt==0)
            printf("对不起，输入有误，无对应的书\n");
        
         file=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\books.dat","w");
         file2=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\users.dat","w");
//已以写的方式打开已经存的文件相当于是清空，再加上下面再重新写入数据，就相当于把还书后图书的信息给改了
//不知还有没有其他方法来更改文件中的数据 
         if(file==NULL)
         {
            printf("文件打开失败！\n");
            exit(0);
         }
         if(file2==NULL)
         {
            printf("文件打开失败！\n");
            exit(0);
         }
     
         book=link.head;
         while(book!=NULL)
         {
         
          
         
             fprintf(file,"%d   %s    %s      %s      %s      %s      %d      %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);
     
             book=book->next;
         
        
         }
     
         user=linkk.head;
         if(i9==1)
         {
             while(user!=NULL)
             {
          
                if(strcmp(user->ID,IDs)==0)  
                {      
                    if(user->b_amount>0)
                        user->b_amount--;
                    else
                        printf("你未曾借出过书，不需要还！\n"); 
                }
                user=user->next;       
              }
         }
     
         user=linkk.head;
         while(user!=NULL)
         {
         
          
         
             fprintf(file2,"%s               %s                 %s                 %d             %d\n",user->ID,user->name,user->contact,user->amount,user->b_amount);
     
             user=user->next;
         
        
         }   
     
     
     
    }

     
}

void borrow_book(struct UserList linkk,struct Users *user,struct BookList link,struct Books *book,FILE *file1,FILE *file2)
{
     char IDs[20];
     char ISBN2[50];
     printf("请输入你的学号：");
     scanf("%s",IDs);
     int t7=0;
     while(user!=NULL)
     {
          
          if(strcmp(user->ID,IDs)==0)  
          {      
              t7++;
              break;
          }
          user=user->next;       
     }
     if(t7==0)
     {
         printf("对不起，你的学号有误！！\n");   
     }
     else 
     {
         printf("\n登陆成功!\n"); 
         printf("请你搜索你要找的书\n");
         Search(book);
         printf("请跟据你搜索的情况，输入你要借的书的ISBN号：");
         scanf("%s",ISBN2);
         
         book=link.head;
         int t8=0;
         while(book!=NULL)
         {
           
             if(strcmp(book->ISBN,ISBN2)==0)
             {  
                  t8++;
                  if(book->borrow_or_not==1)
                      printf("对不起，本书已经借出，请你选择其他书\n");
                  else
                  {
                      book->borrow_or_not=1;
                      user->amount++;
                      user->b_amount++;
                      printf("已完成借书，请你继续选择其他功能\n");
                      break;  
                  }
                  
             }      
             book=book->next;       
         }
         if(t8==0)
            printf("对不起，没有相关书籍！！\n");
     }
        
        
     file1=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\books.dat","w");
     if(file1==NULL)
     {
        printf("文件打开失败！\n");
        exit(0);
     }
     book=link.head;
     while(book!=NULL)
     {
         
          
         
         fprintf(file1,"%d   %s    %s      %s      %s      %s      %d      %f\n",book->num,book->location,book->name,book->writer,book->ISBN,book->press,book->borrow_or_not,book->price);
     
         book=book->next;
     }
     
     
        
     file2=fopen("G:\\代码尽快弄懂\\自己做的--图书管理系统程序设计基础实训文档及程序\\文档及程序\\users.dat","w");
     if(file2==NULL)
     {
        printf("文件打开失败！\n");
        exit(0);
     }
     user=linkk.head;
     while(user!=NULL)
     {
         
          
         
         fprintf(file2,"%s               %s                 %s                 %d             %d\n",user->ID,user->name,user->contact,user->amount,user->b_amount);
     
         user=user->next;
         
        
     }   
}

void login(FILE *file,struct Users *user,struct UserList linkk)//注册新用户的功能 ，当输入的学号已存在时，程序会输出提醒 
{
    char IDs[20]; 
    printf("请输入你的学号：");
    scanf("%s",IDs);
    if(test_ID(IDs)==0)
        printf("学号格式不正确\n");
      
    else
   {   
       int i7=0; 
       while(user!=NULL)
       { 
           if(strcmp(user->ID,IDs)==0)
           {
               printf("对不起，该学号已存在！！\n");
               i7++;  
               break;
           }
           user=user->next; 
      } 
    
      if(i7==0)
      {     
          user=new Users; 
          strcpy(user->ID,IDs);
//strcpy(s1,s2)是把s2的值赋值到s1上    
          printf("请输入你的名字、联系方式："); 
          scanf("%s%s",user->name,user->contact);
    
          fprintf(file,"\n%s          %s          %s         0         0",user->ID,user->name,user->contact,user->amount,user->b_amount);
          user->next=NULL;
          if(linkk.tail==NULL)
              linkk.head=linkk.tail=user;
          else
          {
              linkk.tail->next=user;
              linkk.tail=user;
          }
          printf("录入成功！\n");
      }
  }

}

void search_user(struct Users *user,struct UserList linkk)//搜索用户借书情况
{
     int i2=0;
     char ID2[50]; 
     printf("请输入你的学号：");
     scanf("%s",ID2);
     while(user!=NULL)
     {
         if(strcmp(user->ID,ID2)==0)
         printf("共借了%d本书，还有%d本未还！\n",user->amount,user->b_amount);  
         i2++; 
         break;
     } 
     if(i2==0)
         printf("对不起，没有你的相关信息！\n");
} 


int test_ID(char ID[])//检验学号形式是否合格 
{
     int i;
     int t=0;
     int n=strlen(ID);
     for(i=0;i<n;i++)
     {
         if(ID[i]-'0'<=0||ID[i]-'0'>=9)
            t++;
     }
     if(t==0)
         return 1;//t==0即 上面ID中有些元素都是数字，此时输入合格
     else 
        return 0;// t!=0即 上面ID中有些元素不是数字 ，此时输入不合格 
}
