  #include<stdio.h>
  #include<stdlib.h>
  #include<string.h>
  #include<conio.h>
  #define M 2
  #define PAGE 3
  /*图书结构体类型*/
  typedef struct
  {int num;        /*图书号*/
   char name[20];      /*书名*/
   char zuozhe[20];    /*作者姓名*/
   char chubanshe[20]; /*出版社*/
   int price;      /*价格*/
  }BOOKS;
  

  int read_file(BOOKS books[])
     {  FILE *fp;
        int i=0;
        if((fp=fopen("project choose.txt","rt"))==NULL)
        { printf("\n\n*****库存文件不存在!请创建");
          return 0;
        }
        while(feof(fp)!=1)
        {  fread(&books[i],sizeof(BOOKS),1,fp);
           if(books[i].num==0)
              break;
           else
              i++;
        }
        fclose(fp);
        return i;
     }

  void save_file(BOOKS books[],int sum)
  {     FILE *fp;
      int i;
      if((fp=fopen("project choose.txt","wb"))==NULL)
      {   printf("读文件错误！\n");
          return;
      }
      for(i=0;i<sum;i++)
          if(fwrite(&books[i],sizeof(BOOKS),1,fp)!=1)
             printf("写文件错误！\n");
      fclose(fp);
}
  

 /*输入模块*/
   int input(BOOKS books[])
   {   int i=0;
       system("cls");
       printf("\n\n                   录入图书信息   (最多%d种)\n",M);
       printf("----------------------------------------------------\n");
       do
       {   printf("\n                       第%d本图书",i+1);
       printf("\n                图书编号：");
           scanf("%d",&books[i].num);                                                                                  if(books[i].num==0)  break;
       printf("\n                图书名称：");
           scanf("%s",books[i].name);
           printf("\n                作者：");
           scanf("%s",books[i].zuozhe);
           printf("\n                出版社：");
           scanf("%s",&books[i].chubanshe);
           printf("\n                图书价格：");
       scanf("%d",&books[i].price);
            i++;
       }while(i<M);
       fflush(stdin);
       getch(); 
       printf("\n                  --%d种图书信息输入完毕!--\n",i);
       printf("\n                     按任意键返回主菜单!");
       getchar();
       return i;
   }
   



    /*输出模块*/
    void output(BOOKS books[])
    {int i=0,j=0,page=1;
     system("cls");
     printf("\n\n            --图书信息表--                 第%d页\n\n",page);
     printf("图书编号----图书名称-----作者----- 出版社-----图书价格\n");
     printf("-------------------------------------------------------\n");
     do
      {   if(books[i].num!=0)
      {   j++;
          if(j%PAGE!=0)
          { printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price);
            printf("------------------------------------------------------\n");
          }
       else
          { printf("按任意键继续!");
            getchar();
            system("cls");
            printf("\n\n     --图书信息表--                 第%d页\n\n",++page);
            printf("图书编号--图书名称--作者-- 出版社--图书价格\n");
            printf("------------------------------------------\n");
            printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price);
            printf("---------------------------------------------\n");
           }
      }
        i++;
    }while(books[i].num!=0);
    printf("按任意键返回主菜单!");
    getchar( );
    }
    

  /*给定编号，作者，出版社查找信息模块*/
     void find_by_num(BOOKS books[],int sum)     
    { int i,find_num;
      
      system("cls");
      printf("\n               请输入要查找的图书编号:");
      fflush(stdin);
      scanf("%d",&find_num);
      
      for(i=0;i<sum;i++)
        if(books[i].num==find_num)       
        {
            printf("这是您所查找到的图书:\n");
            printf("图书编号----图书名称----作者---- 出版社---图书价格\n");
            printf("------------------------------------------\n");
            printf("%4d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                         books[i].zuozhe,  books[i].chubanshe,books[i].price);  
            printf("---------------------------------------------\n");
            break;
        }
          else
          {
            printf("\n       未找到要查找的图书信息，按任意键返回!");
            getchar();
            system("cls");    
          }
        
        fflush(stdin);
        getchar();
    }

    


    void find_by_zuozhe(BOOKS books[],int sum)
     { 
      int i;
       char find_zuozhe[20];
      
       system("cls");
       printf("\n               请输入要查找的作者姓名:");
       scanf("%s",find_zuozhe);
       for(i=0;i<sum-1;i++)
       fflush(stdin);
       getch();
       if(strcmp(books[i].zuozhe,find_zuozhe)==0)
       {printf("这是您所查找到属于该作者的图书:");
        printf("图书编号--图书名称--作者-- 出版社--图书价格\n");
        printf("------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
       }
       else
       {printf("\n       未找到要查找的图书信息，按任意键返回!");
        getchar();
        system("cls");    
       }
     }

 
    
    
      void find_by_chubanshe(BOOKS books[],int sum)
     { 
      int i;
       char find_chubanshe[20];
      
       system("cls");
       printf("\n               请输入要查找的出版社名称:");
       scanf("%s",find_chubanshe);
       for(i=0;i<sum;i++)
       fflush(stdin);
       getch();
      if(strcmp(books[i].chubanshe,find_chubanshe)==0)
        {printf("这是您所查找到属于该出版社的图书:");
         printf("图书编号--图书名称--作者-- 出版社--图书价格\n");
         printf("------------------------------------------\n");
         printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
         printf("---------------------------------------------\n");
        }
      else
       {printf("\n       未找到要查找的图书信息，按任意键返回!");
        getchar();
        system("cls");    
       }
     }

      void find(BOOKS books[],int sum)

    { int choice;
      system("cls");
      printf("\n     您要按照哪种方式查找?  \n");
      printf("\n      1.按图书编号查找  \n");
      printf("\n      2.按图书作者查找  \n");
      printf("\n      3.按出版社查找  \n");
      printf("\n      0. 退出\n");
      printf("\n       请选择(0-3):  \n");
      scanf("%d",&choice);
      switch(choice)  
      { case 1:     find_by_num(books,sum); break;
        case 2:     find_by_zuozhe(books,sum); break;
        case 3:     find_by_chubanshe(books,sum); break;
        case 0:                               break;
      }
     }  


       /*删除信息模块*/
       void del(BOOKS books[])
     { int i,g,sum;
       int del_num;
       
        { system("cls");
             printf("\n               请输入要删除的图书编号:");
             scanf("%d",&del_num);
             fflush(stdin);
             getch();
              
             for(i=0;i<sum;i++)
             if(books[i].num==del_num)
     g=i;
    for(g=i;g<sum;g++)
     books[g+1]=books[g];
    
             fflush(stdin);
             getch();
    {
             printf("这是您所要删除图书信息:\n");
             printf("图书编号----图书名称----作者---- 出版社----图书价格\n");
             printf("----------------------------------------------------\n");
             printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
             printf("-----------------------------------------------------\n");
             fflush(stdin);
             getch();
                                                      
             printf("您确认要删除吗?");
             printf("按任意键继续!");
             getchar();
    
             fflush(stdin);
             getch();
             printf("已成功删除图书信息!");
          }
          books[i].num=0;
        }
     }


      /*信息修改模块*/
     void modify(BOOKS books[],int sum)
     {int i=0,choice,modify_num,flag;
      do
      {system("cls");
       printf("请输入要修改的图书编号：");
       scanf("%d",&modify_num);
       for(i=0;i<sum;i++)
       if(books[i].num==modify_num)
       { printf("\n\n            --图书信息--                 \n\n");
         printf("图书编号----图书名称----作者---- 出版社----图书价格\n");
        printf("------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
         printf("\n                您要修改哪一项?\n");
         printf("\n                  1.图书名称\n");
         printf("\n                  2.作者\n");
         printf("\n                  3.出版社\n");
         printf("\n                  4.图书价格\n");
         printf("\n                 请选择(1-4):\n");
         scanf("%d",&choice);
         switch(choice)
         { case 1: printf("\n          请输入修改后的图书名称:");
                
                scanf("%s",books[i].name); break;   
           case 2: printf("\n          请输入修改后的作者姓名:");
                scanf("%s",books[i].zuozhe); break;   
           case 3: printf("\n          请输入修改后的出版社名称:");
                scanf("%s",books[i].chubanshe); break;   
           case 4: printf("\n          请输入修改后的图书价格:");
                scanf("%d",&books[i].price); break;   
         }
        fflush(stdin);
        getch();

        printf("\n\n            --图书信息--                 \n\n");
         printf("图书编号----图书名称----作者---- 出版社----图书价格\n");
        printf("--------------------------------------------\n");
        printf("%8d %10s %10s %10s %8d \n",books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
        printf("---------------------------------------------\n");
        break;
       }
       else
       {printf("\n          该书不存在!");
        getchar();
       }
       printf("\n    修改成功!\n");
       printf("您要继续修改吗?(Y/N)");
       if (choice=='Y'||choice=='y')
       { flag=1;
         printf("\n                     继续!\n");
        }
       else flag=0;
      }while( flag==1);
       fflush(stdin);
       getch();
       
       printf("\n     按任意键返回主菜单!");
       getchar();
      }
   


       /*图书信息统计模块*/

     
    
     
      void count(BOOKS books[],int sum)   /*统计某个出版社的图书数*/
      { int i;
       char count_chubanshe[20];
       int n=0;
       system("cls");     
       printf("请输入一个出版社名称:\n");
       fflush(stdin);
       scanf("%s",count_chubanshe);     
       for(i=0;i<sum;i++)
       {          
         if( strcmp(books[i].chubanshe,count_chubanshe)==0)
             n++;
         break;
       }
       fflush(stdin);
       
       printf("统计出属于该出版社一共有%d本书\n",n);
       getch();
     }


      





     /*排序模块*/
     void sort(BOOKS books[],int sum)   /*按图书编号排序模块*/
     {BOOKS t;
      int i,j,k;
      system("cls");  
      printf("\n            --图书信息--      \n");
      printf("\n 排名 图书编号     图书名称        作者         出版社  图书价格\n");
      
      for(i=0;i<sum-1;i++)
      { k=i;
        for(j=i+1;j<sum;j++)
           if(books[k].num>books[j].num)
    
           {t=books[j];
            books[j]=books[k];  
            books[k]=t;
           }
      }
      for(i=0;i<sum;i++)
      { printf("%2d  %8d %12s %12s %12s %6d \n",i+1,books[i].num,books[i].name,
                 books[i].zuozhe,  books[i].chubanshe,books[i].price); 
      }
      fflush(stdin);
      getch();
    }



       int main()
       { BOOKS books[M];
         int choice,sum;
         sum=read_file(books);
         if (sum==0)
         {printf("请录入基本图书信息!*******\n");
          getch();
          sum=input(books);
         }
        do
       { system("cls"); 
         printf("\n\n\n      *******图书馆理系统*******    \n\n");
         printf("                 1.修改图书信息 \n\n");
         printf("                 2.删除图书信息\n\n");
         printf("                 3.查找图书信息\n\n");
         printf("                 4.统计图书信息\n\n");
         printf("                 5.图书排行信息\n\n");
         printf("                 0.退出系统\n\n");
         printf("                  请选择\n\n");
         scanf("%d",&choice);
         switch(choice)
         {  case 1 :     modify(books,sum);    break;
            case 2 :     del(books);           break;
            case 3 :     find(books,sum);      break;
            case 4 :     count(books,sum);     break;
            case 5 :     sort(books,sum);      break;
            case 0 :                           break;
         }
       }while(choice!=0);
       save_file(books,sum);
       
       system("pause");
       return 0;

      }
