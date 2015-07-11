#include <stdio.h> //输入输出函数
#include <stdlib.h> //定义杂项函数及内存分配函数
#include <string.h>//字符串处理 
#include <conio.h> //
#define LEN sizeof(struct teacher)  //宏定义,在以后出现LEN的地方，用teacher这个结构体所占的字节数代替，这个字节数是一个整数
struct teacher 
{  
	int num;
	char name[20]; 
	char sex[20]; 
	char workplace[50]; //学院
	char address[50]; 
	long phone;  
	double de_salary; //基本工资
	double de_jintie; //津贴
	double de_shenghuobutie; //生活补贴
	double yingfa_salary; //应发工资
	double cost_phone; //电话费
	double cost_water_elec;//水电费
	double cost_rent; // 房租
	double cost_tax;//税费
	double cost_weisheng; // 卫生费
	double cost_gongjijin; //公积金 
	double cost_all; //合计扣款
	double shifa_salary;//实发工资
	struct teacher *next; 
};    
/*********************************读取函数************************************/
 struct teacher *load() 
{ 
	struct teacher *p1,*p2,*head; //定义指向struct teacher类型数据的指针变量p1、p2、head
    FILE *fp; //定义指向FILE类型文件的指针变量
    int i=1; //定义变量i，赋值1
    if((fp=fopen("save","rb"))==NULL)//判断以读二进制的方式打开文件save，文件句柄保存到fp，fp是否为空,如果为空，就是打开文件失败，否则打开文件成功
	{
		printf("             文件不存在！按下任意键返回主菜单...");
		getch();//从键盘上获取任意字符
		return (NULL); //返回主菜单
	}
	else
	{
		head=NULL;  //若为是空表
		p1=(struct teacher *)malloc(LEN);  //开辟一个新单元
		while (fread(p1,LEN-4,1,fp)==1)  //从fp文件中读取LEN-4个字节的1块数据存放到p1中，等于1时为进行循环
		{
			if(i==1)
			{
				head=p1;  //p1的值赋给head
				p2=p1;  //p2的值赋给p1
				i=2;//使head、p1、p2同时指向新开辟的空间
			}
			else
			{
				p2->next=p1;   //p2的结点为p2的头结点
				p2=p2->next;  //将p2的头指针所指的下一个结点作头指针
			}
			p1=(struct teacher *)malloc(LEN);  //开辟一个新单元
		}
		p2->next=NULL;  //p2的结点为新表的头结点
        free(p1); 
        fclose(fp);  //关闭文件
        return(head);  //回到头指针
	}
}

 /***************************排序函数*************************************/ 
void sort()
{  
	int i;
	struct teacher *head,*q,*t; //定义指向struct teacher类型数据的指针变量head、q、t
	system("cls");      //清屏显示
	FILE *fp;
	if((fp=fopen("sort.xls","w"))==NULL) //打开文件
	{
		printf("打开文件出错！"); 
		getch(); 
		exit(1);  //退出
	}
	else
		fprintf(fp,"教工号\t姓名\t性别\t单位名称\t家庭住址\t联系电话\t电话费\t水电费\t房租\t个人所得税\t卫生费\t公积金\t合计扣款\t基本工资\t津贴\t生活补贴\t应发工资\t实发工资\n");
	printf("\n\n\n             ******************排序********************\n");
	printf("             *            1、按工号升序排序           *\n"); 
	printf("             *            2、按基本工资降序排序       *\n"); 
	printf("             *            3、按降序实发工资           *\n"); 
	printf("             ******************************************\n"); 
	printf("             输入想要排序方式前面的序号：");
	scanf("%d",&i); 
	while(i<1||i>3)
	{
		printf("输入有误，请重新输入：");
		scanf("%d",&i);
	}
	switch(i)  //选择语句
	{
		case 1: 
			q=t=head=load();   //指针读入个数据
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->num)<(t->num))  //如果q的结点比t的结点小执行下面的语句
						t=q;
					q=q->next;//将q头指针所指的下一个结点作头指针
				}
				fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%ld\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
				if(t==head)  //如果t的结点恒等于head的结点执行下面的语句
					head=head->next; //将head所指的下一个结点作头指针
				else 
				{
					q=head; 
					while(q->next!=t)//如果q的结点不等于t的结点
						q=q->next;
					q->next=t->next;
					free(t); //释放内存
				}
				q=t=head;
			}
			fclose(fp);
			printf("按工号升序排序成功，请打开文件sort.xls进行查看！任意键回到主菜单...");
			getch();break; //回到主菜单
		case 2:
			q=t=head=load();   //指针读入个数据
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->de_salary)>(t->de_salary))  //如果q的结点比de_salary的结点小执行下面的语句
						t=q;  //t和q交换值
					q=q->next;  //将q头指针所指的下一个结点作头指针
				}
				fprintf(fp,"%d\t%s\t%s\t%s\t%s\t%ld\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\t%.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
				if(t==head)
					head=head->next;  //将head所指的下一个结点作头指针
				else 
				{
					q=head;
					while(q->next!=t)
						q=q->next;  //将q头指针所指的下一个结点作头指针
					q->next=t->next;  //t指针赋给q指针
					free(t); //释放内存
				}
				q=t=head;
			}
			fclose(fp);
			printf("按基本工资降序排序成功，请打开文件sort.xls进行查看！任意键回到主菜单...");
			getch();break;
		case 3:
			q=t=head=load();
			while(q!=NULL)
			{
				while(q!=NULL)
				{
					if((q->shifa_salary)>(t->shifa_salary))  //如果q的结点比shifa_salary的结点小执行下面的语句
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
			printf("按实发工资降序排序成功，请打开文件sort.xls进行查看！任意键回到主菜单...");
			getch();break;
	}
}

int main()
{
	sort();
	return 0;
}