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
int main()
{
input();
return;
}