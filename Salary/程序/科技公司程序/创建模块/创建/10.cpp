#include <stdio.h> //�����������
 #include <stdlib.h> //������������ڴ���亯��
 #include <string.h>//�ַ������� 
#include <conio.h> //C����ͼ�κ���
#define LEN sizeof(struct teacher)  //�궨��,���Ժ����LEN�ĵط�����teacher����ṹ����ռ���ֽ������棬����ֽ�����һ������
struct teacher 
 {  int num;
  char name[20]; 
 char sex[20]; 
 char workplace[50]; //ѧԺ
 char teacher_ident; //��ʦְ��
 char address[50]; 
 long phone;  
double de_salary; //��������
 double de_jintie; //����
 double de_shenghuobutie; //�����
 double yingfa_salary; //Ӧ������
 double cost_phone; //�绰��
 double cost_water_elec;//ˮ���
  double cost_rent; // ����
double cost_tax;//����
  double cost_weisheng; // ������
double cost_gongjijin; //������ 
double cost_all; //�ϼƿۿ�
 double shifa_salary;//ʵ������
  struct teacher *next; 
};    
//��ȡ����
 struct teacher *load() 
{  struct teacher *p1,*p2,*head; 
 FILE *fp; 
 int i=1; 
 if((fp=fopen("save","rb"))==NULL)//�ж��Զ������Ƶķ�ʽ���ļ�save���ļ�������浽fp��fp�Ƿ�Ϊ��,���Ϊ�գ����Ǵ��ļ�ʧ�ܣ�������ļ��ɹ�
  { 
  printf("             �ļ������ڣ�����������������˵�...");
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
 printf("             �ļ������ڣ�����������������˵�...");
getch(); 
 }  
else
  {
   printf("             �������ʦ��Ϣ��\n"); 
 do  
{   
 printf("             ------------------------------\n");  
  printf("             ������̹���:");
gets(num);p1->num=atoi(num);   
 printf("             ����������:");
gets(p1->name);
printf("             �������Ա�:");
gets(p1->sex);
    printf("             �����뵥λ����:");gets(p1->workplace);   
 printf("             �������ͥסַ:");gets(p1->address); 
   printf("             ��������ϵ�绰:");gets(num);p1->phone=atoi(num);  
  printf("             �������������:");
gets(num);
p1->de_salary=atof(num);   
 printf("             ���������:");
gets(num);p1->de_jintie=atof(num);   
 printf("             �����������:");gets(num);p1->de_shenghuobutie=atof(num);   
 printf("             ������绰��:");gets(num);p1->cost_phone=atof(num); 
   printf("             ������ˮ���:");gets(num);p1->cost_water_elec=atof(num);  
  printf("             �����뷿��:");gets(num);p1->cost_rent=atof(num);  
  printf("             �������������˰:");gets(num);p1->cost_tax=atof(num);  
  printf("             ������������:");gets(num);p1->cost_weisheng=atof(num);  
  printf("             �����빫����:");gets(num);p1->cost_gongjijin=atof(num);   
 p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;   
 p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;  
  p1->shifa_salary=p1->yingfa_salary-p1->cost_all;    fwrite(p1,LEN-4,1,fp); 
   printf("             ������һ������y��n��");  
  m=getchar();   
 if(m!='y'&&m!='Y')  
  {
printf("             ���ݱ���ɹ�������������������˵�...");
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