#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stu{  
	char name[10];
	int id;
	int grade1;
	int grade2;
	int grade3;
	struct stu *next;
};
int i,j,k,ave_grade1=0,ave_grade2=0,ave_grade3=0,i_d,a,b,c,count=0;
char na[10];
stu* insert(struct stu *head, struct stu *p)  //���¶���ڵ� 
{	
	do{		
		p=(struct stu *)malloc(sizeof(struct stu));
		count++;
		printf("input the name:"); //����ѧ����Ϣ
		gets(p->name);
		printf("input the id:");
		scanf("%d",&p->id);
		printf("input the grade1:");
		scanf("%d",&p->grade1);
		printf("input the grade2:");
		scanf("%d",&p->grade2);
		printf("input the grade3:");
		scanf("%d",&p->grade3);
		printf("\n");
		printf("press 1:continue, 0:end");
		scanf("%d",&k);
		fflush(stdin);
		p->next=head;
		head=p;    //���ӳ�����
	  }while(k==1);
	  return head;
} 
stu* inserthead(struct stu *head, struct stu *p) //ͷ�������½ڵ�
{
	p=(struct stu *)malloc(sizeof(struct stu));
	printf("input the name:"); //����ѧ����Ϣ
	gets(p->name);
	printf("input the id:");
	scanf("%d",&p->id);
	printf("input the grade1:");
	scanf("%d",&p->grade1);
	printf("input the grade2:");
	scanf("%d",&p->grade2);
	printf("input the grade3:");
	scanf("%d",&p->grade3);
	p->next=head;
	head=p; 
	count++;
	printf("\n\n");
	return head;
}

stu* inserttail(struct stu *head, struct stu *p)//β������ڵ� 
{
	struct stu *q;
	q=head;
	for(i=0;i<count-1;i++)
	{
		q=q->next;
	}
	p=(struct stu *)malloc(sizeof(struct stu));
	count++;
	printf("input the name:"); //����ѧ����Ϣ
	gets(p->name);
	printf("input the id:");
	scanf("%d",&p->id);
	printf("input the grade1:");
	scanf("%d",&p->grade1);
	printf("input the grade2:");
	scanf("%d",&p->grade2);
	printf("input the grade3:");
	scanf("%d",&p->grade3);
	fflush(stdin);
	q->next=p;
	printf("\n\n");
	return head;
}

void calculation(struct stu *head, struct stu *p) //����ɼ�����
{
	p=head;
	printf("%d",count);
	//printf("%d",ave_grade1);
	for(i=0;i<count;i++)
	{
		ave_grade1 += p->grade1; //�������ſ�Ŀ��ƽ���ɼ�
		ave_grade2 += p->grade2;
		ave_grade3 += p->grade3;
		p=p->next;
	}
	printf("\n******\naverage grade1: %d\n",(ave_grade1)/(i));
	printf("average grade2: %d\n",(ave_grade2)/(i));
	printf("average grade3: %d\n******\n",(ave_grade3)/(i));
	printf("\n\n");
}

stu* deletee(struct stu *head, struct stu *p) //ɾ���ڵ㺯��
{
	int stuid;
	struct stu *q;
	printf("��������Ҫɾ����id");
	scanf("%d",&stuid);
	if(head==NULL)
	{
		printf("����Ϊ��\n");
        return head;
	}
	while(p->id!=stuid&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(p->id==stuid)
	{
		if(p==head)
		{
			head=p->next;
			count--;
		}
		else
		{
			q->next=p->next;
			count--;
		}
		free(p);
	}
	else
	{
		printf("û���ҵ���Ҫɾ����id\n");
	}
	 
}
stu* sort(struct stu *head, struct stu *p) //�Խڵ���id��������
{
	stu temp;
	for(i=count-1;i>0;i--)
	{
		p=head;
		for(j=0;j<i;j++)
		{ 
			if(p->id > p->next->id)
			{
				temp=*p;
				p->grade1=p->next->grade1;
				p->grade2=p->next->grade2;
				p->grade3=p->next->grade3;
				p->id=p->next->id;
				strcpy(p->name,p->next->name);
				p->next->grade1=temp.grade1;
				p->next->grade2=temp.grade2;
				p->next->grade3=temp.grade3;
				p->next->id=temp.id;
				strcpy(p->next->name,temp.name);
			}
			p=p->next;
		}
	}
	printf("sucessful!\n\n");
	return head;
}

void display(struct stu *head, struct stu *p) //��ʾ��Ϣ
{
	p=head;
	if(head==NULL)
	{
		printf("��ʱû����Ϣ");
	}
	for(i=0;i<count;i++)
	{
		printf("name: %s,  id: %d,  grade1: %d,  grade2: %d, grade3: %d\n",p->name ,p->id ,p->grade1 ,p->grade2 ,p->grade3);
		p=p->next;
	}
	return ;
}
int main()
{
	struct stu *p;
	struct stu *head=NULL; //Ϊ������׼��
	int choice;
	printf("�뿪ʼ�����µĽڵ�\n"); 
	do{		
		p=(struct stu *)malloc(sizeof(struct stu));
		count++;
		printf("input the name:"); //����ѧ����Ϣ
		gets(p->name);
		printf("input the id:");
		scanf("%d",&p->id);
		printf("input the grade1:");
		scanf("%d",&p->grade1);
		printf("input the grade2:");
		scanf("%d",&p->grade2);
		printf("input the grade3:");
		scanf("%d",&p->grade3);
		printf("\n");
		printf("press 1:continue, 0:end");
		scanf("%d",&k);
		fflush(stdin);
		p->next=head;
		head=p;    //���ӳ�����
	}while(k==1);
	printf("\n*********************************\n"); //��ʾ�˵�
	printf("1.ͷ�������½ڵ�\n2.β�������½ڵ�\n3.˳������½ڵ�\n4.ɾ���ڵ�\n5.����ƽ���ɼ�\n6.�������������\n7.��ʾ����\n");
	printf("***********************************\n");
	do{
		printf("input your choice\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{             //�û�ѡ����
			case 1: head=inserthead(head, p); break;
			case 2: head=inserttail(head, p); break;
			case 3: head=insert(head, p); break;
			case 4: deletee(head, p); break;		
			case 5: calculation(head, p); break;
			case 6: head=sort(head, p); break;
			case 7: display(head, p); break;
			case 8: return 0;
		};
	}while(choice!=8);
	return 0;
}
