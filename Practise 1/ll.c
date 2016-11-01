#include<stdio.h>
#include<stdlib.h>
struct test
{
int val;
struct test* next;
} *head,*curr,*ptr,*temp;
head=NULL;
curr=NULL;
temp=NULL;
void create(int val)
{
ptr=(struct test*) malloc(sizeof(struct test));
if(ptr==NULL)
printf("cant create\n");
else 
{
ptr->val=val;
ptr->next=NULL;
head=ptr;
curr=ptr;
}
}
void insert(int val,int pos)
{
ptr=(struct test*) malloc(sizeof(struct test));
if(pos==1)
{
ptr->val=val;
ptr->next=head;
head=ptr;
}
else
{
curr=head;
temp=head;
int i=1;
for(;i<pos;i++)
{
temp=curr;
curr=curr->next;
if(i==pos-1)
{
ptr=temp->next;
curr=ptr->next;
ptr->val=val;
}
}
}
}
void count()
{
curr=head;
int i=1;
while(curr->next!=NULL)
i++;
printf("nodes=%d\n",i);
}
void delete(int pos)
{
int i;
temp=head;
if(pos==1)
head=head->next;
else if(pos==count())
{read:
if(temp->next->next==NULL)
temp->next=NULL;
else
{
temp=temp->next;
goto read;
}}
else
{
for(i=1;i<pos;i++)
{
if(i==pos-1)
{temp=temp->next->next;
break;
}
temp=temp->next;
}
}
}
void display()
{
temp=head;
if(head==NULL)
printf("empty");
else
{
while(temp->next!=NULL)
{
printf("%d \t",temp->val);
temp=temp->next;
}
}
}
int main()
{
int c,a,b;

do{
printf("ENTER\n1.CREATE\n2.INSERT\n3.DELETE\n4.COUNT\n5.EXIT");
scanf("%d",&c);
switch(c)
{
case 1: printf("enter value");
        scanf("%d",&a);
        create(a);
        display();
	break;
case 2: printf("val and pos?");
	scanf("%d%d", &a,&b);
	insert(a,b);
	display();
	break;
case 3: printf("pos?");
	scanf("%d",&b);
	delete(b);
	display();
	break;
case 4: count();
	display();
	break;
case 5:printf("exit");
       break;
default:printf("wrong");
}
}while(c>=1 && c<=4);
}






