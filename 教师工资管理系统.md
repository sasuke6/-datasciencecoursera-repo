## This is a markdown file
#include <stdio.h>								//输入输出函数
#include <stdlib.h>								//定义杂项函数及内存分配函数
#include <string.h>								//字符串处理 
#include <conio.h>								//C语言图形函数
#define LEN sizeof(struct teacher)				//宏定义,在以后出现LEN的地方，用teacher这个结构体所占的字节数代替，这个字节数是一个整数
struct teacher 
{  
	int num;
	char name[20]; 
	char sex[20]; 
	char workplace[50];							//学院
	char address[50]; 
	long phone;  
	double de_salary;							//基本工资
	double de_jintie;							//津贴
	double de_shenghuobutie;					//生活补贴
	double yingfa_salary;						//应发工资
	double cost_phone;							//电话费
	double cost_water_elec;						//水电费
	double cost_rent;							//房租
	double cost_tax;							//个人所得税
	double cost_weisheng;						//卫生费
	double cost_gongjijin;						//公积金 
	double cost_all;							//合计扣款
	double shifa_salary;						//实发工资
	struct teacher *next; 
};     
/*********************************读取函数************************************/
struct teacher *load()							//定义函数。此函数返回一个指向链表头的指针
{  
	struct teacher *p1,*p2,*head; 
	FILE *fp;									//定义文件指针
	int i=1;									//定义i=1
	if((fp=fopen("save","rb"))==NULL)			//判断以读二进制的方式打开文件save，文件句并保存到fp，fp是否为空
		{ 
			printf("             文件不存在！按下任意键返回主菜单...");
			getch();  
			return (NULL); 
		}
	else 
		{   
			head=NULL;							//定义head的值为0
			p1=(struct teacher *)malloc(LEN);	//开辟一个新单元
			while (fread(p1,LEN-4,1,fp)==1)		//当从fp里读一个字节为LEN-4长度的元素到p1的返回值等于1时循环
				{    
					if(i==1)   
						{     
							head=p1;			//让p1指向头
							p2=p1;				//让p2指向头
							i=2;   
						}   
					else  
						{  
							p2->next=p1;		//让p1指向下一结点 
							p2=p2->next;		//让p2指向下一结点
						}  
					p1=(struct teacher *)malloc(LEN);  //开辟一个新单元
				}  
			p2->next=NULL;						//让p2的尾部指向尾
			free(p1);							//释放p1内存
			fclose(fp);							//关闭文件fp
			return(head);						//返回一个链表起始地址
		}
 }
/***************************欢迎菜单函数*************************************/ 
void welcome()
{
    printf("\n\n\n                       >>>>>欢迎使用教师工资管理系统<<<<<\n"     );
    printf("             *******************************************************\n");
    printf("             *                  由科技管理公司制作                 *\n");
    printf("             *            C语言课程设计  教师工资管理系统          *\n");
    printf("             *            班级： 12光信息班  组别：4               *\n"); 
    printf("             *            成员：许志泳  黄振星  吴作鸿             *\n");
    printf("             *                  王健宁  伍明杰  谢仕昭             *\n");
    printf("             *******************************************************\n"); 
    printf("\n\n                             按下任意键进入系统...");  
    getch();  
    system("cls"); 
} 
/*********************************创建函数************************************/
void input()   //声明input（）函数
{  
	FILE *fp;    //定义一个指向文件的指针变量fp
	char m,num[30];   //定义字符数组
	struct teacher *p1;      //定义指针变量p1
	p1=(struct teacher *)malloc(LEN);     //开辟动态存储区，把起始地址赋给p1
	if((fp=fopen("save","ab"))==NULL)  //打开输出文件并使fp指向此文件
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
					gets(num);
					p1->num=atoi(num);   
					printf("             请输入姓名:");
					gets(p1->name);
					printf("             请输入性别:");
					gets(p1->sex);
					printf("             请输入单位名称:");
					gets(p1->workplace);   
					printf("             请输入家庭住址:");
					gets(p1->address); 
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
					p1->yingfa_salary=p1->de_salary+p1->de_jintie+p1->de_shenghuobutie;   //进行指针的运算 p1->cost_all=p1->cost_phone+p1->cost_water_elec+p1->cost_rent+p1->cost_tax+p1->cost_weisheng+p1->cost_gongjijin;  
					p1->shifa_salary=p1->yingfa_salary-p1->cost_all;    fwrite(p1,LEN-4,1,fp); 
					printf("             输入下一个？（y或n）");  
					m=getchar();   
					if(m!='y'&&m!='Y')   //如果输入y或Y，数据保存成功
						{
							printf("             数据保存成功！按下任意键返回主菜单...");
							getch();
						}  
					getchar();   
				}while (m=='y'||m=='Y');
		}
	fclose(fp);   //关闭文件
} 
/******************************菜单函数**************************************/ 
int menu()
{  
	int i;
	printf("   \n\n\n\n                                    菜单                 \n");   
	printf("             *******************************************************\n");
	printf("             *                 1.创建工资档案                      *\n");  
	printf("             *                 2.新增工资信息                      *\n"); 
	printf("             *                 3.修改工资信息                      *\n"); 
	printf("             *                 4.删除工资信息                      *\n"); 
	printf("             *                 5.查找工资信息                      *\n"); 
	printf("             *                 6.分类信息列表                      *\n");  
	printf("             *                 7.退出系统                          *\n");
	printf("             *******************************************************\n"); 
	printf("             请输入你想要的操作：");
	scanf("%d",&i);
	getchar(); 
	return i;  
} 
/****************************插入函数*****************************************/
 

