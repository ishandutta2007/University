#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

//*(p).num=p->num!!

/*void PrintData(LIB *p);	//打印输出单链表pp中的学生信息
LIB Add(LIB *p,LIB *o );		//在单链表l中增加学生记录的节点
void Qur( LIB *p,int o);		//在单链表l中按学号或姓名查找满足条件的学生记录，并输出显示
LIB Del(LIB *p,int o );		//在单链表l中按学号或姓名查找满足条件的学生记录，并删除该节点
//LIB Modify( );//修改单链表l中某条学生的记录信息
//LIB Count( );	//在单链表l中完成学生信息的统计工作，如统计该班总分第一名、单科第一名和各科不及格人数等。
LIB Sort(LIB *p );	//对单链表l中的学生按某条件（如，总分）的降序排序。
//LIB Save( );		//将单链表l中的数据写入磁盘中的数据文件Stu_Score.txt
*/
typedef struct student  //建立链表结构 
{
    int num;			//学号
	char name[15];		//姓名
	int cgrade;			//c语言成绩
	int mgrade;			//数学成绩
	int egrade;			//英语成绩
	int total;				//总分
	float ave;			//平均分
	struct student *next;
}stu;

typedef struct node												/*单链表节点结构体*/	
{
	struct student data;										//student类型学生信息，数据域
	struct node *next;											//链表后继节点地址，指针域
}node;	
node *head;		  												//node类型指针变量headptr

node *Link()
{
    node *head;
	return head;	
}

void Creat(node *head) //建立学生链表 
{	
    node *p1,*p2;
    int n,l;
    printf("请输入学生人数");
    scanf("%d",&l);
	printf("##请按照顺序添加学生信息#如下↓↓↓↓↓\n");
	printf("##依次输入学号***姓名***C语言成绩***数学成绩***英语成绩##\n");
	p1=(node*)malloc(sizeof(node));
	p1=head;
	n=1;
	scanf("%d%s%d%d%d",&p1->data.num,p1->data.name,&p1->data.cgrade,&p1->data.mgrade,&p1->data.egrade); 
	p1->data.total=p1->data.cgrade+p1->data.mgrade+p1->data.egrade;
	p1->data.ave=p1->data.total/3.0;     
     while(n<l)
     {
         p2=(node*)malloc(sizeof(node));
         p2->next=NULL;
         p1->next=p2;
         p1=p2;                   
         scanf("%d%s%d%d%d",&p1->data.num,p1->data.name,&p1->data.cgrade,&p1->data.mgrade,&p1->data.egrade); 
		 p1->data.total=p1->data.cgrade+p1->data.mgrade+p1->data.egrade;
		 p1->data.ave=p1->data.total/3.0;
		 n++;                                                                  
     }
     p1->next=NULL;
}

void PrintData(node *head) //显示数据//
{		
        node *p;
        p=head;
        printf("依次:学号 姓名 C语言成绩 数学成绩 英语成绩 总分 平均分:\n");
		if(p==NULL) 
		printf("List NULL\n");
		else
		while(p!=NULL)
		{ 
		printf("%d	%s	%d	%d	%d	%d	%.2f\n",p->data.num,p->data.name,p->data.cgrade,p->data.mgrade,p->data.egrade,p->data.total,p->data.ave);
		p=p->next;
		}
}

void Count(node *head)						//统计函数 
{
	node *p;
	p=head;
	int i=0,cmax,mmax,emax,c60=0,m60=0,e60=0;
	float cave=0,mave=0,eave=0;	              //max对应最大，ave对应平均，60对应不及格 
	cmax=p->data.cgrade;mmax=p->data.mgrade;emax=p->data.egrade;	//默认链表第一个节点最大 	
	cave=cave+p->data.cgrade;mave=mave+p->data.mgrade;eave=eave+p->data.egrade;		
	if(p->data.cgrade<60)
	{
		c60++;
	}
	if(p->data.mgrade<60)
	{
			m60++;
	}
	if(p->data.egrade<60)
	{
			e60++;
	}
	p=p->next;
	i++;
		while(p)
{
		if(p->data.cgrade>cmax)
		{
			cmax=p->data.cgrade;
		}
		if(p->data.mgrade>mmax)
		{
			mmax=p->data.mgrade;
		}
		if(p->data.egrade>emax)
		{
			emax=p->data.egrade;
		}
		cave=cave+p->data.cgrade;
		mave=mave+p->data.mgrade;
		eave=eave+p->data.egrade;
		
		if(p->data.cgrade<60)
		{
			c60++;
		}
		 if(p->data.mgrade<60)
		{
			m60++;
		}
		if(p->data.egrade<60)
		{
			e60++;
		}
		    p=p->next;
			i++;
}

	cave=cave/i;mave=mave/i;eave=eave/i;
	
	printf("学生人数是：%d\n",i);
	printf("C语言成绩最高分为：%d\n",cmax);
	printf("数学成绩最高分为：%d\n",mmax);
	printf("英语成绩最高分为：%d\n",emax);
	printf("C语言成绩平均分为：%.2f\n",cave);
	printf("数学成绩平均分为：%.2f\n",mave);
	printf("英语成绩平均分为：%.2f\n",eave);
	printf("C语言成绩不及格人数为：%d\n",c60);
	printf("数学成绩不及格人数为：%d\n",m60);
	printf("英语成绩不及格人数为：%d\n",e60);	
}

