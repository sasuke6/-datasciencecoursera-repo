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
double cost_tax;//��������˰
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
 void insert()
 {  
struct teacher *head,*p1,*p2,*p3,*px;  
int i,t; 
 FILE *fp;
  char k,n='n',num[30],name[20];
  p1=p2=p3=px=(struct teacher *)malloc(LEN); 
 if((head=load())!=NULL)
  {  
 do
   {    n='n';    printf("             ������Ҫ����Ľ�ʦ��Ϣ��\n");  
  printf("             ------------------------------\n");   
 printf("             ������̹���:");
gets(num);px->num=atoi(num); 
   printf("             ����������:");
gets(px->name); 
   printf("             �������Ա�:");
gets(px->sex);   
 printf("             �����뵥λ����:");
gets(px->workplace); 
   printf("             �������ͥסַ:");
gets(px->address);  
  printf("             ��������ϵ�绰:");
gets(num);
px->phone=atoi(num);   
 printf("             �������������:");
gets(num);
px->de_salary=atof(num);
printf("             ���������:");
gets(num);
px->de_jintie=atof(num); 
   printf("             �����������:");
gets(num);
px->de_shenghuobutie=atof(num);   
 printf("             ������绰��:");
gets(num);
px->cost_phone=atof(num);  
  printf("             ������ˮ���:");
gets(num);
px->cost_water_elec=atof(num);  
  printf("             �����뷿��:");
gets(num);
px->cost_rent=atof(num);   
 printf("             �������������˰:");
gets(num);
px->cost_tax=atof(num);  
  printf("             ������������:");gets(num);
px->cost_weisheng=atof(num);  
  printf("             �����빫����:");
gets(num);
px->cost_gongjijin=atof(num);  
  px->yingfa_salary=px->de_salary+px->de_jintie+px->de_shenghuobutie;  
  px->cost_all=px->cost_phone+px->cost_water_elec+px->cost_rent+px->cost_tax+px->cost_weisheng+px->cost_gongjijin;  
  px->shifa_salary=px->yingfa_salary-px->cost_all; 
   printf("             ����������ϣ��������������...");
getch();     
   system("cls"); 
   printf("\n\n\n                       >>>>>>>>>>> �����ʦ��Ϣ <<<<<<<<<<<\n"); 
   printf("             *******************************************************\n");  
  printf("             *                     1.�����ʦ��                    *\n");   
 printf("             *                     2.��������                      *\n"); 
   printf("             *                     3.�����ϼ��˵�                  *\n");   
 printf("             *******************************************************\n"); 
   printf("             ��ѡ����뷽ʽ��");
    scanf("%d",&i);getchar();   
 while (i<1||i>3) 
   {   
  printf("             ��������!����������:");   
  scanf("%d",&i);getchar();  
  }    
switch(i) 
   { 
   case 1:printf("             ������Ҫ�������������ݺ��棺");  
   scanf("%d",&t);
   getchar();   
  p1=head; 
    while (p1->num!=t)   
  {     
 if (p1->next!=NULL)    
  { 
p1=p1->next;   
   }    
  else
       {     
  printf("             ���Ҳ����������!\n");    
   break;  
     } 
    }    
 if (p1->num==t)   
  {    
  printf("-----------------------------Ҫ�������Ϣ���£�--------------------------------\n");  
    printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");   
   printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",px->num,px->name,px->sex,px->workplace,px->address,px->phone);   
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");    
  printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",px->cost_phone,px->cost_water_elec,px->cost_rent,px->cost_tax,px->cost_weisheng,px->cost_gongjijin,px->cost_all);    
  printf("��������       ����         �����       Ӧ������       ʵ������\n");  
    printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",px->de_salary,px->de_jintie,px->de_shenghuobutie,px->yingfa_salary,px->shifa_salary);    
  printf("-------------------------------------------------------------------------------\n");  
   printf("             ȷ�������𣿣�y��n��:");     
 scanf("%c",&k);
 getchar();   
  }
     if (k=='y'||k=='Y')   
  {   
  if (p1->num==t)   
  {    
  if(p1==head)/*��������Ϊͷָ��*/     
 {     
  p3=p1->next;    
   p1->next=px;   
    px->next=p3;    
   p2=head;  
    } 
     else if(p1->next==NULL)/*��������Ϊĩβָ��*/      
  {    
     p3=p1;p1=head;p2=head;     
    while(p1->next!=p3)       
  {p1=p1->next;
}         
p1=p1->next;    
     p1->next=px; 
        px->next=NULL;    
    }      
 else
{/*��������Ϊ�м�ָ��*/ 
        p3=p1;
p1=head;
p2=head;    
     while(p1->next!=p3)      
   {
p1=p1->next;
}      
   p1=p1->next;      
   p3=p1->next;    
     px->next=p3; 
        p1->next=px;   
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
     if(p2->next!=NULL)       p2=p2->next;  
     }
while(p2->next!=NULL);   
   if(p2!=head)   
    fwrite(p2,LEN-4,1,fp);    
  }
fclose(fp); 
     printf("             ����ɹ����������������...");
getch();   
  }    
 }   
  else
 {
printf("             �����ѱ�ȡ�����������������...");
getch();
}     break; 
   case 2:printf("             ������Ҫ����Ľ�ʦ������");
     gets(name);   
  p1=head;    
 while (strcmp((p1->name),name)!=0) 
{    
  if (p1->next!=NULL)       p1=p1->next; 
     else    
   {       printf("             ���Ҳ����������!\n");       break;  
    }   
  }    
 if (strcmp((p1->name),name)==0)   
  {      printf("-----------------------------Ҫ�������Ϣ���£�--------------------------------\n"); 
     printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");   
   printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");     
 printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     
 printf("��������       ����         �����       Ӧ������       ʵ������\n");  
    printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");  
    printf("             ȷ�������𣿣�y��n��:");      
scanf("%c",&k);getchar();  
   }  
   if (k=='y'||k=='Y') 
    {  
   if (strcmp((p1->name),name)==0)  
   {   
   if(p1==head)/*��������Ϊͷָ��*/    
  {    
   p1->next=px; 
      p2=head;    
  }   
   else if(p1->next==NULL)/*��������Ϊĩβָ��*/     
   {     
    p3=p1
;p1=head;
p2=head;     
    while(p1->next!=p3)  
       {
p1=p1->next;
}        
 p1=p1->next; 
        p1->next=px;
         px->next=NULL; 
       }    
   else{/*��������Ϊ�м�ָ��*/   
      p3=p1;
p1=head;
p2=head;  
       while(p1->next!=p3)  
       {
p1=p1->next;
}        
 p1=p1->next;    
     p1->next=px; 
        p3=p3->next;  
       px->next=p3;   
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
     if(p2->next!=NULL)       p2=p2->next;   
    }
while(p2->next!=NULL);   
   if(p2!=head)       fwrite(p2,LEN-4,1,fp);    
  }
fclose(fp);  
    printf("             ����ɹ����������������...");
getch();    
 }    
 }   
  else
 {
printf("             �����ѱ�ȡ�����������������...");
getch();
}     break;
    case 3:break; 
   default :break; 
   }  
  if (i!=3)  
  {   
 printf("\n             ��������������ʦ����Ϣ�𣿣�y��n��");  
  scanf("%c",&n);getchar();    } 
  }
while((n=='y'||n=='Y')&&i!=3); 
 }   
 printf("             ���ݲ���ɹ�������������������˵�...");
getch();  
  getchar(); 
 }  
int main()
{
insert();
return;
}

