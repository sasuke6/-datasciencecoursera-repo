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
//��ӭ�˵�����
void welcome()
{
 printf("\n\n\n                       >>>>>��ӭʹ�ý�ʦ���ʹ���ϵͳ<<<<<\n"     );
 printf("             *******************************************************\n");
 printf("             *            C���Կγ����  ��ʦ���ʹ���ϵͳ          *\n");
 printf("             *            �༶�� 12����Ϣ��  ���4               *\n"); 
 printf("             *            ��Ա����־Ӿ  ������  ������             *\n");
 printf("             *                  ������  ������  л����             *\n");
 printf("             *******************************************************\n"); 
 printf("\n\n                             �������������ϵͳ...");  
getch();  
system("cls"); 
} 
/***************************������Ա����*************************************/ 
void list()
 {  
  system("cls");
  printf("********************************************************************\n");
  printf("*    ѧУ(College):       �㶫����ʦ��ѧԺ                         *\n"); 
  printf("*    �������(Software)�� ��ʦ���ʹ���ϵͳ                         *\n"); 
  printf("*    ������(Producer)��   ��־Ӿ ��                                  *\n"); 
  printf("*    ���ڰ༶(Class)��    12����Ϣ��                               *\n");  
  printf("*    ����ѧԺ(Institute)����������ϢѧԺ                           *\n"); 
  printf("********************************************************************\n"); 

  printf("\n\n                             ����������������˵�...");
  getch();
 } 
void scan()
 {
  struct teacher *head,*p1;  int i;  char m='n'; 
 p1=head=(struct teacher *)malloc(LEN);  
if((head=load())!=NULL)
  {   system("cls"); 
  printf("\n\n\n                       >>>>>>>>>>> �����ʦ��Ϣ <<<<<<<<<<<\n");  
 printf("             *******************************************************\n");  
 printf("             *                     1.ȫ�����                      *\n"); 
  printf("             *                     2.�������                      *\n");  
 printf("             *                     3.�����ϼ��˵�                  *\n");  
 printf("             *******************************************************\n");  
 printf("             ����������Ҫ�Ĳ�����");  
 scanf("%d",&i);
getchar();  
 while (i<1||i>3)   
{    
printf("             ������������������:");  
  scanf("%d",&i);
getchar(); 
  } 
  switch(i)  
 {   case 1:p1=head;  
  printf("----------------------------���б������Ϣ���£�-------------------------------\n");    
printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n"); 
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
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");
do   
 {   
 printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf ",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     if (p1->next!=NULL) 
    {p1=p1->next;
}   
  else break;   
 }
while(1);   
 p1=head;
    printf("��������       ����         �����       Ӧ������       ʵ������\n"); 
   do  
  {   
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf \n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); 
    if (p1->next!=NULL)     {p1=p1->next;
}     else break;   
 }
while(1);   
 p1=head; 
   printf("\n-------------------------------------------------------------------------------\n");   
 printf("             ����������������˵�...");  
  getch();    break; 
    case 2:    do   
 {   
 int num=0;  
  char name[20];    
p1=head;  
  system("cls");  
  printf("\n\n\n                       >>>>>>>>>>> �����ʦ��Ϣ <<<<<<<<<<<\n");   
 printf("             *******************************************************\n");  
  printf("             *                     1.�����ʦ��                    *\n"); 
   printf("             *                     2.��������                      *\n"); 
   printf("             *******************************************************\n"); 
   printf("             ����������Ҫ�Ĳ�����");   
 scanf("%d",&i);
getchar();  
  while (i<1||i>2)   
 {   
  printf("             ��������!����������:"); 
    scanf("%d",&i);getchar();  
  }   
 switch(i)   
 {  
 case 1:printf("             ������Ҫ��ѯ�Ľ�ʦ�ţ�");     
scanf("%d",&num);getchar();    
 while (p1->num!=num)   
  {      if (p1->next!=NULL)     
  p1=p1->next;     
 else      
 {     
  printf("             ���Ҳ����������!\n");  
     break;    
  }    
 }     
if (p1->num==num)  
   {      printf("-------------------------------������Ϣ���£�----------------------------------\n");    
  printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");   
   printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");    
  printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",
p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("��������       ����         �����       Ӧ������       ʵ������\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);   
   printf("-------------------------------------------------------------------------------\n");   
  }     break;   
 case 2:printf("             ������Ҫ��ѯ�Ľ�ʦ������");    
 gets(name); 
    while (strcmp(p1->name,name)!=0) 
    {    
  if (p1->next!=NULL)   
    p1=p1->next;  
    else   
    {  
     printf("             ���Ҳ���������ݣ�\n");       break; 
     }    
 }   
 if (strcmp(p1->name,name)==0)    
 {     
 printf("-------------------------------������Ϣ���£�----------------------------------\n");   
   printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);  
    printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);    
  printf("��������       ����         �����       Ӧ������       ʵ������\n"); 
     printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);    
  printf("-------------------------------------------------------------------------------\n");  
   }  
   break;  
  default :break; 
   }   
 printf("             ��������𣿣�y��n��");   
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