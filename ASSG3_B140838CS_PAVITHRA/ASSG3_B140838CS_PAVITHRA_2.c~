#include<stdio.h>
#include<stdlib.h>

struct node
{
long int e;
struct node *next;
}*head=NULL,*new,*trk=NULL;

long int k_last(struct node*Head, int k)
{
//printf("enter funct");
int n=0;
struct node*t;
t=Head;
while(t->next!=NULL)
{
n++;
t=t->next;
}
//printf("noe=%d",n);
t=Head;
int i=0;
for(i=0;i<n-k+1;i++)
{
t=t->next;
}
return (t->e) ;
}


int main()
{
int noe;
long int el;
int i,k;
double p,q;
scanf("%lf",&p);
if(p==0||p==1.0){
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
if(q-(long int)q!=0||q>1073741824||q<-1073741824)
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
//printf("enter k");
scanf("%d",&k);
if(k>noe||k<1)
{
if(k>noe)
printf("invalid input:%d>%d",k,noe);
if(k<1)
printf("invalid input:%d<1",k);
goto ret;
}
//printf("going to fun");
long int j;
j=k_last(head,k);
printf("\n%ld",j);
ret: return 0;
}

