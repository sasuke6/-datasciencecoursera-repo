#include <stdio.h> //�����������
#include <stdlib.h> //������������ڴ���亯��
#include <string.h>//�ַ������� 
#include <conio.h> //
#define LEN sizeof(struct teacher)  //�궨��,���Ժ����LEN�ĵط�����teacher����ṹ����ռ���ֽ������棬����ֽ�����һ������
struct teacher 
{  
	int num;
	char name[20]; 
	char sex[20]; 
	char workplace[50]; //ѧԺ
	char address[50]; 
	long phone;  
	double de_salary; //��������
	double de_jintie; //����
	double de_shenghuobutie; //�����
	double yingfa_salary; //Ӧ������
	double cost_phone; //�绰��
	double cost_water_elec;//ˮ���
	double cost_rent; // ����
	double cost_tax;//˰��
	double cost_weisheng; // ������
	double cost_gongjijin; //������ 
	double cost_all; //�ϼƿۿ�
	double shifa_salary;//ʵ������
	struct teacher *next; 
};    
/*********************************��ȡ����************************************/
 struct teacher *load() 
{ 
	struct teacher *p1,*p2,*head; //����ָ��struct teacher�������ݵ�ָ�����p1��p2��head
    FILE *fp; //����ָ��FILE�����ļ���ָ�����
    int i=1; //�������i����ֵ1
    if((fp=fopen("save","rb"))==NULL)//�ж��Զ������Ƶķ�ʽ���ļ�save���ļ�������浽fp��fp�Ƿ�Ϊ��,���Ϊ�գ����Ǵ��ļ�ʧ�ܣ�������ļ��ɹ�
	{
		printf("             �ļ������ڣ�����������������˵�...");
		getch();//�Ӽ����ϻ�ȡ�����ַ�
		return (NULL); //�������˵�
	}
	else
	{
		head=NULL;  //��Ϊ�ǿձ�
		p1=(struct teacher *)malloc(LEN);  //����һ���µ�Ԫ
		while (fread(p1,LEN-4,1,fp)==1)  //��fp�ļ��ж�ȡLEN-4���ֽڵ�1�����ݴ�ŵ�p1�У�����1ʱΪ����ѭ��
		{
			if(i==1)
			{
				head=p1;  //p1��ֵ����head
				p2=p1;  //p2��ֵ����p1
				i=2;//ʹhead��p1��p2ͬʱָ���¿��ٵĿռ�
			}
			else
			{
				p2->next=p1;   //p2�Ľ��Ϊp2��ͷ���
				p2=p2->next;  //��p2��ͷָ����ָ����һ�������ͷָ��
			}
			p1=(struct teacher *)malloc(LEN);  //����һ���µ�Ԫ
		}
		p2->next=NULL;  //p2�Ľ��Ϊ�±��ͷ���
        free(p1); 
        fclose(fp);  //�ر��ļ�
        return(head);  //�ص�ͷָ��
	}
}

 /***************************������*************************************/ 
void sort()
{  
	int i;
	struct teacher *head,*q,*t; //����ָ��struct teacher�������ݵ�ָ�����head��q��t
	system("cls");      //������ʾ
	FILE *fp;
	if((fp=fopen("sort.xls","w"))==NULL) //���ļ�
	{
		printf("���ļ�����"); 
		getch(); 
		exit(1);  //�˳�
	}
	else
		fprintf(fp,"�̹���\t����\t�Ա�\t��λ����\t��ͥסַ\t��ϵ�绰\t�绰��\tˮ���\t����\t��������˰\t������\t������\t�ϼƿۿ�\t��������\t����\t�����\tӦ������\tʵ������\n");
	printf("\n\n\n             ******************����********************\n");
	printf("             *            1����������������           *\n"); 
	printf("             *            2�����������ʽ�������       *\n"); 
	printf("             *            3��������ʵ������           *\n"); 
	printf("             ******************************************\n"); 
	printf("             ������Ҫ����ʽǰ�����ţ�");
	scanf("%d",&i); 
	while(i<1||i>3)
	{
		printf("�����������������룺");
		scanf("%d",&i);
	}
	switch(i)  //ѡ�����
	{
		case 1: 
			q=t=head=load();   //ָ����������
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->num)<(t->num))  //���q�Ľ���t�Ľ��Сִ����������
						t=q;
					q=q->next;//��qͷָ����ָ����һ�������ͷָ��
				}
				fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%ld\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
				if(t==head)  //���t�Ľ������head�Ľ��ִ����������
					head=head->next; //��head��ָ����һ�������ͷָ��
				else 
				{
					q=head; 
					while(q->next!=t)//���q�Ľ�㲻����t�Ľ��
						q=q->next;
					q->next=t->next;
					free(t); //�ͷ��ڴ�
				}
				q=t=head;
			}
			fclose(fp);
			printf("��������������ɹ�������ļ�sort.xls���в鿴��������ص����˵�...");
			getch();break; //�ص����˵�
		case 2:
			q=t=head=load();   //ָ����������
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->de_salary)>(t->de_salary))  //���q�Ľ���de_salary�Ľ��Сִ����������
						t=q;  //t��q����ֵ
					q=q->next;  //��qͷָ����ָ����һ�������ͷָ��
				}
				fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%ld\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
				if(t==head)
					head=head->next;  //��head��ָ����һ�������ͷָ��
				else 
				{
					q=head;
					while(q->next!=t)
						q=q->next;  //��qͷָ����ָ����һ�������ͷָ��
					q->next=t->next;  //tָ�븳��qָ��
					free(t); //�ͷ��ڴ�
				}
				q=t=head;
			}
			fclose(fp);
			printf("���������ʽ�������ɹ�������ļ�sort.xls���в鿴��������ص����˵�...");
			getch();break;
		case 3:
			q=t=head=load();
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->shifa_salary)>(t->shifa_salary))  //���q�Ľ���shifa_salary�Ľ��Сִ����������
						t=q;
					q=q->next;
				}
				fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%ld\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
				if(t==head)
					head=head->next;
				else 
				{
					q=head;
					while(q->next!=t)
						q=q->next;
					q->next=t->next;
					free(t);
				}
				q=t=head;
			}
			fclose(fp);
			printf("��ʵ�����ʽ�������ɹ�������ļ�sort.xls���в鿴��������ص����˵�...");
			getch();break;
	}
}

int main()
{
	sort();
	return 0;
}