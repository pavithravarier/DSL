#include<stdio.h>
#include<stdlib.h>
static int flag=0;
struct node
{
long int x;
struct node*next;
}*new,*top,*temp=NULL;

void push(struct node*top,long int e);
long int pop(struct node*top );
void print(struct node*top);

int main()
{
double n;
char ch;
long int p;
top=NULL;
do
{
scanf("  %c",&ch);
switch(ch)
{
case 'a':scanf("%lf",&n);
    if(n-(long int)n!=0||n<0||n>2147483648)
        {
    printf("invalid");
    goto ret;
    }
 p=(long int)n;
    push(top,p);
	top=temp;
    break;
case 'r':p=pop(top);
         if(flag==0)
    printf("EMPTY\n");
    else
    printf("%li\n",p); 
	top=temp;  
    break;
case 'p':print(top);
    break;
case 's':printf("\n");
    break;
default:printf("wrong choice,enter again\n");
}
}while(ch!='s');
ret:return 0;
}


void push(struct node* top,long int e)
{
new=(struct node*)malloc(sizeof(struct node));
new->x=e;
if(temp==NULL)
{
temp=new;
new->next=NULL;
}
else
{
new->next=temp;
temp=new;
}
return;
}
long int pop(struct node*top)
{
long int a=0;
temp=top;
if(temp==NULL)
{
a=-1;
flag=0;
}
else
{
a=temp->x;
temp=temp->next;
flag=1;
}
return a;
}

void print(struct node* top)
{
struct node*trk=top;
if(top==NULL)
printf("EMPTY\n");
else
{
while(trk)
{
printf("%li ",trk->x);
trk=trk->next;
}
printf("\n");
}
return;
}
