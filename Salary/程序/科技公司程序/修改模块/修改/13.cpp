#include <stdio.h> //�����������
 #include <stdlib.h> //������������ڴ���亯��
 #include <string.h>//�ַ������� 
#include <conio.h> //(ͨ������̨���������������������ĺ�������Ҫ��ͨ�������̲����Ķ�Ӧ����)
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
/****************************�޸ĺ���*****************************************/
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
   printf("\n\n\n                       >>>>>>>>>>> �޸Ľ�ʦ��Ϣ <<<<<<<<<<<\n");   
 printf("             *******************************************************\n");  
  printf("             *                     1.�����ʦ��                    *\n");   
 printf("             *                     2.��������                      *\n");  
  printf("             *                     3.�����ϼ��˵�                  *\n");  
  printf("             *******************************************************\n");  
  printf("             ��ѡ���޸ķ�ʽ��");  
  scanf("%d",&i);getchar();  
  while (i<1||i>3) 
   {    
 printf("             ��������!����������:");  
   scanf("%d",&i);getchar();    }  
  switch(i) 
   {  
  case 1:printf("             ������Ҫ�޸ĵĽ�ʦ�ţ�");  
   scanf("%d",&num);getchar(); 
while (p1->num!=num)   
  {   
   if (p1->next!=NULL)       p1=p1->next;   
   else      
   {       
       printf("             ���Ҳ����������!\n"); break;  
    } 
    }   
  if (p1->num==num)   
  {    
  system("cls");  
    printf("\n\n\n                    >>>>>��ӭʹ�ý�ʦ���ʹ���ϵͳ<<<<<\n");    
  printf("----------------------------------ԭ��Ϣ���£�---------------------------------\n");  
    printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); 
     printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");     
 printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     
 printf("��������       ����         �����       Ӧ������       ʵ������\n");    
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
    printf("-------------------------------------------------------------------------------\n");    
  printf("             *******************************************************\n");  
    printf("             *              1.��ʦ��        2.����                 *\n");    
  printf("             *              3.�Ա�          4.��λ����             *\n");  
    printf("             *              5.��ͥסַ      6.��ϵ�绰             *\n");   
   printf("             *              7.��������      8.����                 *\n");   
   printf("             *              9.�����      10.�绰��              *\n");   
   printf("             *             11.ˮ���        12.����                *\n");    
  printf("             *             13.����˰        14.������              *\n");   
   printf("             *                      15.������                      *\n");  
    printf("             *******************************************************\n");   
   do    
  {    
  printf("             ��ѡ��Ҫ�޸ĵ����ݣ�");    
  scanf("%d",&i);getchar();  
    while (i>15||i<1)  
    {       
printf("             ������������������:");  
     scanf("%d",&i);getchar(); 
     }  
    switch(i)  
    {    
  case 1:printf("             �������½�ʦ�ţ�");gets(num2);p1->num=atoi(num2);break;   
   case 2:printf("             ��������������");gets(p1->name);break;  
    case 3:printf("             ���������Ա�");gets(p1->sex);break;   
   case 4:printf("             �������µ�λ���ƣ�");gets(p1->workplace);break;   
   case 5:printf("             �������¼�ͥסַ��");gets(p1->address);break;   
   case 6:printf("             ����������ϵ�绰��");gets(num2);p1->phone=atoi(num2);break;  
    case 7:printf("             �������»������ʣ�");gets(num2);p1->de_salary=atof(num2);break; 
     case 8:printf("             �������½�����");gets(num2);p1->de_jintie=atof(num2);break;  
    case 9:printf("             ���������������");
gets(num2);p1->de_shenghuobutie=atof(num2);break;   
   case 10:printf("             �������µ绰�ѣ�");
gets(num2);p1->cost_phone=atof(num2);break;    
  case 11:printf("             ��������ˮ��ѣ�");
gets(num2);p1->cost_water_elec=atof(num2);break;     
 case 12:printf("             �������·��⣺");
gets(num2);p1->cost_rent=atof(num2);break;   
   case 13:printf("             ������������˰��");
gets(num2);p1->cost_tax=atof(num2);break;   
   case 14:printf("             �������������ѣ�");
gets(num2);p1->cost_weisheng=atof(num2);break;  
    case 15:printf("             �������¹�����");
gets(num2);p1->cost_gongjijin=atof(num2);break;
      default:break;    
  }    
  p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;  
    p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;   
   p1->shifa_salary=p1->yingfa_salary-p1->cost_all;  
    printf("             �����޸�����������(y��n):");  
    scanf("%c",&m);
    getchar();  
    }
while (m=='y'||m=='Y');   
   p2=head;    
  if((fp=fopen("save","wb"))==NULL)  
    {     
  printf("             �ļ������ڣ�����������������˵�...");
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
    printf("------------------------------�޸ĺ��������£�---------------------------------\n");  
    printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);   
   printf("��������       ����         �����       Ӧ������       ʵ������\n");    
  printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); 
     printf("-------------------------------------------------------------------------------\n");   
   }   
   fclose(fp);  
   }   
  break; 
   case 2:printf("             ������Ҫ�޸ĵĽ�ʦ������");  
   gets(name);    
   while (strcmp(p1->name,name)!=0)    
 {    
       if (p1->next!=NULL)   
           p1=p1->next;    
  else  
     {       printf("             ���Ҳ���������ݣ�\n");    
   break;    
  } 
    }    
 if (strcmp(p1->name,name)==0)   
  {      
system("cls");  
   printf("\n\n\n                    >>>>>��ӭʹ�ý�ʦ���ʹ���ϵͳ<<<<<\n"); 
     printf("----------------------------------ԭ��Ϣ���£�---------------------------------\n");  
   printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");    
  printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
  printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");   
   printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("��������       ����         �����       Ӧ������       ʵ������\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);    
  printf("-------------------------------------------------------------------------------\n");    
  printf("             *******************************************************\n");   
  printf("             *              1.��ʦ��        2.����                 *\n");   
  printf("             *              3.�Ա�          4.��λ����             *\n");   
  printf("             *              5.��ͥסַ      6.��ϵ�绰             *\n");  
  printf("             *              7.��������      8.����                 *\n");    
  printf("             *              9.�����      10.�绰��              *\n");    
  printf("             *             11.ˮ���        12.����                *\n");  
  printf("             *             13.����˰        14.������              *\n");   
  printf("             *             15.������                               *\n");   
  printf("             *******************************************************\n");  
    do   
  {    
  printf("             ��ѡ��Ҫ�޸ĵ����ݣ�");     
 scanf("%d",&i);getchar();    
  while (i>15||i<1)     
 {    
   printf("             ������������������:"); 
      scanf("%d",&i);
getchar();   
   }  
    switch(i)  
    {   
   case 1:printf("             �������½�ʦ�ţ�");gets(num2);p1->num=atoi(num2);break;     
 case 2:printf("             ��������������");gets(p1->name);break;     
 case 3:printf("             ���������Ա�");gets(p1->sex);break;
      case 4:printf("             �������µ�λ���ƣ�");gets(p1->workplace);break;   
   case 5:printf("             �������¼�ͥסַ��");gets(p1->address);break;  
    case 6:printf("             ����������ϵ�绰��");gets(num2);p1->phone=atoi(num2);break;    
  case 7:printf("             �������»������ʣ�");gets(num2);p1->de_salary=atof(num2);break; 
     case 8:printf("             �������½�����");gets(num2);p1->de_jintie=atof(num2);break;    
  case 9:printf("             ���������������");
gets(num2);p1->de_shenghuobutie=atof(num2);break;  
    case 10:printf("             �������µ绰�ѣ�");
gets(num2);p1->cost_phone=atof(num2);break;   
   case 11:printf("             ��������ˮ��ѣ�");
gets(num2);p1->cost_water_elec=atof(num2);break;    
  case 12:printf("             �������·��⣺");
gets(num2);p1->cost_rent=atof(num2);break;  
    case 13:printf("             ������������˰��");
gets(num2);p1->cost_tax=atof(num2);break;    
  case 14:printf("             �������������ѣ�");
gets(num2);p1->cost_weisheng=atof(num2);break;    
  case 15:printf("             �������¹�����");
gets(num2);p1->cost_gongjijin=atof(num2);break;      default:break;  
    }  
    p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;   
   p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;      p1->shifa_salary=p1->yingfa_salary-p1->cost_all;  
    printf("             �����޸�����������(y��n):");   
   scanf("%c",&m);
getchar(); 
     }
while (m=='y'||m=='Y');  
    p2=head;  
    if((fp=fopen("save","wb"))==NULL)     
 {     
  printf("             �ļ������ڣ�����������������˵�...");
getch();     
 }    
  else    
  {   
   fwrite(head,LEN-4,1,fp);  
    do    
  {       p2=p2->next;  
     fwrite(p2,LEN-4,1,fp);   
   }while(p2->next!=NULL);    
  printf("------------------------------�޸ĺ��������£�---------------------------------\n");    
  printf("�̹���     ����    �Ա�    ��λ����            ��ͥסַ          ��ϵ�绰\n");  
    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
   printf("�绰��     ˮ���     ����     ��������˰     ������     ������     �ϼƿۿ�\n");  
    printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
    printf("��������       ����         �����       Ӧ������       ʵ������\n");   
   printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);   
   printf("-------------------------------------------------------------------------------\n");    
  }     
 fclose(fp);    
 }     break; 
   case 3:break;    default :break;  
  } 
   if (i!=3)   
 {    printf("\n             �����޸�������ʦ����Ϣ�𣿣�y��n��");  
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