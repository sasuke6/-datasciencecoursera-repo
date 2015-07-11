#include <stdio.h> //输入输出函数
 #include <stdlib.h> //定义杂项函数及内存分配函数
 #include <string.h>//字符串处理 
#include <conio.h> //(通过控制台进行数据输入和数据输出的函数，主要是通过按键盘产生的对应操作)
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
void input()
 {  
FILE *fp;
  char m,num[30]; 
  struct teacher *p1; 
 p1=(struct teacher *)malloc(LEN); 
 if((fp=fopen("save","ab"))==NULL)  
{  
 printf("             文件不存在！按下任意键返回主菜单...");
getch(); 
 }  
else
  {
   printf("             请输入教师信息：\n"); 
 do  
{   
 printf("             ------------------------------\n");  
  printf("             请输入教工号:");
gets(num);p1->num=atoi(num);   
 printf("             请输入姓名:");
gets(p1->name);
printf("             请输入性别:");
gets(p1->sex);
    printf("             请输入单位名称:");gets(p1->workplace);   
 printf("             请输入家庭住址:");gets(p1->address); 
   printf("             请输入联系电话:");gets(num);p1->phone=atoi(num);  
  printf("             请输入基本工资:");
gets(num);
p1->de_salary=atof(num);   
 printf("             请输入津贴:");
gets(num);p1->de_jintie=atof(num);   
 printf("             请输入生活补贴:");gets(num);p1->de_shenghuobutie=atof(num);   
 printf("             请输入电话费:");gets(num);p1->cost_phone=atof(num); 
   printf("             请输入水电费:");gets(num);p1->cost_water_elec=atof(num);  
  printf("             请输入房租:");gets(num);p1->cost_rent=atof(num);  
  printf("             请输入个人所得税:");gets(num);p1->cost_tax=atof(num);  
  printf("             请输入卫生费:");gets(num);p1->cost_weisheng=atof(num);  
  printf("             请输入公积金:");gets(num);p1->cost_gongjijin=atof(num);   
 p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;   
 p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;  
  p1->shifa_salary=p1->yingfa_salary-p1->cost_all;    fwrite(p1,LEN-4,1,fp); 
   printf("             输入下一个？（y或n）");  
  m=getchar();   
 if(m!='y'&&m!='Y')  
  {
printf("             数据保存成功！按下任意键返回主菜单...");
getch();
}  
  getchar();   
 }
while (m=='y'||m=='Y');
  }
  fclose(fp); 
 }  
