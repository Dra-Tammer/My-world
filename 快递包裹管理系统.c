//欢迎使用快递包裹管理系统
//开始进行文件的初始化 
//文件中原有的数据为： 
//*******************************************************************************
//姓名             联系电话        快递单号        收件地址              所在仓库
//huyi             135214632       1001            addressone               1
//wanger           135625365       1012            addresstwo               1
//zhangsan         156655987       1033            addressthree             3
//lisi             145263842       1048            addressfour              8
//sunwu            158935359       1082            addressfive              9
//******************************************************************************* 
//注意：如果在第一级选择目录下输入0即关闭程序 
//管理员登录密码是：123 
//消费者寄出的快递会默认存放在1仓库，而后等待管理员根据寄往地区进行分配 
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Consumer)
int n=5;
int i=0,j=0;
int choise; 
int password;
void print_the_report();//打印报表 
void transition();//加载条模拟 
void firt_open();//打开时的欢迎界面 
void loading_begin();//加载界面 
void loading_begin_success();//加载成功的界面 
void selection();//第一级选择目录 
void Revisit();//欢迎再次访问系统 
void out_port_right();//消费者取快递快递成功出库 
void in_port_right();//消费者寄快递快递成功入库 
void find_num();//通过快递号查询快递信息 
void modify();//管理员修改信息 
void administrator_mode();//管理员选择目录即第二级选择目录 
void read_the_file();//文件的读取 
void input_print_report();//打印修改后的内容 
void write_the_file();//文件的写入 
void password_right_selection();//当访问管理员选择目录时，进行密码的检验，简单表示 
struct Consumer *source_insert (struct Consumer *head );//管理员进行插入插入操作 
struct Consumer *p,*head;//贯穿全系统的很关键的两个结构体指针变量 
struct Consumer *consumer_del(struct Consumer *head );//消费者取快递 
struct Consumer *del(struct Consumer *head );//管理员进行数据的删除操作 
struct Consumer *insert (struct Consumer *head);//消费者寄快递 
struct Consumer
{   
    char name[20];
    long tele;
	long num;
	char address[20];
	int location;
	struct Consumer *next; 
}con[20]={{"huyi",135214632,1001,"addressone",1},{"wanger",135625365,1012,"addresstwo",1},{"zhangsan",156655987,1033,"addressthree",3},{"lisi",145263842,1048,"addressfour",8},{"sunwu",158935359,1082,"addressfive",9}};
int main()
{
//初始化程序// 
//***************************************************//	
    head=&con[0]; 
	for(i=0;i<4;i++)
	con[i].next=&con[i+1];
	p=head;
	con[4].next=NULL;
    write_the_file();
//***************************************************//
firt_open();
transition();
loading_begin();
transition();
loading_begin_success();
do
{ 

transition();
selection();
choise=0; 
printf("您的决定：");//注意如果第一级目录下输入0即关闭程序 
scanf("%d",&choise);//第一级选择目录 
		switch (choise)
		{   case 0:
			    transition();
			    Revisit(); 
			    return;
			case 1:
			    source_insert(head);//消费者寄快递 
			    transition();
	            in_port_right();
				break;
			case 2:
				consumer_del(head);//消费者取快递 
				break;
			case 3:
				password_right_selection();//管理员模式
				 
				break;
			case 4:
				find_num();//通过快递号进行数据的查找 
				break;
			default:
				break;
		}
}while(1); //用于重新启动选择界面 
return 0;
}
void password_right_selection()//当访问管理员选择目录时，进行密码的检验 
{
	printf("请输入管理员密码：\n");
	scanf("%d",&password);
	if(password==123)
	{
	transition();
	printf("**密码正确！**\n");
	transition();
    administrator_mode();
    }
    else 
    
	{
	transition();
    printf("**密码输入错误，重新访问系统!**\n");}
}
struct Consumer *source_insert (struct Consumer *head )	//消费者寄送快递 
{
	struct Consumer *add;
	add=(struct Consumer*)malloc(LEN);
	printf("请按**姓名-电话号码-快递号-寄件地址**格式输入信息：\n");
	scanf("%s %ld %ld %s",&add->name,&add->tele,&add->num,&add->address);
	add->location=1;
	struct Consumer *p0,*p1,*p2;
	p1=head;
	p0=add;
	if (head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else 
	{
		while ((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
			head=p0;
			else p2->next=p0;
			p0->next=p1;
		}
		else 
		{
			p1->next=p0;
			p0->next=NULL;
		}
		n=n+1;
		p=head;
		write_the_file();
		return (head);
	}
}	
void read_the_file()//进行数据文件的读入操作 
{
	FILE *fp1;
	int j=0;
	if((fp1=fopen("快递人员信息","r"))==NULL)
	{
		printf("cannot open file.\n");
		return;
	}
	printf("\n所有快递的信息为：\n");
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	for (i=0;fread(&con[i],sizeof(struct Consumer),1,fp1)!=0;i++)
	{
		printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",con[i].name,con[i].tele,con[i].num,con[i].address,con[i].location);
	}
	printf("*******************************************************************************\n");
	fclose(fp1);		

}
void write_the_file()//进行数据的写入操作 
{
	FILE *fp;
	if((fp=fopen("快递人员信息","w"))==NULL)
	{
		printf("can not open file.");
		return;
	}
	do
    {
    if(fwrite(p,sizeof(struct Consumer),1,fp)!=1)
	printf("error!\n");
	p=p->next;
    }
	while(p!=NULL);
	fclose(fp);
}
void input_print_report()//打印修改后数据内容 
{
	p=head;
	transition();
	printf("当前数据库已更新为；\n");
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	do
	{
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p->name,p->tele,p->num,p->address,p->location);
	p=p->next;
	}while (p!=NULL);
	printf("*******************************************************************************\n");
}
void firt_open()//开始的欢迎界面 
{
int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**          欢迎进入快递包裹管理系统          **\n");
   else if(welcome==5)printf("**  小组成员：方坤 冯胜龙 刘旭 叶顾玮豪 宋森  **\n");
   else	if(welcome==7)printf("**                  计卓一班                  **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void loading_begin()//加载中的界面 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**             loading...........             **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void loading_begin_success()//加载成功的界面 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**         System login succeeded !           **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void selection()//选择界面 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**            请选择您需要的服务              **\n");
   else if(welcome==5)printf("**    1.寄快递                 2.取快递       **\n");
   else	if(welcome==7)printf("**    3.管理员模式             4.查询         **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void out_port_right()//成功出库的界面
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**            您的快递已成功出库！            **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 
void in_port_right()//成功入库的界面 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**            您的快递已成功入库！            **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 	
void Revisit()//退出时的页面 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**             欢迎再次访问系统!              **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 		
void administrator_mode()//管理员选择界面 
{
	int welcome;//第二级选择目录 
	for(welcome=0;welcome<=10;welcome++) 
		if(welcome==3)printf("**               请选择服务：                 **\n");
   else if(welcome==5)printf("**    1.打印报表           2.数据删除         **\n");
   else	if(welcome==7)printf("**    3.数据修改           4.数据添加         **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
   choise=0; 
   printf("您的决定：");
   scanf("%d",&choise);
		switch (choise)
		{
			case 1:
				print_the_report();
				break;
			case 2:
				del(head);
				break;
			case 3:
				modify(); 
				break;
			case 4:
				head=insert (head);
				p=head;
				write_the_file();
	            read_the_file();
				break;
			default:
				break;
		}
}	
void print_the_report()//打印报表 
{
	struct Consumer *p,*head;
	head=&con[0]; 
	for(i=0;i<4;i++)
	con[i].next=&con[i+1];
	p=head;
	con[5].next=NULL;
	transition();
	read_the_file();
}	
struct Consumer *insert (struct Consumer *head )//管理员进行快递信息的录入 
{
	struct Consumer *add;
	add=(struct Consumer*)malloc(LEN);
	printf("请按**姓名-电话号码-快递号-寄件地址-存储仓库**格式输入信息：\n");
	scanf("%s %ld %ld %s %d",&add->name,&add->tele,&add->num,&add->address,&add->location);
	struct Consumer *p0,*p1,*p2;
	p1=head;
	p0=add;
	if (head==NULL)
	{
		head=p0;
		p0->next=NULL;
	}
	else 
	{
		while ((p0->num>p1->num)&&(p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p0->num<=p1->num)
		{
			if(head==p1)
			head=p0;
			else p2->next=p0;
			p0->next=p1;
		}
		else 
		{
			p1->next=p0;
			p0->next=NULL;
		}
		n=n+1;
		p=head;
		write_the_file();
		return (head);
	}
}	
struct Consumer *del(struct Consumer *head )//管理员进行数据的删除 
{
	long num;
	printf("Input the deleted number :");
	scanf("%ld",&num);
	struct Consumer *p1,*p2;
	if (head==NULL)
	{
		printf("\nlist null!\n");
		return (head);
	}
	p1=head;
	while (num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if (p1==head)
		head=p1->next;
		else p2->next=p1->next;
		printf("delete :%ld\n",num);
		n=n-1;
	}
	else printf("%ld not been found !\n",num); 
	transition();
	printf("数据库已更新为：\n");
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	p=head;
	do
	{
		printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p->name,p->tele,p->num,p->address,p->location);
		p=p->next;
	} while (p!=NULL);
	printf("*******************************************************************************\n"); 
	p=head;
	write_the_file();
	transition();
	Revisit();	
	return (head);	
} 
struct Consumer *consumer_del(struct Consumer *head )//消费者取快递 
{
	long num;
	printf("Input the taken-out number :");
	scanf("%ld",&num);	
	struct Consumer *p1,*p2;
	if (head==NULL)
	{
		printf("\nlist null!\n");
		return (head);
	}
	p1=head;
	while (num!=p1->num&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(num==p1->num)
	{
		if (p1==head)
		head=p1->next;
		else p2->next=p1->next;
		printf("taken-out::%ld\n",num);
		n=n-1;
	}
	else printf("%ld not been found !\n",num);
	for(i=0;i<n-1;i++)
	con[i].next=&con[i+1];
	p=head;
	con[n].next=NULL;
	transition();
    out_port_right();
	write_the_file();
	return (head);	
} 
void find_num()//通过快递号查找信息 
{   
	long num;
    printf("Please input the found number:\n");
    scanf("%ld",&num);
    struct Consumer *p1;
    p1=head;
    while (num!=p1->num&&p1->next!=NULL)
{
	p1=p1->next;
}
    if (num==p1->num)
{
	printf("这是您要查询的信息：\n");
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
	return;
}
else 
    transition(); 
    printf("数据库里没有您查找的快递信息\n请核实您输入是否有误！\n请在重启系统后再次查找！\n");
}	
void modify()//修改程序 
{   
    p=head;
    read_the_file();
	printf("请输入需要修改信息的快递编号：\n");
    long num;
    scanf("%ld",&num);
    transition();
    struct Consumer *p1,*p2;
    p1=head;
    while (num!=p1->num&&p1->next!=NULL)
{
    p2=p1;
	p1=p1->next;
}
    if (num==p1->num)
{   
    printf("这是该快递的原始信息：\n"); 
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
    printf("请输入修改后的内容：\n");
    scanf("%s %ld %ld %s %d",&p1->name,&p1->tele,&p1->num,&p1->address,&p1->location); 
    transition();
    printf("这是修改后的内容：\n");
	printf("*******************************************************************************\n");
	printf("姓名\t         联系电话\t 快递单号\t 收件地址\t       所在仓库\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
	p=head;
	write_the_file();
	transition();	
    printf("**修改成功！**\n"); 

}
}
void transition()//加载条的模拟 
{
   int i=0;
   for (i=0;i<=5;i++)
   printf("_\n");	
} 

