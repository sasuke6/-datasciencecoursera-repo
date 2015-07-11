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
//读取函数
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
//欢迎菜单函数
void welcome()
{
 printf("\n\n\n                       >>>>>欢迎使用教师工资管理系统<<<<<\n"     );
 printf("             *******************************************************\n");
 printf("             *            C语言课程设计  教师工资管理系统          *\n");
 printf("             *            班级： 12光信息班  组别：4               *\n"); 
 printf("             *            成员：许志泳  黄振星  吴作鸿             *\n");
 printf("             *                  王健宁  伍明杰  谢仕昭             *\n");
 printf("             *******************************************************\n"); 
 printf("\n\n                             按下任意键进入系统...");  
getch();  
system("cls"); 
} 
/***************************制作人员名单*************************************/ 
void list()
 {  
  system("cls");
  printf("********************************************************************\n");
  printf("*    学校(College):       广东技术师范学院                         *\n"); 
  printf("*    软件名称(Software)： 教师工资管理系统                         *\n"); 
  printf("*    制作人(Producer)：   许志泳 等                                  *\n"); 
  printf("*    所在班级(Class)：    12光信息班                               *\n");  
  printf("*    所在学院(Institute)：电子与信息学院                           *\n"); 
  printf("********************************************************************\n"); 

  printf("\n\n                             按下任意键返回主菜单...");
  getch();
 } 
void scan()
 {
  struct teacher *head,*p1;  int i;  char m='n'; 
 p1=head=(struct teacher *)malloc(LEN);  
if((head=load())!=NULL)
  {   system("cls"); 
  printf("\n\n\n                       >>>>>>>>>>> 浏览教师信息 <<<<<<<<<<<\n");  
 printf("             *******************************************************\n");  
 printf("             *                     1.全部浏览                      *\n"); 
  printf("             *                     2.单个浏览                      *\n");  
 printf("             *                     3.返回上级菜单                  *\n");  
 printf("             *******************************************************\n");  
 printf("             请输入你想要的操作：");  
 scanf("%d",&i);
getchar();  
 while (i<1||i>3)   
{    
printf("             输入有误！请重新输入:");  
  scanf("%d",&i);
getchar(); 
  } 
  switch(i)  
 {   case 1:p1=head;  
  printf("----------------------------所有保存的信息如下：-------------------------------\n");    
printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n"); 
   do  
  {   
  printf(" %-4d %-13s %s     %-19s %-19s%-14ld",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);  
   if (p1->next!=NULL)   
  {
p1=p1->next;
}     else break;  
  }
while(1); 
   p1=head; 
   printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
do   
 {   
 printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf ",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     if (p1->next!=NULL) 
    {p1=p1->next;
}   
  else break;   
 }
while(1);   
 p1=head;
    printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); 
   do  
  {   
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf \n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); 
    if (p1->next!=NULL)     {p1=p1->next;
}     else break;   
 }
while(1);   
 p1=head; 
   printf("\n-------------------------------------------------------------------------------\n");   
 printf("             按下任意键返回主菜单...");  
  getch();    break; 
    case 2:    do   
 {   
 int num=0;  
  char name[20];    
p1=head;  
  system("cls");  
  printf("\n\n\n                       >>>>>>>>>>> 浏览教师信息 <<<<<<<<<<<\n");   
 printf("             *******************************************************\n");  
  printf("             *                     1.输入教师号                    *\n"); 
   printf("             *                     2.输入姓名                      *\n"); 
   printf("             *******************************************************\n"); 
   printf("             请输入你想要的操作：");   
 scanf("%d",&i);
getchar();  
  while (i<1||i>2)   
 {   
  printf("             输入有误!请重新输入:"); 
    scanf("%d",&i);getchar();  
  }   
 switch(i)   
 {  
 case 1:printf("             请输入要查询的教师号：");     
scanf("%d",&num);getchar();    
 while (p1->num!=num)   
  {      if (p1->next!=NULL)     
  p1=p1->next;     
 else      
 {     
  printf("             查找不到相关数据!\n");  
     break;    
  }    
 }     
if (p1->num==num)  
   {      printf("-------------------------------所查信息如下：----------------------------------\n");    
  printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");   
   printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");    
  printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",
p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);   
   printf("-------------------------------------------------------------------------------\n");   
  }     break;   
 case 2:printf("             请输入要查询的教师姓名：");    
 gets(name); 
    while (strcmp(p1->name,name)!=0) 
    {    
  if (p1->next!=NULL)   
    p1=p1->next;  
    else   
    {  
     printf("             查找不到相关数据！\n");       break; 
     }    
 }   
 if (strcmp(p1->name,name)==0)    
 {     
 printf("-------------------------------所查信息如下：----------------------------------\n");   
   printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);  
    printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);    
  printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); 
     printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);    
  printf("-------------------------------------------------------------------------------\n");  
   }  
   break;  
  default :break; 
   }   
 printf("             继续浏览吗？（y或n）");   
 scanf("%c",&m);  
  }
while(m=='y'||m=='Y');  
 case 3:break;    
    }
  }
 }  
 int main()
 {
	 scan();
	 return 0;
 }