/*void Add(node *head)     //添加学生信息函数 
{
     node *p,*s;
     p=head;
     double num1;
     printf("请输入添加的学生的学号\n");
     scanf("%d",&num1);
     if(num1<(p->data.num))
     
	 {
	 s=(node *)malloc(sizeof(node));;
	 s->next=head->next;
	 head->next=s;
     }
     else
	 { 
	 do
     p=p->next;
     //while(num1>(p->next->data.num)&&num1<(p->next->data)||p->next==NULL);
     if(p->next==NULL)
     {
     	s=(node *)malloc(sizeof(node));
     	s=p->next;
		s->next=NULL; 
	 }
     else
     {
     	s=(node *)malloc(sizeof(node));
     	s->next=p->next;
     	p->next=s;
	 }
     }
}*/ 

void Del(node *head)
{
   node *p,*q;
   p=head;
   char a[10],b[15];
   int n,N;
   N=n-'0';
   printf("按1选择学号查询按2选择姓名查询\n");
   scanf("%d",&n);
   switch(N)
   {
      case 1: scanf("%s",&a);break;     
      case 2: scanf("%s",&b);break;     
   }  
   do
   {
   p=p->next;
   }
   while((p->data.num==a)||(strcmp(p->next->data.name,b)==0)||p->next==NULL);
   {
   if(p->next!=NULL)
   {
      q=p->next;
      p->next=q->next;
      free(q);
   }
   else printf("没有找到相关信息"); 
}
}
			 

/*LIB InsertT(LIB *p,LIB *o)
{		LIB *head=p,*q;
		p->total=(p->cgrade)+(p->mgrade)+(p->egrade);o->total=(p->cgrade)+(p->mgrade)+(p->egrade);
		p->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;o->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;
		if(p==0)
		{head=o;o->next=0;}
		else
		 if((o->total)>(p->total))
			{ head=o;o->next=p;}
		 else
		 	{
			 while((o->total)<(p->total))
		 	    {q=p;p=p->next;}
		 	 if(p->next==0)
		 	 {p->next=o;o->next=0;}
		 	 else
		 	 {q->next=o;o->next=p;}
		     }	
}
LIB SortT(LIB *head)
{		LIB *p,*q;
		if(head==0)
		p=head;head=0;
		while(p!=0)
		{  
		q=p;
		p=p->next;
		head=InsertT(head,q);
		}
		
}

LIB InsertA(LIB *p,LIB *o)
{		LIB *head=p,*q;
		p->total=(p->cgrade)+(p->mgrade)+(p->egrade);o->total=(p->cgrade)+(p->mgrade)+(p->egrade);
		p->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;o->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;
		if(p==0)
		{head=o;o->next=0;}
		else
		 if((o->ave)>(p->ave))
			{ head=o;o->next=p;}
		 else
		 	{
			 while((o->ave)<(p->ave))
		 	    {q=p;p=p->next;}
		 	 if(p->next==0)
		 	 {p->next=o;o->next=0;}
		 	 else
		 	 {q->next=o;o->next=p;}
		     }
		 return head;	
}
LIB SortA(LIB *head)
{		LIB *p,*q;
		if(head==0)
		return head;
		p=head;head=0;
		while(p!=0)
		{  q=p;p=p->next;head=InsertA(head,q);}
		return head;
		
}

LIB InsertC(LIB *p,LIB *o)
{		LIB *head=p,*q;
		p->total=(p->cgrade)+(p->mgrade)+(p->egrade);o->total=(p->cgrade)+(p->mgrade)+(p->egrade);
		p->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;o->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;
		if(p==0)
		{head=o;o->next=0;}
		else
		 if((o->cgrade)>(p->cgrade))
			{ head=o;o->next=p;}
		 else
		 	{
			 while((o->cgrade)<(p->cgrade))
		 	    {q=p;p=p->next;}
		 	 if(p->next==0)
		 	 {p->next=o;o->next=0;}
		 	 else
		 	 {q->next=o;o->next=p;}
		     }
		 return head;	
}
LIB SortC(LIB *head)
{		LIB *p,*q;
		if(head==0)
		return head;
		p=head;head=0;
		while(p!=0)
		{  q=p;p=p->next;head=InsertC(head,q);}
		return head;
		
}


LIB InsertM(LIB *p,LIB *o)
{		LIB *head=p,*q;
		p->total=(p->cgrade)+(p->mgrade)+(p->egrade);o->total=(p->cgrade)+(p->mgrade)+(p->egrade);
		p->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;o->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;
		if(p==0)
		{head=o;o->next=0;}
		else
		 if((o->mgrade)>(p->mgrade))
			{ head=o;o->next=p;}
		 else
		 	{
			 while((o->mgrade)<(p->mgrade))
		 	    {q=p;p=p->next;}
		 	 if(p->next==0)
		 	 {p->next=o;o->next=0;}
		 	 else
		 	 {q->next=o;o->next=p;}
		     }
		 return head;	
}
LIB SortM(LIB *head)
{		LIB *p,*q;
		if(head==0)
		return head;
		p=head;head=0;
		while(p!=0)
		{  q=p;p=p->next;head=InsertM(head,q);}
		return head;
		
}



LIB InsertE(LIB *p,LIB *o)
{		LIB *head=p,*q;
		p->total=(p->cgrade)+(p->mgrade)+(p->egrade);o->total=(p->cgrade)+(p->mgrade)+(p->egrade);
		p->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;o->ave=((p->cgrade)+(p->mgrade)+(p->egrade))/3;
		if(p==0)
		{head=o;o->next=0;}
		else
		 if((o->egrade)>(p->egrade))
			{ head=o;o->next=p;}
		 else
		 	{
			 while((o->egrade)<(p->egrade))
		 	    {q=p;p=p->next;}
		 	 if(p->next==0)
		 	 {p->next=o;o->next=0;}
		 	 else
		 	 {q->next=o;o->next=p;}
		     }
		 return head;	
}
LIB SortE(LIB *head)
{		LIB *p,*q;
		if(head==0)
		return head;
		p=head;head=0;
		while(p!=0)
		{  q=p;p=p->next;head=InsertE(head,q);}
		return head;
		
}*/