void insert()									//定义插入函数
{  
    struct teacher *head,*p1,*p2,*p3,*px;		//定义结构体指针
	int i,t;									//定义变量
	FILE *fp;									//定义一个指向文件的指针变量fp
	char k,n='n',num[30],name[20];				//定义字符、数组
	p1=p2=p3=px=(struct teacher *)malloc(LEN);	//开辟一个新单元
	if((head=load())!=NULL)						//辨别head地址是否为空
		{  
		    do									 //插入教师信息
				{
					n='n';    
					printf("             请输入要插入的教师信息：\n");  
					printf("             ------------------------------\n");   
					printf("             请输入教工号:");
					gets(num);
					px->num=atoi(num);														//自动将num转为整型
					printf("             请输入姓名:");
					gets(px->name); 
					printf("             请输入性别:");
					gets(px->sex);   
					printf("             请输入单位名称:");
					gets(px->workplace); 
					printf("             请输入家庭住址:");
					gets(px->address);  
					printf("             请输入联系电话:");
					gets(num);
					px->phone=atoi(num);   
					printf("             请输入基本工资:");
					gets(num);
					px->de_salary=atof(num);												//自动将num转为浮点型
					printf("             请输入津贴:");
					gets(num);
					px->de_jintie=atof(num); 
					printf("             请输入生活补贴:");
					gets(num);
					px->de_shenghuobutie=atof(num);   
					printf("             请输入电话费:");
					gets(num);
					px->cost_phone=atof(num);  
					printf("             请输入水电费:");
					gets(num);
					px->cost_water_elec=atof(num);  
					printf("             请输入房租:");
					gets(num);
					px->cost_rent=atof(num);   
					printf("             请输入个人所得税:");
					gets(num);
					px->cost_tax=atof(num);  
					printf("             请输入卫生费:");gets(num);
					px->cost_weisheng=atof(num);  
					printf("             请输入公积金:");
					gets(num);
					px->cost_gongjijin=atof(num);  
					px->yingfa_salary=px->de_salary+px->de_jintie+px->de_shenghuobutie;								//计算应发工资
					px->cost_all=px->cost_phone+px->cost_water_elec+px->cost_rent+
						px->cost_tax+px->cost_weisheng+px->cost_gongjijin;											//计算话费金额
					px->shifa_salary=px->yingfa_salary-px->cost_all;												//计算实发工资
					printf("             数据输入完毕，按下任意键继续...");
					getch();     
					system("cls");																					//清楚屏幕																					
					printf("\n\n\n                       >>>>>>>>>>> 插入教师信息 <<<<<<<<<<<\n");					//插入方式种类
					printf("             *******************************************************\n");  
					printf("             *                     1.按教师号插入                  *\n");				
					printf("             *                     2.按姓名插入                    *\n");				
					printf("             *                     3.返回上级菜单                  *\n");   
					printf("             *******************************************************\n"); 
					printf("             请选择插入方式：");
					scanf("%d",&i);getchar();   
					while (i<1||i>3) 
						{   
							printf("             输入有误!请重新输入:");   
							scanf("%d",&i);getchar();  
						}    
					switch(i)																					//选择插入方式
						{ 
							case 1:printf("             请输入要插入在哪条数据后面：");							//按教师号插入	
							scanf("%d",&t);
							getchar();   
							p1=head;																			//让p1指向头
							while (p1->num!=t)																	//当输入的学号不存在时		
								{     
									if (p1->next!=NULL)    
										{ 
											p1=p1->next;														//将p1移向next
										}    
									else
										{     
											printf("             查找不到相关数据!\n");    
											break;  
										} 
								}    
							if (p1->num==t)																		//当输入的学号存在时
								{    
									printf("-----------------------------要插入的信息如下：--------------------------------\n");  
									printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");   
									printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",px->num,px->name,px->sex,
										px->workplace,px->address,px->phone);   
									printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");    
									printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",
										px->cost_phone,px->cost_water_elec,px->cost_rent,px->cost_tax,
										px->cost_weisheng,px->cost_gongjijin,px->cost_all);    
									printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");  
									printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",px->de_salary,
										px->de_jintie,px->de_shenghuobutie,px->yingfa_salary,px->shifa_salary);    
									printf("-------------------------------------------------------------------------------\n");  
									printf("             确定插入吗？（y或n）:");     
									scanf("%c",&k);
									getchar();   
								}
							if (k=='y'||k=='Y')																	//选择是否确认插入
								{   
									if (p1->num==t)																//当输入的学号存在时
										{    
											if(p1==head)														//如果插入点为头指针     
												{     
													p3=p1->next;												//让p3指向第二个结点头
													p1->next=px;												//让px指向第二个结点头
													px->next=p3;												//让p3指向第二个结点尾
													p2=head;													//让p2指向头
												} 
											else if(p1->next==NULL)												//如果插入点为末尾指针      
												{    
													p3=p1;														//让p3指向最后一个结点头
													p1=head;													//让p1指向头
													p2=head;													//让p2指向头
													while(p1->next!=p3)											//当p1指向尾不等于p3时
														{
															p1=p1->next;										//让p1移向下一结点
														}         
													p1=p1->next;												//让p1移向下一结点
													p1->next=px;												//让px指向末结点头
													px->next=NULL;												//让PX指向尾为空
												}      
											else
												{																//如果插入点为中间指针 
													p3=p1;														//让p3指向p1所指向位置
													p1=head;													//让p1指向头
													p2=head;													//让p2指向头
													while(p1->next!=p3)											//当p1指向尾部等于p3时
														{
															p1=p1->next;										//让p1移向下一结点
														}      
													p1=p1->next;												//让p1移向下一结点
													p3=p1->next;												//让p3移向p1指向尾
													px->next=p3;												//让px指向p1所指向的位置
													p1->next=px;												//让p1指向尾为下一个结点
												}		
											if((fp=fopen("save","wb"))==NULL)									//测试打开文件是否成功
												{    
													printf("             文件不存在！按下任意键返回主菜单...");
													getch();    
												}    
											else   
												{     
													do     
														{     
															fwrite(p2,LEN-4,1,fp);						//从fp中写入一个字节为LEN-4的元素到p2
															if(p2->next!=NULL)       p2=p2->next;		//当p2指向尾不为空时将p2移向下一结点		
														}while(p2->next!=NULL);							//当p2指向尾为空时结束循环
													if(p2!=head)   fwrite(p2,LEN-4,1,fp);				//如果p2不指向头，从fp中写入一个字节为LEN-4的元素到p2
												}
											fclose(fp);													//关闭文件fp
											printf("             插入成功！按下任意键继续...");
											getch();													//按任意键跳回
										}    
								}   
							else
								{
									printf("             插入已被取消！按下任意键继续...");
									getch();
								}   break; 
							case 2:printf("             请输入要插入的教师姓名：");						//按姓名插入
							gets(name);																	//从键盘读入插入的教师位置名字
							p1=head;																	//让p1指向头   
							while (strcmp((p1->name),name)!=0)											//若输入插入的名字不存在
								{    
									if (p1->next!=NULL)       p1=p1->next;								//如果p1指向尾不为空，让p1指向下一个结点							
									else    
										{       
											printf("             查找不到相关数据!\n");       break;  
										}   
								}    
							if (strcmp((p1->name),name)==0)												//若输入插入的名字存在
								{
									printf("-----------------------------要插入的信息如下：--------------------------------\n"); 
									printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");   
								    printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,
										p1->workplace,p1->address,p1->phone);   
								    printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");     
									printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",
										p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,
										p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     
									printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");  
									printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,
										p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
									printf("-------------------------------------------------------------------------------\n");  
									printf("             确定插入吗？（y或n）:");      
									scanf("%c",&k);getchar();											//确认是否插入
								}  
							if (k=='y'||k=='Y') 
								{  
									if (strcmp((p1->name),name)==0)											//若插入的名字存在
										{   
											if(p1==head)													//如果插入点为头指针    
												{
													p3=p1->next;											//让p3指向第二个结点头
													p1->next=px;											//让px指向第二个结点头
													px->next=p3;											//让p3指向第二个结点尾
													p2=head;												//让p2指向头
												} 
 
											else if(p1->next==NULL)											//如果插入点为末尾指针     
												{     
												p3=p1;														//让p3指向最后一个结点头
													p1=head;												//让p1指向头
													p2=head;												//让p2指向头
													while(p1->next!=p3)										//当p1指向尾不等于p3时
														{
															p1=p1->next;									//让p1移向下一结点
														}         
													p1=p1->next;											//让p1移向下一结点
													p1->next=px;											//让px指向末结点头
													px->next=NULL;											//让PX指向尾为空
												}    
											else
												{															//如果插入点为中间指针   
													p3=p1;													//让p3指向p1所指向位置
													p1=head;												//让p1指向头
													p2=head;												//让p2指向头
													while(p1->next!=p3)										//当p1指向尾部等于p3时
														{
															p1=p1->next;									//让p1移向下一结点
														}      
													p1=p1->next;											//让p1移向下一结点
													p3=p1->next;											//让p3移向p1指向尾
													px->next=p3;											//让px指向p1所指向的位置
													p1->next=px;											//让p1指向尾为下一个结点
												}      
											if((fp=fopen("save","wb"))==NULL)								//是否正常打开文件
												{     
													printf("             文件不存在！按下任意键返回主菜单...");
													getch();  
												}      
											else    
												{      
													do    
														{      
															fwrite(p2,LEN-4,1,fp);							//从fp中写入一个字节为LEN-4的元素到p2
															if(p2->next!=NULL)       p2=p2->next;			//如果p2指向尾不为空，让p2移向下一结点
														}while(p2->next!=NULL);								//当p2指向尾为空时，结束循环
													if(p2!=head)       fwrite(p2,LEN-4,1,fp);				//如果p2不等于头，从fp中写入一个字节为LEN-4的元素到p2
												}
											fclose(fp);														//关闭文件fp
											printf("             插入成功！按下任意键继续...");
											getch();    
										}    
								}   
							else
								{
									printf("             插入已被取消！按下任意键继续...");
									getch();
								}   break;
							case 3:	printf("             插入已被取消！");
									getch(); break; 
							default :break; 
						}  
					if (i!=3)  
						{   
							printf("\n             继续插入其他教师的信息吗？（y或n）");  
							scanf("%c",&n);getchar();    
						} 
				}while((n=='y'||n=='Y')&&i!=3);																//当n不等于y或Y且当i等于3时结束循环
		}   
	printf("            按下任意键返回主菜单...");
	getch(); 
	getchar(); 
}  



