#include<stdio.h>
#include<stdlib.h>
struct node
{
long int e;
struct node *next;
}*head=NULL,*new,*trk=NULL;

void swap(struct node*Head,long int x,long int y);

int main()
{
int noe;
long int el,i,x,y;
double p,q;
scanf("%lf",&p);
if(p==0||p==1){
	printf("\nInput size Invalid ");
	goto ret;
	}
if(p-(int)p!=0||p<0){
	printf("invalid input");
	goto ret;
	}
noe=(int)p;
for(i=0;i<noe;i++)
{
new=(struct node *)malloc(sizeof(struct node));
if(new==NULL)
{
printf("no memory allocated");
goto ret;
}
scanf("%lf",&q);
if(q-(long int)q!=0||q<-1073741824||q>1073741824)
{
printf("invalid input");
goto ret;
}
el = (long int) q;
new->e=el;
new->next=NULL;
if(head==NULL)
{
head=new;
trk=new;
}
else
{
trk->next=new;
trk=new;
}
}
double u,v;
scanf("%lf%lf",&u,&v);
if((u-(long int)u!=0)||(v-(long int)v)!=0||v>1073741824||u>1073741824||v<-1073741824||u<-1073741824)
{
printf("invalid");
goto ret;
}
x=(long int)u;
y=(long int)v;
swap(head,x,y);
ret:return 0;
}



void swap(struct node*Head,long int x,long int y)
{
if(x==y)
goto pr;
int f1=0,f2=0;
struct node*t1,*t2,*x1,*y1,*temp;
if(Head->e==x)
{
f1=1;
x1=Head;
t2=Head;
while(t2->next!=NULL)
{
if(y==(t2->next)->e)
{
f2=1;
y1=t2->next;
break;
}
t2=t2->next;
}
if(f2==1)
{
Head=y1;
t2->next=x1;
temp=x1->next;
x1->next=y1->next;
y1->next=temp;
goto pr;
pr:trk=Head;
while(trk)
{
printf("%ld ",trk->e);
trk=trk->next;
}
goto retu;
}
}
else if(Head->e==y)
{
f2=1;
y1=Head;
t1=Head;
while(t1->next!=NULL)
{
if(x==(t1->next)->e)
{
f1=1;
x1=t1->next;
break;
}
t1=t1->next;
}
if(f1==1)
{
Head=x1;
t1->next=y1;
temp=x1->next;
x1->next=y1->next;
y1->next=temp;
goto prn;
prn:trk=Head;
while(trk)
{
printf("%ld ",trk->e);
trk=trk->next;
}
goto retu;
}
}
else
{
t2=t1=Head;
while(t1->next!=NULL)
{
if(x==(t1->next)->e)
{
f1=1;
x1=t1->next;
break;
}
t1=t1->next;
}
while(t2->next!=NULL)
{
if(y==(t2->next)->e)
{
f2=1;
y1=t2->next;
break;
}
t2=t2->next;
}
if(f1==0)
{
printf("%ld not found",x);
}
if(f2==0)
{
printf("%ld not found",y);
}
if(f1==1&&f2==1)
{
t2->next=x1;
t1->next=y1;
temp=x1->next;
x1->next=y1->next;
y1->next=temp;
//displaying
trk=head;
while(trk)
{
printf("%ld ",trk->e);
trk=trk->next;
}
}
}
retu:return;
}


