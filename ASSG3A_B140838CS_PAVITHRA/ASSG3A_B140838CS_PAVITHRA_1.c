#include<stdio.h>
#include<stdlib.h>
 
struct node
{
long int el;
struct node*next;
}*new,*trk=NULL,*head=NULL;

struct node* reverselist(struct node*a,struct node*b,struct node*c)
{
b->next=a;
if(c==NULL)
{
return b;
}
else
return (reverselist(b,c,c->next));
}


void print(struct node*a);

int main()
{
float n;
int m;
scanf("%f",&n);
if(n<=0||n-(int)n!=0)
{
printf("invalid");
goto ret;
}
m=(int)n;
int i;
long int p;
double x;
for(i=0;i<m;i++)
{
scanf("%lf",&x);
if(x>1073741824||x<-1073741824||x-(long int)x!=0)
{
printf("invalid\n");
goto ret;
}
p=(long int)x;
new=(struct node*)malloc(sizeof(struct node));
new->el=p;
new->next=NULL;
if(trk==NULL)
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
if((head==NULL)||(head->next==NULL))
print(head);

else
{
head=reverselist(NULL,head,head->next);
print(head);
}
ret:return 0;
}
void print(struct node*a)
{
struct node*t=a;

while(t)
{
printf("%ld ",t->el);
t=t->next;
}
printf("\n");
return ;
}