void Qur(node *head)  // 查询学生信息 
{
   node *p;
   int a;
   char b[15];
   int n;
   printf("按1选择学号查询按2选择姓名查询\n");
   scanf("%d",&n);
   switch(n)
   {
      case 1: scanf("%d",&a);break;     
      case 2: scanf("%s",b);break;     
   }
   p=head;
   while(!((p->data.num==a)||(strcmp(p->data.name,b)==0)||p==NULL))
   p=p->next;
   if(p==NULL)
   printf("没有找到相关信息");
   else
   printf("学号：%d\t姓名：%s\tC语言成绩：%d\t数学成绩：%d\t英语成绩：%d\t总分：%d\t平均分：%.2f\n",p->data.num,p->data.name,p->data.cgrade,p->data.mgrade,p->data.egrade,p->data.total,p->data.ave);
}

void Save(node *head)   
{        
   FILE *fp;   
   node *p;
   p=head;      
   fp=fopen("Stu_Score.txt","w");
   fprintf(fp,"学号            姓名         C语言成绩  数学成绩   英语成绩   总分     平均分:\n");
   while(p)
	{
		fprintf(fp,"%7d\t",p->data.num);
		fprintf(fp,"%-7s\t",p->data.name);
		fprintf(fp,"%7d\t   ",p->data.cgrade);
		fprintf(fp,"%7d    ",p->data.mgrade);
		fprintf(fp,"%7d     ",p->data.egrade);
		fprintf(fp,"%7d\t",p->data.total);
		fprintf(fp,"%7f\t\n",p->data.ave);		
        p=p->next;
	}
	fclose(fp);
}
     
main()
{			
            node *p=0,*h=0,*q;
			int s,t,m,z;
			head=Link();
			char n[15],d[15],num[15];
			L:
                printf("*************************************\n");
      			printf("*                                   *\n");
      			printf("*                                   *\n");
      			printf("*         学生成绩管理系统          *\n");
      			printf("*                                   *\n");
      			printf("* 1.输入学生信息     2.输出学生信息 *\n");
      			printf("* 3.查询学生信息     4.更新学生信息 *\n");
      			printf("* 5.统计学生信息     6.退出系统     *\n");
      			printf("*                                   *\n");
      			printf("*************************************\n");
      			
      		    printf("请输入你的选择：");
      		ll: scanf("%d",&m);
      			switch(m)
      				{  
					   case 1:   Creat(head);Save(head);break;
      				   case 2:   PrintData(head);break;
      				   case 3:   Qur(head);break;
      				   case 4:   Del(head);break;							 
					   case 5:   Count(head);break;
					   case 6:   exit;
					   default:  printf("请输入正确的选项");goto ll;
			    	}
			    	
			    	printf("返回主菜单请输入'0'\n");              	
	                scanf("%d",&s);
	                if(s==0)
                    {
    	            getchar();
		            system("cls");                
		            goto L;
	                }
}