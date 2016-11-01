#include<stdio.h>
#include<stdlib.h>
struct node
{
long int e;
struct node *next;
}*head=NULL,*new,*rear=NULL;
int flag=0;
void enqueue(struct node*Head,long int el);
long int dequeue(struct node*Head);
void print(struct node*Head);

int main()
{
long int p;
long int res;
double r;
char ch;
do
{
//printf("\n");
l:scanf(" %c",&ch);
switch (ch)
{
case 'e':scanf("%lf",&r);
	 if(r<0||r-(long int)r!=0||r>2147483648)
	 {
	  printf("\ninvalid");
		goto ret;
	 }
	 p=(long int)r;
	 enqueue(head,r);
	 break;
case 'd':res=dequeue(head);
	if(flag!=0)
	printf("%li\n",res);
	 break;
case 'p':print(head);
	 break;
case 's':printf("\n");
	 break;
default: printf("\nwrong choice, enter again");
}
}while(ch!='s');
ret:return 0;
}

void enqueue(struct node*Head,long int el)
{
new=(struct node*)malloc(1*sizeof(struct node));
new->e=el;
new->next=NULL;
if(head==NULL)
{
head=new;
rear=new;

}
else
{
rear->next=new;
rear=new;
}
return ;
}
long int dequeue(struct node*Head)
{
int a=-1;
if(head==NULL)
{
printf("EMPTY\n");
return a;
}

else if(head->next==NULL)
{
flag=1;
a=head->e;
head=NULL;
rear=NULL;
}
else
{
flag=1;
a=head->e;
head=head->next;
}
return a;
}
void print(struct node*Head)
{
if(head==NULL)
printf("EMPTY\n");
else
{
struct node*trk=head;
while(trk)
{
printf("%li ",trk->e);
trk=trk->next;
}
printf("\n");
}
}

