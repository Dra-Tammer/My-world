//��ӭʹ�ÿ�ݰ�������ϵͳ
//��ʼ�����ļ��ĳ�ʼ�� 
//�ļ���ԭ�е�����Ϊ�� 
//*******************************************************************************
//����             ��ϵ�绰        ��ݵ���        �ռ���ַ              ���ڲֿ�
//huyi             135214632       1001            addressone               1
//wanger           135625365       1012            addresstwo               1
//zhangsan         156655987       1033            addressthree             3
//lisi             145263842       1048            addressfour              8
//sunwu            158935359       1082            addressfive              9
//******************************************************************************* 
//ע�⣺����ڵ�һ��ѡ��Ŀ¼������0���رճ��� 
//����Ա��¼�����ǣ�123 
//�����߼ĳ��Ŀ�ݻ�Ĭ�ϴ����1�ֿ⣬����ȴ�����Ա���ݼ����������з��� 
#include<stdio.h>
#include<malloc.h>
#define LEN sizeof(struct Consumer)
int n=5;
int i=0,j=0;
int choise; 
int password;
void print_the_report();//��ӡ���� 
void transition();//������ģ�� 
void firt_open();//��ʱ�Ļ�ӭ���� 
void loading_begin();//���ؽ��� 
void loading_begin_success();//���سɹ��Ľ��� 
void selection();//��һ��ѡ��Ŀ¼ 
void Revisit();//��ӭ�ٴη���ϵͳ 
void out_port_right();//������ȡ��ݿ�ݳɹ����� 
void in_port_right();//�����߼Ŀ�ݿ�ݳɹ���� 
void find_num();//ͨ����ݺŲ�ѯ�����Ϣ 
void modify();//����Ա�޸���Ϣ 
void administrator_mode();//����Աѡ��Ŀ¼���ڶ���ѡ��Ŀ¼ 
void read_the_file();//�ļ��Ķ�ȡ 
void input_print_report();//��ӡ�޸ĺ������ 
void write_the_file();//�ļ���д�� 
void password_right_selection();//�����ʹ���Աѡ��Ŀ¼ʱ����������ļ��飬�򵥱�ʾ 
struct Consumer *source_insert (struct Consumer *head );//����Ա���в��������� 
struct Consumer *p,*head;//�ᴩȫϵͳ�ĺܹؼ��������ṹ��ָ����� 
struct Consumer *consumer_del(struct Consumer *head );//������ȡ��� 
struct Consumer *del(struct Consumer *head );//����Ա�������ݵ�ɾ������ 
struct Consumer *insert (struct Consumer *head);//�����߼Ŀ�� 
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
//��ʼ������// 
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
printf("���ľ�����");//ע�������һ��Ŀ¼������0���رճ��� 
scanf("%d",&choise);//��һ��ѡ��Ŀ¼ 
		switch (choise)
		{   case 0:
			    transition();
			    Revisit(); 
			    return;
			case 1:
			    source_insert(head);//�����߼Ŀ�� 
			    transition();
	            in_port_right();
				break;
			case 2:
				consumer_del(head);//������ȡ��� 
				break;
			case 3:
				password_right_selection();//����Աģʽ
				 
				break;
			case 4:
				find_num();//ͨ����ݺŽ������ݵĲ��� 
				break;
			default:
				break;
		}
}while(1); //������������ѡ����� 
return 0;
}
void password_right_selection()//�����ʹ���Աѡ��Ŀ¼ʱ����������ļ��� 
{
	printf("���������Ա���룺\n");
	scanf("%d",&password);
	if(password==123)
	{
	transition();
	printf("**������ȷ��**\n");
	transition();
    administrator_mode();
    }
    else 
    
	{
	transition();
    printf("**��������������·���ϵͳ!**\n");}
}
struct Consumer *source_insert (struct Consumer *head )	//�����߼��Ϳ�� 
{
	struct Consumer *add;
	add=(struct Consumer*)malloc(LEN);
	printf("�밴**����-�绰����-��ݺ�-�ļ���ַ**��ʽ������Ϣ��\n");
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
void read_the_file()//���������ļ��Ķ������ 
{
	FILE *fp1;
	int j=0;
	if((fp1=fopen("�����Ա��Ϣ","r"))==NULL)
	{
		printf("cannot open file.\n");
		return;
	}
	printf("\n���п�ݵ���ϢΪ��\n");
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
	for (i=0;fread(&con[i],sizeof(struct Consumer),1,fp1)!=0;i++)
	{
		printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",con[i].name,con[i].tele,con[i].num,con[i].address,con[i].location);
	}
	printf("*******************************************************************************\n");
	fclose(fp1);		

}
void write_the_file()//�������ݵ�д����� 
{
	FILE *fp;
	if((fp=fopen("�����Ա��Ϣ","w"))==NULL)
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
void input_print_report()//��ӡ�޸ĺ��������� 
{
	p=head;
	transition();
	printf("��ǰ���ݿ��Ѹ���Ϊ��\n");
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
	do
	{
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p->name,p->tele,p->num,p->address,p->location);
	p=p->next;
	}while (p!=NULL);
	printf("*******************************************************************************\n");
}
void firt_open()//��ʼ�Ļ�ӭ���� 
{
int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**          ��ӭ�����ݰ�������ϵͳ          **\n");
   else if(welcome==5)printf("**  С���Ա������ ��ʤ�� ���� Ҷ����� ��ɭ  **\n");
   else	if(welcome==7)printf("**                  ��׿һ��                  **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void loading_begin()//�����еĽ��� 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**             loading...........             **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void loading_begin_success()//���سɹ��Ľ��� 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**         System login succeeded !           **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void selection()//ѡ����� 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**            ��ѡ������Ҫ�ķ���              **\n");
   else if(welcome==5)printf("**    1.�Ŀ��                 2.ȡ���       **\n");
   else	if(welcome==7)printf("**    3.����Աģʽ             4.��ѯ         **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
}
void out_port_right()//�ɹ�����Ľ���
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**            ���Ŀ���ѳɹ����⣡            **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 
void in_port_right()//�ɹ����Ľ��� 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**            ���Ŀ���ѳɹ���⣡            **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 	
void Revisit()//�˳�ʱ��ҳ�� 
{
	int welcome;
	for(welcome=0;welcome<=10;welcome++)
		if(welcome==3)printf("**                                            **\n");
   else if(welcome==5)printf("**             ��ӭ�ٴη���ϵͳ!              **\n");
   else	if(welcome==7)printf("**                                            **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
} 		
void administrator_mode()//����Աѡ����� 
{
	int welcome;//�ڶ���ѡ��Ŀ¼ 
	for(welcome=0;welcome<=10;welcome++) 
		if(welcome==3)printf("**               ��ѡ�����                 **\n");
   else if(welcome==5)printf("**    1.��ӡ����           2.����ɾ��         **\n");
   else	if(welcome==7)printf("**    3.�����޸�           4.�������         **\n");
   else if(welcome==0||welcome==10)printf("************************************************\n");
   else printf              ("**                                            **\n");	
   choise=0; 
   printf("���ľ�����");
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
void print_the_report()//��ӡ���� 
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
struct Consumer *insert (struct Consumer *head )//����Ա���п����Ϣ��¼�� 
{
	struct Consumer *add;
	add=(struct Consumer*)malloc(LEN);
	printf("�밴**����-�绰����-��ݺ�-�ļ���ַ-�洢�ֿ�**��ʽ������Ϣ��\n");
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
struct Consumer *del(struct Consumer *head )//����Ա�������ݵ�ɾ�� 
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
	printf("���ݿ��Ѹ���Ϊ��\n");
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
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
struct Consumer *consumer_del(struct Consumer *head )//������ȡ��� 
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
void find_num()//ͨ����ݺŲ�����Ϣ 
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
	printf("������Ҫ��ѯ����Ϣ��\n");
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
	return;
}
else 
    transition(); 
    printf("���ݿ���û�������ҵĿ����Ϣ\n���ʵ�������Ƿ�����\n��������ϵͳ���ٴβ��ң�\n");
}	
void modify()//�޸ĳ��� 
{   
    p=head;
    read_the_file();
	printf("��������Ҫ�޸���Ϣ�Ŀ�ݱ�ţ�\n");
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
    printf("���Ǹÿ�ݵ�ԭʼ��Ϣ��\n"); 
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
    printf("�������޸ĺ�����ݣ�\n");
    scanf("%s %ld %ld %s %d",&p1->name,&p1->tele,&p1->num,&p1->address,&p1->location); 
    transition();
    printf("�����޸ĺ�����ݣ�\n");
	printf("*******************************************************************************\n");
	printf("����\t         ��ϵ�绰\t ��ݵ���\t �ռ���ַ\t       ���ڲֿ�\t\n");
	printf("%-10s\t %8ld\t %-10ld\t %-10s\t %10d\n",p1->name,p1->tele,p1->num,p1->address,p1->location);
	printf("*******************************************************************************\n");
	p=head;
	write_the_file();
	transition();	
    printf("**�޸ĳɹ���**\n"); 

}
}
void transition()//��������ģ�� 
{
   int i=0;
   for (i=0;i<=5;i++)
   printf("_\n");	
} 

