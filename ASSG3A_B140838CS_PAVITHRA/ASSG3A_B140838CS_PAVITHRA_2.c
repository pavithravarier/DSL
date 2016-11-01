#include<stdio.h>
#include<stdlib.h>
 int n;
static int c=0;
struct node
{
int el;
struct node*next;
}*new,*head1,*head2,*trk;

 int nod(long int );

void sum_of_digits(struct node*,struct node*);
void print(struct node*);

int main()
{
float no;
scanf("%f",&no);
if(no-(int)no!=0||no<=0||no>=10001)
{
printf("invalid!\n");
goto ret;
}
n=(int)no;

double x,y;
long int x1,x2;
scanf("%lf%lf",&x,&y);
if(x-(long int)x!=0||x>1073741824||x<-1073741824||y-(long int)y!=0||y>1073741824||y<-1073741824)
{
printf("invalid!\n");
goto ret;
}
x1=(long int)x;
x2=(long int)y;

if(nod(x1)!=nod(x2)||nod(x1)!=n||nod(x2)!=n)
{
printf("invalid!\n");
goto ret;
}

long int var;
var=x1;
trk=NULL;
while(var)
{
new=(struct node*)malloc(sizeof(struct node));
new->el=var%10;
new->next=NULL;
if(head1==NULL)
{
head1=new;
trk=new;
}
else
{
new->next=head1;
head1=new;
}
var=var/10;
}


trk=NULL;
var=x2;
while(var)
{
new=(struct node*)malloc(sizeof(struct node));
new->el=var%10;
new->next=NULL;
if(head2==NULL)
{
head2=new;
trk=new;
}
else
{
new->next=head2;
head2=new;
}

var=var/10;
}
sum_of_digits(head1,head2);

if(c!=0)
{
new=(struct node*)malloc(sizeof(struct node));
new->el=c;
new->next=head1;
head1=new;
}

print(head1);

ret:return 0;
}
int sum=0;


void sum_of_digits(struct node*t1,struct node*t2)
{
if(t1==NULL)
return ;
sum_of_digits(t1->next,t2->next);
sum=t1->el+t2->el+c;
c=sum/10;
sum=sum%10;
t1->el=sum;
return;
}

void print(struct node* a)
{
struct node*trk1=a;
while(trk1)
{
printf("%d",trk1->el);
trk1=trk1->next;
}
printf("\n");
return;
}

 int nod(long int a)
{
int no=0;
while(a)
{
no++;
a/=10;
}
return no;
}




