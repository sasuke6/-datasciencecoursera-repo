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
/*********************************��ȡ����************************************/
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
  printf("\n\n\n                       >>>>>>>>>>> ɾ����ʦ��Ϣ <<<<<<<<<<<\n"); 
  printf("             *******************************************************\n");   
 printf("             *                     1.�����ʦ��                    *\n");  
  printf("             *                     2.��������                      *\n");  
  printf("             *                     3.�����ϼ��˵�                  *\n");  
  printf("             *******************************************************\n");   
 printf("             ��ѡ��ɾ����ʽ��");   
 scanf("%d",&i);
getchar();  
  while (i<1||i>3)  
  {     
printf("             ��������!����������:"); 
scanf("%d",&i);
getchar();  
  }    
switch(i)   
 {    
    case 1:printf("             ������Ҫɾ������Ϣ�Ľ�ʦ�ţ�");     
scanf("%d",&num);getchar();     
while (p1->num!=num)   
  {    
  if (p1->next!=NULL)     
  p1=p1->next;  
    else  
     {      
 printf("             ���Ҳ����������!\n");    
   break;   
   }   
  }   
  if (p1->num==num)  
   {    
  printf("-----------------------------Ҫɾ������Ϣ���£�--------------------------------\n");  
    printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("��������       ����         �����       Ӧ������       ʵ������\n");  
    printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");  
   printf("             ȷ��ɾ���𣿣�y��n��:");   
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
   printf("             �ļ������ڣ�����������������˵�...");
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
  printf("             ɾ���ɹ����������������...");
getch(); 
    }   
  }    
else
 {
printf("             ɾ���ѱ�ȡ�����������������...");
getch();
}     break;  
  case 2:printf("             ������Ҫ�޸ĵĽ�ʦ������");   
  gets(name);  
   while (strcmp((p1->name),name)!=0)    
 {      if (p1->next!=NULL)    
   p1=p1->next;     
 else    
   {     
 printf("             ���Ҳ����������!\n");   
    break;    
  }   
  }    
 if (strcmp((p1->name),name)==0)   
  {    
  printf("-----------------------------Ҫɾ������Ϣ���£�--------------------------------\n");  
    printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);    
  printf("��������       ����         �����       Ӧ������       ʵ������\n");     
 printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");   
   printf("             ȷ��ɾ���𣿣�y��n��:");   
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
   printf("             �ļ������ڣ�����������������˵�...");
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
  printf("             ɾ���ɹ����������������...");
getch();  
   }   
  }    
 else {printf("             ɾ���ѱ�ȡ�����������������...");
getch();
}     break;   
 case 3:break;   
 default :break;   
 }  
  if (i!=3)  
  {   
 printf("\n             ����ɾ��������ʦ����Ϣ�𣿣�y��n��");    scanf("%c",&n);    } 
  }
while((n=='y'||n=='Y')&&i!=3); 
 } 
}  
 int main()
 {
	 deletes();
	 return ;
 }