/****************************修改函数*****************************************/
void modify()
	{  
		struct teacher *head,*p1,*p2;  //定义结构体指针head,p1和p2
		int i; //定义整型变量i
		FILE *fp;//定义FILE类型数据指针变量fp
		char m='n',n='n',num2[30]; //定义字符变量m等于n,n等于n,字符数组num2
		p1=head=(struct teacher *)malloc(LEN); //用malloc函数开辟一个长度为结构体变量的空间，让p1的首地址等于head的首地址同时指向它
		if ((head=load())!=NULL) //调用load函数，如果指针head指向load开辟的空间的首地址的返回值不为NULL，执行下面程序
			{  
				do  
					{   
						int num=0;//定义整型变量num等于0
						char name[20];  //定义字符变量name 
						p1=head;  //使p1指向head
						system("cls"); //将频幕清空
						printf("\n\n\n                       >>>>>>>>>>> 修改教师信息 <<<<<<<<<<<\n");//输出“>>>>>>>>>>> 修改教师信息 <<<<<<<<<<<”   
						printf("             *******************************************************\n"); //输出“*******************************************************”
						printf("             *                     1.输入教师号                    *\n"); //输出“1.输入教师号”  
						printf("             *                     2.输入姓名                      *\n");  //输出“2.输入姓名”
						printf("             *                     3.返回上级菜单                  *\n");  //输出“返回上级菜单”
						printf("             *******************************************************\n");  //输出“*******************************************************”
						printf("             请选择修改方式：");//输出“请选择修改方式：”  
						scanf("%d",&i);getchar(); //输入i的值
						while (i<1||i>3)//当i小于1或i大于3 
							{    
								printf("             输入有误!请重新输入:");  //输出“输入有误!请重新输入:”
								scanf("%d",&i);//输入i的值
								getchar();    
							}  
						switch(i) //运用switch语句
							{  
								case 1://当i等于1
									printf("             请输入要修改的教师号："); //输出“请输入要修改的教师号：” 
									scanf("%d",&num);//输入num的值
									getchar(); 
									while (p1->num!=num)  //当指针变量p1的成分num的值不等于num的值
										{   
											if (p1->next!=NULL)//如果指针变量p1的成分指针next不等于NULL       
											p1=p1->next;//指针变量p1的首地址等于指针变量p1的成分指针next所指向的地址   
											else//否则      
												{       
													printf("             查找不到相关数据!\n");//输出“查找不到相关数据!”
													break;  //停止
												} 
										}   
									if (p1->num==num)   //如果指针变量p1的成分num的值等于num的值
										{    
											system("cls");//频幕清空  
											printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统<<<<<\n");//输出“ >>>>>欢迎使用教师工资管理系统<<<<<”   
											printf("----------------------------------原信息如下：---------------------------------\n"); //输出“----------------------------------原信息如下：---------------------------------” 
											printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");//输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”   
											printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); //输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”
											printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
											printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
											printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); //输出“基本工资       津贴         生活补贴       应发工资       实发工资”
											printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); //输出“基本工资       津贴         生活补贴       应发工资       实发工资” 
											printf("-------------------------------------------------------------------------------\n");//输出“-------------------------------------------------------------------------------”  
											printf("             *******************************************************\n");  //输出“*******************************************************”
											printf("             *              1.教师号        2.姓名                 *\n");  //输出“*              1.教师号        2.姓名                 *” 
											printf("             *              3.性别          4.单位名称             *\n");  //输出“*              3.性别          4.单位名称             *”
											printf("             *              5.家庭住址      6.联系电话             *\n");  //输出“*              5.家庭住址      6.联系电话             *”
											printf("             *              7.基本工资      8.津贴                 *\n");  //输出“*              7.基本工资      8.津贴                 *” 
											printf("             *              9.生活补贴      10.应发工资            *\n");  //输出“*              9.生活补贴      10.应发工资            *”
											printf("             *              11.电话费       12.水电费              *\n");  //输出“*              11.电话费       12.水电费              *”  
											printf("             *              13.房租         14.个人所得税          *\n");  //输出“*              13.房租         14.个人所得税          *” 
											printf("             *              15.卫生费       16.公积金              *\n");  //输出“*              15.卫生费       16.公积金              *”
											printf("             *              17.合计公款     18.实发工资            *\n");  //输出“*              17.合计公款     18.实发工资            *”
											printf("             *******************************************************\n");  //输出“*******************************************************” 
											do    
												{    
													printf("             请选择要修改的数据：");//输出“请选择要修改的数据：”    
													scanf("%d",&i);getchar();//输入i的值  
													while (i>18||i<1)  //当i大于18或i小于1时
														{       
															printf("             输入有误！请重新输入:"); //输出“输入有误！请重新输入:” 
															scanf("%d",&i);getchar(); //输入i的值
														}  
													switch(i)//运用switch语句
														{    
															case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break; //当i等于1时，输出“请输入新教师号：”，新的教师号  
															case 2:printf("             请输入新姓名：");gets(p1->name);break; //当i等于2时，输出“请输入新姓名：”，新的姓名
															case 3:printf("             请输入新性别：");gets(p1->sex);break;  //当i等于3时，输出“请输入新姓名：”，新的姓名 
															case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;  //当i等于4时，输出“请输入新姓名：”，新的姓名 
															case 5:printf("             请输入新家庭住址：");gets(p1->address);break;  //当i等于5时，输出“请输入新姓名：”，新的姓名 
															case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break; //当i等于6时，输出“请输入新姓名：”，新的姓名 
															case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break; //当i等于7时，输出“请输入新姓名：”，新的姓名
															case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;  //当i等于8时，输出“请输入新姓名：”，新的姓名
															case 9:printf("             请输入新生活补贴：");gets(num2);p1->de_shenghuobutie=atof(num2);break; //当i等于9时，输出“请输入新姓名：”，新的姓名  
															case 10:printf("             请输入新应发工资：");gets(num2);p1->yingfa_salary=atof(num2);break; //当i等于10时，输出“请输入新姓名：”，新的姓名   
															case 11:printf("             请输入新电话费：");gets(num2);p1->cost_phone=atof(num2);break;  //当i等于11时，输出“请输入新姓名：”，新的姓名   
															case 12:printf("             请输入新水电费：");gets(num2);p1->cost_water_elec=atof(num2);break; //当i等于12时，输出“请输入新姓名：”，新的姓名  
															case 13:printf("             请输入新所房租：");gets(num2);p1->cost_rent=atof(num2);break; //当i等于13时，输出“请输入新姓名：”，新的姓名  
															case 14:printf("             请输入新所得税：");gets(num2);p1->cost_tax=atof(num2);break;  //当i等于14时，输出“请输入新姓名：”，新的姓名
															case 15:printf("             请输入新卫生费：");gets(num2);p1->cost_weisheng=atof(num2);break;//当i等于15时，输出“请输入新姓名：”，新的姓名
															case 16:printf("             请输入新公积金：");gets(num2);p1->cost_gongjijin=atof(num2);break;  //当i等于16时，输出“请输入新姓名：”，新的姓名 
															case 17:printf("             请输入新合计扣费：");gets(num2);p1->cost_all=atof(num2);break; //当i等于17时，输出“请输入新姓名：”，新的姓名  
															case 18:printf("             请输入新实发工资：");gets(num2);p1->shifa_salary=atof(num2);break; //当i等于18时，输出“请输入新姓名：”，新的姓名 
															default:break;    //否则，停止
														}    
													printf("             继续修改其他数据吗？(y或n):");//输出“继续修改其他数据吗？(y或n):”
													scanf("%c",&m);//输入m的值
													getchar();  
												}while (m=='y'||m=='Y');   //当m等于y或Y
											p2=head;    //指针变量p2等于head的首地址
											if ((fp=fopen("save","wb"))==NULL)  //如果以写的方式打开save的文件的返回值为NULL
												{     
													printf("             文件不存在！按下任意键返回主菜单...");//输出“文件不存在！按下任意键返回主菜单...”
													getch();   
												}    
											else //否则   
												{    
													fwrite(head,LEN-4,1,fp);// 以二进制的方式从head的首地址开始写进文件中    
													do  
														{     
															p2=p2->next;  //p2的地址等于p2的成分指针变量next指向的地址
															fwrite(p2,LEN-4,1,fp); // 以二进制的方式从p2的首地址开始写进文件中    
														}while(p2->next!=NULL);  //当p2的成分指针变量next指向的地址不为NULL
													printf("------------------------------修改后数据如下：---------------------------------\n");//输出“------------------------------修改后数据如下：---------------------------------”  
													printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");//输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”   
													printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); //输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”
													printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
													printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
													printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); //输出“基本工资       津贴         生活补贴       应发工资       实发工资”
													printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); //输出“基本工资       津贴         生活补贴       应发工资       实发工资” 
													printf("-------------------------------------------------------------------------------\n");//输出“-------------------------------------------------------------------------------”  
												}   
											fclose(fp); //将文件关闭 
										}break; //停止
								case 2://当i等于2时
									printf("             请输入要修改的教师姓名：");//输出“请输入要修改的教师姓名：” 
									gets(name);   //输入name的值 
									while (strcmp(p1->name,name)!=0)//当p1的成分name不等于输入的name时    
										{    
											if (p1->next!=NULL)//如果p1的成分指针next不为NULL时   
												p1=p1->next;    //p1指向p1的成分next的地址
											else  //否则
												{       
													printf("             查找不到相关数据！\n");//输出“ 查找不到相关数据！”    
													break;    //停止
												} 
										}    
									if (strcmp(p1->name,name)==0)//当p1的成分name等于输入的name时    
										{      
											system("cls");  
											printf("\n\n\n                    >>>>>欢迎使用教师工资管理系统<<<<<\n");//输出“ >>>>>欢迎使用教师工资管理系统<<<<<”   
											printf("----------------------------------原信息如下：---------------------------------\n"); //输出“----------------------------------原信息如下：---------------------------------” 
											printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");//输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”   
											printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); //输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”
											printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
											printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
											printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); //输出“基本工资       津贴         生活补贴       应发工资       实发工资”
											printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); //输出“基本工资       津贴         生活补贴       应发工资       实发工资” 
											printf("-------------------------------------------------------------------------------\n");//输出“-------------------------------------------------------------------------------”  
											printf("             *******************************************************\n");  //输出“*******************************************************”
											printf("             *              1.教师号        2.姓名                 *\n");  //输出“*              1.教师号        2.姓名                 *” 
											printf("             *              3.性别          4.单位名称             *\n");  //输出“*              3.性别          4.单位名称             *”
											printf("             *              5.家庭住址      6.联系电话             *\n");  //输出“*              5.家庭住址      6.联系电话             *”
											printf("             *              7.基本工资      8.津贴                 *\n");  //输出“*              7.基本工资      8.津贴                 *” 
											printf("             *              9.生活补贴      10.应发工资            *\n");  //输出“*              9.生活补贴      10.应发工资            *”
											printf("             *              11.电话费       12.水电费              *\n");  //输出“*              11.电话费       12.水电费              *”  
											printf("             *              13.房租         14.个人所得税          *\n");  //输出“*              13.房租         14.个人所得税          *” 
											printf("             *              15.卫生费       16.公积金              *\n");  //输出“*              15.卫生费       16.公积金              *”
											printf("             *              17.合计公款     18.实发工资            *\n");  //输出“*              17.合计公款     18.实发工资            *”
											printf("             *******************************************************\n");  //输出“*******************************************************” ");   
											do   
												{    
													printf("             请选择要修改的数据："); //输出“请选择要修改的数据：”    
													scanf("%d",&i);getchar();    //输入i的值
													while (i>18||i<1)//当i大于18或i小于1时     
														{    
															printf("             输入有误！请重新输入:");//输出“输入有误！请重新输入:” 
															scanf("%d",&i);//输入i的值
															getchar();   
														}  
													switch(i)  //运用switch语句
														{   
														case 1:printf("             请输入新教师号：");gets(num2);p1->num=atoi(num2);break; //当i等于1时，输出“请输入新教师号：”，新的教师号  
															case 2:printf("             请输入新姓名：");gets(p1->name);break; //当i等于2时，输出“请输入新姓名：”，新的姓名
															case 3:printf("             请输入新性别：");gets(p1->sex);break;  //当i等于3时，输出“请输入新姓名：”，新的姓名 
															case 4:printf("             请输入新单位名称：");gets(p1->workplace);break;  //当i等于4时，输出“请输入新姓名：”，新的姓名 
															case 5:printf("             请输入新家庭住址：");gets(p1->address);break;  //当i等于5时，输出“请输入新姓名：”，新的姓名 
															case 6:printf("             请输入新联系电话：");gets(num2);p1->phone=atoi(num2);break; //当i等于6时，输出“请输入新姓名：”，新的姓名 
															case 7:printf("             请输入新基本工资：");gets(num2);p1->de_salary=atof(num2);break; //当i等于7时，输出“请输入新姓名：”，新的姓名
															case 8:printf("             请输入新津贴：");gets(num2);p1->de_jintie=atof(num2);break;  //当i等于8时，输出“请输入新姓名：”，新的姓名
															case 9:printf("             请输入新生活补贴：");gets(num2);p1->de_shenghuobutie=atof(num2);break; //当i等于9时，输出“请输入新姓名：”，新的姓名  
															case 10:printf("             请输入新应发工资：");gets(num2);p1->yingfa_salary=atof(num2);break; //当i等于10时，输出“请输入新姓名：”，新的姓名   
															case 11:printf("             请输入新电话费：");gets(num2);p1->cost_phone=atof(num2);break;  //当i等于11时，输出“请输入新姓名：”，新的姓名   
															case 12:printf("             请输入新水电费：");gets(num2);p1->cost_water_elec=atof(num2);break; //当i等于12时，输出“请输入新姓名：”，新的姓名  
															case 13:printf("             请输入新所房租：");gets(num2);p1->cost_rent=atof(num2);break; //当i等于13时，输出“请输入新姓名：”，新的姓名  
															case 14:printf("             请输入新所得税：");gets(num2);p1->cost_tax=atof(num2);break;  //当i等于14时，输出“请输入新姓名：”，新的姓名
															case 15:printf("             请输入新卫生费：");gets(num2);p1->cost_weisheng=atof(num2);break;//当i等于15时，输出“请输入新姓名：”，新的姓名
															case 16:printf("             请输入新公积金：");gets(num2);p1->cost_gongjijin=atof(num2);break;  //当i等于16时，输出“请输入新姓名：”，新的姓名 
															case 17:printf("             请输入新合计扣费：");gets(num2);p1->cost_all=atof(num2);break; //当i等于17时，输出“请输入新姓名：”，新的姓名  
															case 18:printf("             请输入新实发工资：");gets(num2);p1->shifa_salary=atof(num2);break; //当i等于18时，输出“请输入新姓名：”，新的姓名 
															default:break;  //否则，停止  
														} 
													printf("             继续修改其他数据吗？(y或n):");  //输出“继续修改其他数据吗？(y或n):” 
													scanf("%c",&m);//输入m的值
													getchar(); 
												}while (m=='y'||m=='Y');  //当m为y或Y时
											p2=head;  //p2指向head的地址
											if((fp=fopen("save","wb"))==NULL)  //如果以写的方式打开save的文件的返回值为NULL   
												{     
													printf("             文件不存在！按下任意键返回主菜单...");//输出“文件不存在！按下任意键返回主菜单...”
													getch();     
												}    
											else   //否则 
												{   
													fwrite(head,LEN-4,1,fp);  // 以二进制的方式从head的首地址开始写进文件中
													do    
														{       
															p2=p2->next;  //p2的地址等于p2的成分指针变量next指向的地址
															fwrite(p2,LEN-4,1,fp); // 以二进制的方式从p2的首地址开始写进文件中  
														}while(p2->next!=NULL); //当p2的成分指针变量next指向的地址不为NULL   
													printf("------------------------------修改后数据如下：---------------------------------\n");//输出“------------------------------修改后数据如下：---------------------------------”  
													printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");//输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”   
													printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone); //输出“教工号     姓名    性别    单位名称            家庭住址          联系电话”
													printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
													printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);//输出“电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款”     
													printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); //输出“基本工资       津贴         生活补贴       应发工资       实发工资”
													printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); //输出“基本工资       津贴         生活补贴       应发工资       实发工资” 
													printf("-------------------------------------------------------------------------------\n");//输出“-------------------------------------------------------------------------------”  
												}     
											fclose(fp);//将文件关闭    
											}break; //停止
								case 3:break;    //当i等于3时，停止
								default :break;  //否则，停止
							} 
							if (i!=3)  //如果i不等于3时 
								{    
									printf("\n             继续修改其他教师的信息吗？（y或n）");//输出“继续修改其他教师的信息吗？（y或n）”  
									scanf("%c",&n);  //输入n的值
								}   
			}while((n=='y'||n=='Y')&&i!=3);//当n为y或Y,且i不等于3时
		} 
	}  
