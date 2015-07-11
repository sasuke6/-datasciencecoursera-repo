#include <stdio.h> //输入输出函数
 #include <stdlib.h> //定义杂项函数及内存分配函数
 #include <string.h>//字符串处理 
#include <conio.h> //C语言图形函数
#define LEN sizeof(struct teacher)  //宏定义,在以后出现LEN的地方，用teacher这个结构体所占的字节数代替，这个字节数是一个整数
struct teacher 
 {  int num;
  char name[20]; 
 char sex[20]; 
 char workplace[50]; //学院
 char teacher_ident; //教师职称
 char address[50]; 
 long phone;  
double de_salary; //基本工资
 double de_jintie; //津贴
 double de_shenghuobutie; //生活补贴
 double yingfa_salary; //应发工资
 double cost_phone; //电话费
 double cost_water_elec;//水电费
  double cost_rent; // 房租
double cost_tax;//车费
  double cost_weisheng; // 卫生费
double cost_gongjijin; //公积金 
double cost_all; //合计扣款
 double shifa_salary;//实发工资
  struct teacher *next; 
};    
/*********************************读取函数************************************/
 struct teacher *load() 
{  struct teacher *p1,*p2,*head; 
 FILE *fp; 
 int i=1; 
 if((fp=fopen("save","rb"))==NULL)//判断以读二进制的方式打开文件save，文件句柄保存到fp，fp是否为空,如果为空，就是打开文件失败，否则打开文件成功
  { 
  printf("             文件不存在！按下任意键返回主菜单...");
getch();  
 return (NULL); 
 }
  else 
 {   head=NULL; 
  p1=(struct teacher *)malloc(LEN);
   while (fread(p1,LEN-4,1,fp)==1)  
 {    if(i==1)   
 {     head=p1;
     p2=p1;    
 i=2;   
 }   
 else  
   {  
   p2->next=p1;    
 p2=p2->next;  
  }  
  p1=(struct teacher *)malloc(LEN);  
 }  
 p2->next=NULL;  
 free(p1); 
 fclose(fp);  
 return(head);
  }
 }   

void deletes()
 {  
struct teacher *head,*p1,*p2,*p3; 
 int i; 
 char k;
  FILE *fp;
  char n='n'; 
 p1=p2=p3=(struct teacher *)malloc(LEN); 
 if((head=load())!=NULL)  
{  
 do  
 {  
  int num;   
 char name[20]; 
   p1=head;   
 system("cls");  
  printf("\n\n\n                       >>>>>>>>>>> 删除教师信息 <<<<<<<<<<<\n"); 
  printf("             *******************************************************\n");   
 printf("             *                     1.输入教师号                    *\n");  
  printf("             *                     2.输入姓名                      *\n");  
  printf("             *                     3.返回上级菜单                  *\n");  
  printf("             *******************************************************\n");   
 printf("             请选择删除方式：");   
 scanf("%d",&i);
getchar();  
  while (i<1||i>3)  
  {     
printf("             输入有误!请重新输入:"); 
scanf("%d",&i);
getchar();  
  }    
switch(i)   
 {    
    case 1:printf("             请输入要删除的信息的教师号：");     
scanf("%d",&num);getchar();     
while (p1->num!=num)   
  {    
  if (p1->next!=NULL)     
  p1=p1->next;  
    else  
     {      
 printf("             查找不到相关数据!\n");    
   break;   
   }   
  }   
  if (p1->num==num)  
   {    
  printf("-----------------------------要删除的信息如下：--------------------------------\n");  
    printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");  
    printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");  
   printf("             确定删除吗？（y或n）:");   
   scanf("%c",&k);
getchar();    
 } 
if (k=='y'||k=='Y')   
  { 
if (p1->num==num) 
    {      if(p1==head)   
   {    
   p1=p1->next;   
    p2=p1;   
   }    
  else if(p1->next==NULL)    
    {     
    p3=p1;p1=head;p2=head;  
       while(p1->next!=p3)    
     {p1=p1->next;
}    
     p1->next=NULL;    
    }     
  else
{     
    p2=head;
p3=p1;
p1=head;    
     while(p1->next!=p3)   
      {p1=p1->next;}     
    p3=p3->next;     
    p1->next=p3;     
   }       
  if((fp=fopen("save","wb"))==NULL)    
  {    
   printf("             文件不存在！按下任意键返回主菜单...");
getch();    
  }    
  else  
    {     
 do   
   {     
  fwrite(p2,LEN-4,1,fp);  
     if(p2->next!=NULL)     
  p2=p2->next;  
     }
while(p2->next!=NULL);  
    if(p2!=head)     
 fwrite(p2,LEN-4,1,fp);   
   }
fclose(fp);    
  printf("             删除成功！按下任意键继续...");
getch(); 
    }   
  }    
else
 {
printf("             删除已被取消！按下任意键继续...");
getch();
}     break;  
  case 2:printf("             请输入要修改的教师姓名：");   
  gets(name);  
   while (strcmp((p1->name),name)!=0)    
 {      if (p1->next!=NULL)    
   p1=p1->next;     
 else    
   {     
 printf("             查找不到相关数据!\n");   
    break;    
  }   
  }    
 if (strcmp((p1->name),name)==0)   
  {    
  printf("-----------------------------要删除的信息如下：--------------------------------\n");  
    printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);    
  printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");     
 printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");   
   printf("             确定删除吗？（y或n）:");   
   scanf("%c",&k);getchar();  
   }    
 if (k=='y'||k=='Y')   
  {     if (strcmp((p1->name),name)==0)   
  {      if(p1==head)   
   {       p1=p1->next;   
    p2=p1;
      }    
 else if(p1->next==NULL)    
    {       
  p3=p1;
p1=head;
p2=head;    
     while(p1->next!=p3)         {p1=p1->next;
}     
    p1->next=NULL;   
     }      
 else
{         p2=head;p3=p1;p1=head;     
    while(p1->next!=p3)         {p1=p1->next;
}         p3=p3->next;    
     p1->next=p3;      
  }   
     if((fp=fopen("save","wb"))==NULL)   
   {    
   printf("             文件不存在！按下任意键返回主菜单...");
getch();    
  }      
else  
    {    
  do    
  {     
  fwrite(p2,LEN-4,1,fp);  
     if(p2->next!=NULL)  
     p2=p2->next;   
    }
while(p2->next!=NULL);   
   if(p2!=head)    
   fwrite(p2,LEN-4,1,fp);  
    }fclose(fp);    
  printf("             删除成功！按下任意键继续...");
getch();  
   }   
  }    
 else {printf("             删除已被取消！按下任意键继续...");
getch();
}     break;   
 case 3:break;   
 default :break;   
 }  
  if (i!=3)  
  {   
 printf("\n             继续删除其他教师的信息吗？（y或n）");    scanf("%c",&n);    } 
  }
while((n=='y'||n=='Y')&&i!=3); 
 } 
}  
 int main()
 {
	 deletes();
	 return ;
 }