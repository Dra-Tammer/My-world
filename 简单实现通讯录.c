#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct MailList)
int n=3;
struct MailList *p, *head; 
void print_report();//打印报表
struct MailList *MailInsert(struct MailList *head); 
struct MailList *MailDelete(struct MailList *head);
void find_by_id();
int i=0; 

struct MailList
{
    char name[20];
    long long tele;
    long id;
    struct MailList *next;
} mail[20] = {{"zhangsan", 18798989898, 100}, {"lisi", 18798989898, 101}, {"wangwu", 18798989898, 102}};

int main()
{
    //初始化数据
    head = &mail[0];
    for(i = 0; i < 3; i++)
    {
        mail[i].next = &mail[i + 1];
    }
    p = head;
    mail[3].next = NULL;
    //初始化的结束
    //打印初始化后的报表
    print_report();
    printf("数据的添加操作\n");
    head=MailInsert(head);
    printf("添加成功！\n");
    printf("数据的删除操作\n");
    head=MailDelete(head);
    print_report(); 
    printf("数据删除成功！\n");
    printf("查询操作：\n");
    find_by_id();
    printf("查询操作结束\n");
    printf("链表的销毁操作：\n");
    head=NULL;
    printf("嘿嘿，删库跑路\n");

    return 0;
}


//打印表中的数据
void print_report()
{
    p=head;
    printf("******************\n");
    do
    {
        printf("%-10s\t %8ld\t %-10ld\t\n",p->name,p->tele,p->id);
        p=p->next;
    } while (p->next!=NULL);
    printf("******************\n");
}

//插入
struct MailList *MailInsert(struct MailList *head)
{
    struct MailList *add;
    add=(struct MailList*)malloc(LEN);
    printf("姓名，电话号码，id\n");
    scanf("%s %ld %ld",&add->name,&add->tele,&add->id);
    struct MailList *p0,*p1,*p2;
    p1=head;
    p0=add;
    if(head==NULL)
    {
        head=p0;
        p0->next=NULL;
    } else {
        while((p0->id>p1->id)&&(p1->next!=NULL))
        {
            p2=p1;
            p1=p1->next;
        }
        if(p0->id<=p0->id)
        {
            if(head==p1)
            head=p0;
            else p2->next=p0;
            p0->next=p1;
        } else {
            p1->next=p0;
            p0->next=NULL;
        }
        n=n+1;
        p=head;
        return(head);
    }
}

//删除
struct MailList *MailDelete(struct MailList *head) 
{
	long num;
	printf("Input the deleted id:\n");
	scanf("%ld",&num);
	struct MailList *p1,*p2;
	if(head==NULL)
	{
	  printf("\nlist null!\n");
      return (head);
	}
	p1=head;
	while (num!=p1->id&&p1->next!=NULL)
   {
      p2=p1;
      p1=p1->next;
   }
   if(num==p1->id)
   {
      if (p1==head)
      head=p1->next;
      else p2->next=p1->next;
      printf("delete :%ld\n",num);
      n=n-1;
   }
   else printf("%ld not been found !\n",num); 
   return (head);
   
}

//通过id查询 
void find_by_id()
{
   long num;
   printf("Please input the found number:\n");
   scanf("%ld",&num);
   struct MailList *p1;
   p1=head;
   while(num!=p1->id&&p1->next!=NULL)  
   {
   	p1=p1->next;
   }
   if(num==p1->id)
   {
   	printf("这是要查询的信息：\n");
   	printf("%-10s\t %8ld\t %-10ld\t\n",p1->name,p1->tele,p1->id);
   	return;
   }
   else
   printf("没有要查的信息");
}



