/****************************修改函数*****************************************/
 void modify()
 {  struct teacher *head,*p1,*p2;  
int i; 
 FILE *fp;
  char m='n',n='n',num2[30];  p1=head=(struct teacher *)malloc(LEN); 
 if((head=load())!=NULL) 
 {   do  
 {   
 int num=0;    
char name[20];   
 p1=head;  
  system("cls"); 
   printf("\n\n\n                       >>>>>>>>>>> 修改教师信息 <<<<<<<<<<<\n");   
 printf("             *******************************************************\n");  
  printf("             *                     1.输入教师号                    *\n");   
 printf("             *                     2.输入姓名                      *\n");  
  printf("             *                     3.返回上级菜单                  *\n");  
  printf("             *******************************************************\n");  
  printf("             请选择修改方式：");  
  scanf("%d",&i);getchar();  
  while (i<1||i>3) 
   {    
 printf("             输入有误!请重新输入:");  
   scanf("%d",&i);getchar();    }  
  switch(i) 
   {  
  case 1:printf("             请输入要修改的教师号：");  
   scanf("%d",&num);getchar(); 
while (p1->num!=num)   
  {   
   if (p1->next!=NULL)       p1=p1->next;   
   else      
   {       
       printf("             查找不到相关数据!\n"); break;  
    } 
    }   
  if (p1->num==num)   
  {    
  system("cls");  
    printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统<<<<<\n");    
  printf("----------------------------------原信息如下：---------------------------------\n");  
    printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); 
     printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");     
 printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     
 printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");    
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");    
  printf("             *******************************************************\n");  
    printf("             *              1.教师号        2.姓名                 *\n");    
  printf("             *              3.性别          4.单位名称             *\n");  
    printf("             *              5.家庭住址      6.联系电话             *\n");   
   printf("             *              7.基本工资      8.津贴                 *\n");   
   printf("             *              9.生活补贴      10.电话费              *\n");   
   printf("             *             11.水电费        12.房租                *\n");    
  printf("             *             13.所得税        14.卫生费              *\n");   
   printf("             *                      15.公积金                      *\n");  
    printf("             *******************************************************\n");   
   do    
  {    
  printf("             请选择要修改的数据：");    
  scanf("%d",&i);getchar();  
    while (i>15||i<1)  
    {       
printf("             输入有误！请重新输入:");  
     scanf("%d",&i);getchar(); 
     }  
    switch(i)  
    {    
  case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break;   
   case 2:printf("             请输入新姓名：");gets(p1->name);break;  
    case 3:printf("             请输入新性别：");gets(p1->sex);break;   
   case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;   
   case 5:printf("             请输入新家庭住址：");gets(p1->address);break;   
   case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break;  
    case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break; 
     case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;  
    case 9:printf("             请输入新生活补贴：");
gets(num2);p1->de_shenghuobutie=atof(num2);break;   
   case 10:printf("             请输入新电话费：");
gets(num2);p1->cost_phone=atof(num2);break;    
  case 11:printf("             请输入新水电费：");
gets(num2);p1->cost_water_elec=atof(num2);break;     
 case 12:printf("             请输入新房租：");
gets(num2);p1->cost_rent=atof(num2);break;   
   case 13:printf("             请输入新所得税：");
gets(num2);p1->cost_tax=atof(num2);break;   
   case 14:printf("             请输入新卫生费：");
gets(num2);p1->cost_weisheng=atof(num2);break;  
    case 15:printf("             请输入新公积金：");
gets(num2);p1->cost_gongjijin=atof(num2);break;
      default:break;    
  }    
  p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;  
    p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;   
   p1->shifa_salary=p1->yingfa_salary-p1->cost_all;  
    printf("             继续修改其他数据吗？(y或n):");  
    scanf("%c",&m);
    getchar();  
    }
while (m=='y'||m=='Y');   
   p2=head;    
  if((fp=fopen("save","wb"))==NULL)  
    {     
  printf("             文件不存在！按下任意键返回主菜单...");
getch();   
   }    
  else    
 {    
  fwrite(head,LEN-4,1,fp);     
 do  
    {     
  p2=p2->next;   
    fwrite(p2,LEN-4,1,fp);     
 }
while(p2->next!=NULL);  
    printf("------------------------------修改后数据如下：---------------------------------\n");  
    printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);   
   printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");    
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); 
     printf("-------------------------------------------------------------------------------\n");   
   }   
   fclose(fp);  
   }   
  break; 
   case 2:printf("             请输入要修改的教师姓名：");  
   gets(name);    
   while (strcmp(p1->name,name)!=0)    
 {    
       if (p1->next!=NULL)   
           p1=p1->next;    
  else  
     {       printf("             查找不到相关数据！\n");    
   break;    
  } 
    }    
 if (strcmp(p1->name,name)==0)   
  {      
system("cls");  
   printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统<<<<<\n"); 
     printf("----------------------------------原信息如下：---------------------------------\n");  
   printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);    
  printf("-------------------------------------------------------------------------------\n");    
  printf("             *******************************************************\n");   
  printf("             *              1.教师号        2.姓名                 *\n");   
  printf("             *              3.性别          4.单位名称             *\n");   
  printf("             *              5.家庭住址      6.联系电话             *\n");  
  printf("             *              7.基本工资      8.津贴                 *\n");    
  printf("             *              9.生活补贴      10.电话费              *\n");    
  printf("             *             11.水电费        12.房租                *\n");  
  printf("             *             13.所得税        14.卫生费              *\n");   
  printf("             *             15.公积金                               *\n");   
  printf("             *******************************************************\n");  
    do   
  {    
  printf("             请选择要修改的数据：");     
 scanf("%d",&i);getchar();    
  while (i>15||i<1)     
 {    
   printf("             输入有误！请重新输入:"); 
      scanf("%d",&i);
getchar();   
   }  
    switch(i)  
    {   
   case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break;     
 case 2:printf("             请输入新姓名：");gets(p1->name);break;     
 case 3:printf("             请输入新性别：");gets(p1->sex);break;
      case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;   
   case 5:printf("             请输入新家庭住址：");gets(p1->address);break;  
    case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break;    
  case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break; 
     case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;    
  case 9:printf("             请输入新生活补贴：");
gets(num2);p1->de_shenghuobutie=atof(num2);break;  
    case 10:printf("             请输入新电话费：");
gets(num2);p1->cost_phone=atof(num2);break;   
   case 11:printf("             请输入新水电费：");
gets(num2);p1->cost_water_elec=atof(num2);break;    
  case 12:printf("             请输入新房租：");
gets(num2);p1->cost_rent=atof(num2);break;  
    case 13:printf("             请输入新所得税：");
gets(num2);p1->cost_tax=atof(num2);break;    
  case 14:printf("             请输入新卫生费：");
gets(num2);p1->cost_weisheng=atof(num2);break;    
  case 15:printf("             请输入新公积金：");
gets(num2);p1->cost_gongjijin=atof(num2);break;      default:break;  
    }  
    p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;   
   p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;      p1->shifa_salary=p1->yingfa_salary-p1->cost_all;  
    printf("             继续修改其他数据吗？(y或n):");   
   scanf("%c",&m);
getchar(); 
     }
while (m=='y'||m=='Y');  
    p2=head;  
    if((fp=fopen("save","wb"))==NULL)     
 {     
  printf("             文件不存在！按下任意键返回主菜单...");
getch();     
 }    
  else    
  {   
   fwrite(head,LEN-4,1,fp);  
    do    
  {       p2=p2->next;  
     fwrite(p2,LEN-4,1,fp);   
   }while(p2->next!=NULL);    
  printf("------------------------------修改后数据如下：---------------------------------\n");    
  printf("教工号     姓名    性别    单位名称            家庭住址          联系电话\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);   
   printf("-------------------------------------------------------------------------------\n");    
  }     
 fclose(fp);    
 }     break; 
   case 3:break;    default :break;  
  } 
   if (i!=3)   
 {    printf("\n             继续修改其他教师的信息吗？（y或n）");  
  scanf("%c",&n);  
  }   
 }
while((n=='y'||n=='Y')&&i!=3);
  } 
 }  
 int main()
 {
	 modify();
return;
 }