/***************************删除函数*****************************************/
void deletes()
{  
	struct teacher *head,*p1,*p2,*p3; //结构体类型
	int i; 
	char k;
	FILE *fp;//文件指针
	char n='n'; 
	p1=p2=p3=(struct teacher *)malloc(LEN); //申请一块内存，然后使指针p1、p2、p3都指向这块内存
    if((head=load())!=NULL)  //如果头指针读取不等于空，便进行循环
		{  
			do  
				{  
					int num;   
					char name[20]; 
					p1=head;   
					system("cls");  //清除屏幕
					printf("\n\n\n                       >>>>>>>>>>> 删除教师信息 <<<<<<<<<<<\n"); 
					printf("             *******************************************************\n");   
					printf("             *                     1.输入教师号                    *\n");  
					printf("             *                     2.输入姓名                      *\n");  
					printf("             *                     3.返回上级菜单                  *\n");  
					printf("             *******************************************************\n");   
					printf("             请选择删除方式：");   
					scanf("%d",&i);
					getchar();  
					while (i<1||i>3)  
						{     
							printf("             输入有误!请重新输入:"); 
							scanf("%d",&i);
							getchar();  
						}    
					switch(i)   //跟Case一起使用，对i进行判断选择
						{    
							case 1:printf("             请输入要删除的信息的教师号：");     
							scanf("%d",&num);
							getchar();     
							while (p1->num!=num)  //要找的工号不是当前p1所指的结点，那么这个循环就不要再执行下去了 
								{    
									if (p1->next!=NULL)     //如果p1->next不等于空指针，
									p1=p1->next;        //p1->next赋值给p1，使指针向下一个结点移动
									else  
										{      
											printf("             查找不到相关数据!\n");    
											break;   //结束
										}   
								}   
							if (p1->num==num)  
								{    
									printf("-----------------------------要删除的信息如下：--------------------------------\n");  
									printf("教工号  姓名           性别    单位名称            家庭住址          联系电话\n");  
									printf("  %-8d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
									printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");   
									printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf\n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
									printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");  
									printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
									printf("-------------------------------------------------------------------------------\n");  
									printf("             确定删除吗？（y或n）:");   
									scanf("%c",&k);
									getchar();    
								} 
							if (k=='y'||k=='Y')   
								{ 
									if (p1->num==num) 
										{     
	            							if(p1==head)   
												{    
													p1=p1->next;   
													p2=p1;   //使p1和p2指向p1->next，使p2指向下一个结点
												}    
											else if(p1->next==NULL)    
												{     
													p3=p1;
                     								p1=head;
													p2=head;  //使head,p1,p2为空指针
													while(p1->next!=p3)    
														{
															p1=p1->next;
														}    
													p1->next=NULL;    //p1->next为空指针
												}     
											else
												{     
													p2=head;
													p3=p1;
													p1=head;    
													while(p1->next!=p3)   
														{ 
	             											p1=p1->next;
														}     
													p3=p3->next;     
													p1->next=p3;     
												}       
											if((fp=fopen("save","wb"))==NULL)    //打开save文件，并FP指向它，且为空
												{    
													printf("             文件不存在！按下任意键返回主菜单...");
													getch();    
												}    
											else  
												{     
													do   
														{     
															fwrite(p2,LEN-4,1,fp);  //将p2指针指向的内容，写入到fp中，写入记录大小为1个LEN-4结构的字节大小
															if(p2->next!=NULL)     p2=p2->next;  
														}while(p2->next!=NULL);  
													if(p2!=head)     fwrite(p2,LEN-4,1,fp);   
												}
											fclose(fp);    //关闭fp
											printf("             删除成功！按下任意键继续...");
											getch(); 
										}
								}  
							else
								{
									printf("             删除已被取消！按下任意键继续...");
									getch();
								}  break;  
							case 2:printf("             请输入要修改的教师姓名：");   
							gets(name);  
							while (strcmp((p1->name),name)!=0)    
								{      
									if (p1->next!=NULL)    
									p1=p1->next;     
									else    
										{     
											 printf("             查找不到相关数据!\n");   
											 break;    
										}   
								}    
							if (strcmp((p1->name),name)==0)   
								{    
									printf("-----------------------------要删除的信息如下：--------------------------------\n");  
									printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");    
									printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
									printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");  
									printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);    
									printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");     
									printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);  
									printf("-------------------------------------------------------------------------------\n");   
									printf("             确定删除吗？（y或n）:");   
									scanf("%c",&k);getchar();  
								}    
							if (k=='y'||k=='Y')   
								{    
	         						if (strcmp((p1->name),name)==0)   //判断p1所指向的姓名和输入的姓名为真的话，执行一下循环
										{      
		        							if(p1==head)   
												{     
			        								p1=p1->next;   
													p2=p1;
												}    
											else if(p1->next==NULL)    
												{       
													p3=p1;
													p1=head;
													p2=head;    
													while(p1->next!=p3)       
														{ 
															p1=p1->next;
														}     
													p1->next=NULL;   
												}      
											else
												{
												    p2=head;
												    p3=p1;
												    p1=head;     
												    while(p1->next!=p3)      
														{
															p1=p1->next;
														}        
													p3=p3->next;    
													p1->next=p3;      
												}  
											if((fp=fopen("save","wb"))==NULL)   //如果fp指向为空文件
												{    
													printf("             文件不存在！按下任意键返回主菜单...");
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
													if(p2!=head)    fwrite(p2,LEN-4,1,fp);  
												}
											fclose(fp);    
											printf("             删除成功！按下任意键继续...");
											getch();  
										}   
								}    
							else
								{ 
                   					printf("             删除已被取消！按下任意键继续...");
									getch();
								}     break;   
							case 3:break;   
							default :break;   
						}  
					if (i!=3)  
						{   
							printf("\n             继续删除其他教师的信息吗？（y或n）");    scanf("%c",&n);    
						} 
				}while((n=='y'||n=='Y')&&i!=3);
		} 
}
/****************************浏览函数*****************************************/
 void scan()//浏览函数
{
    struct teacher *head,*p1;  
	int i;  
	char m='n'; //定义指针和变量
    p1=head=(struct teacher *)malloc(LEN); //开辟动态空间 
    if((head=load())!=NULL)
	{   
		system("cls"); //清屏
        printf("\n\n\n                       >>>>>>>>>>> 浏览教师信息 <<<<<<<<<<<\n");  
        printf("             *******************************************************\n");  
        printf("             *                     1.全部浏览                      *\n"); 
        printf("             *                     2.单个浏览                      *\n");  
        printf("             *                     3.返回上级菜单                  *\n");  
        printf("             *******************************************************\n"); //显示选择菜单 
        printf("             请输入你想要的操作：");  
        scanf("%d",&i);//从键盘中得到i的值
        getchar();  //有返回的读取键盘中的字符
        while (i<1||i>3)   
		{    
            printf("             输入有误！请重新输入:");  
            scanf("%d",&i);
            getchar(); 
		} 
        switch(i)  //switch函数实现多分选择
		{
		    case 1:p1=head;  
            printf("----------------------------所有保存的信息如下：-------------------------------\n");    
            printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n"); 
            do  
			{   
                printf(" %-4d %-13s %s     %-19s %-19s%-14ld",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);  
                if (p1->next!=NULL)   
				{
                    p1=p1->next;
				}     
				else break;  
			}
            while(1); 
            p1=head; 
            printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");
            do   
			{   
                printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf ",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);     if (p1->next!=NULL) 
				{
					p1=p1->next;
				}   
            else break;   
			}
            while(1);   
            p1=head;
            printf("基本工资       津贴         生活补贴       应发工资       实发工资\n"); 
            do  
			{   
                printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf \n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary); 
                if (p1->next!=NULL)     
				{
					p1=p1->next;
				}     
				else break;   
			}
            while(1);   
            p1=head; 
            printf("\n-------------------------------------------------------------------------------\n");   
            printf("             按下任意键返回主菜单...");  
            getch();
			break; 
            case 2:    
			do   
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
                    scanf("%d",&i);
					getchar();  
				}   
                switch(i)   
				{  
                    case 1:printf("             请输入要查询的教师号：");     
                           scanf("%d",&num);
						   getchar();    
                           while (p1->num!=num)   
						   {      
							   if (p1->next!=NULL)     
                               p1=p1->next;     
                               else      
							   {     
                                   printf("             查找不到相关数据!\n");  
                                   break;    
							   }    
						   }     
                           if (p1->num==num)  
						   {      
							   printf("-------------------------------所查信息如下：----------------------------------\n");    
                               printf("教工号  姓名       性别    单位名称            家庭住址          联系电话\n");   
                               printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);   
                               printf("电话费     水电费     房租     个人所得税     卫生费     公积金     合计扣款\n");    
                               printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);  
                               printf("基本工资       津贴         生活补贴       应发工资       实发工资\n");   
                               printf(" %-13.1lf %-13.1lf %-13.1lf %-13.1lf  %-13.1lf\n",p1->de_salary,p1->de_jintie,p1->de_shenghuobutie,p1->yingfa_salary,p1->shifa_salary);   
                               printf("-------------------------------------------------------------------------------\n");   
						   }     
						   break;   
                           case 2:printf("             请输入要查询的教师姓名：");    
                                  gets(name); 
                                  while (strcmp(p1->name,name)!=0) //比较字符串p1->name和name，当p1->name<name时，返回值<0，当p1->name==name时，返回值=0，当p1->name>name时，返回值>0。
								  {    
                                      if (p1->next!=NULL)   
                                      p1=p1->next;  
                                      else   
									  {  
                                          printf("             查找不到相关数据！\n");       
										  break; 
									  }    
								  }   
                           if (strcmp(p1->name,name)==0)    
						   {     
                               printf("-------------------------------所查信息如下：----------------------------------\n");   
                               printf("教工号  姓名       性别 单位名称          家庭住址            联系电话          \n");  
                               printf("  %-4d %-13s %s     %-19s %-19s%-14ld\n",p1->num,p1->name,p1->sex,p1->workplace,p1->address,p1->phone);    
                               printf("电话费    水电费    房租      个人所得税 卫生费   公积金    合计扣款  \n");  
                               printf(" %-10.1lf %-10.1lf %-10.1lf %-10.1lf   %-10.1lf %-10.1lf %-10.1lf \n",p1->cost_phone,p1->cost_water_elec,p1->cost_rent,p1->cost_tax,p1->cost_weisheng,p1->cost_gongjijin,p1->cost_all);   
                               printf("基本工资     津贴         生活补贴     应发工资     实发工资     \n");    
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
				fprintf(fp,"%-d\t%-s\t%-s\t%-s\t%-s\t%-ld\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\t%-.1lf\n",t->num,t->name,t->sex,t->workplace,t->address,t->phone,t->cost_phone,t->cost_water_elec,t->cost_rent,t->cost_tax,t->cost_weisheng,t->cost_gongjijin,t->cost_all,t->de_salary,t->de_jintie,t->de_shenghuobutie,t->yingfa_salary,t->shifa_salary);
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

  
/*****************************主函数*****************************************/ 
void main()
{  
	int a=1;  
	welcome(); 
	while(1)  
		{  
			system("cls"); 
			a=menu(); 
			switch(a) 
				{ 
					case 1:input();break; 
					case 2:insert();break;
					case 3:modify();break;
					case 4:deletes();break; 
					case 5:scan();break;  
					case 6:sort();break; 
					case 7:printf("             欢迎下次使用！\n");
					getch();
					exit(0);
					break;  
					default :printf("             输入有误，请重新输入!");
					getch();
					break;
				}  
		} 
	getch(); 
}
