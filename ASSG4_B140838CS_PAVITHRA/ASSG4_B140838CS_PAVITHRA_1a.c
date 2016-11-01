#include<stdio.h>
#include<stdlib.h>

struct node
{
int key;
struct node*next;
}*new;

int c;
/*struct hash_table
{
struct node * ptr;
};*/

int hashfn(int k)
{
if(k>=0)
return k%c;
else
return c+k%c;
}

void insert(struct node *h[],int k)
{
int i;
i=hashfn(k);
printf("%d\n",i);
new=(struct node*)malloc(sizeof(struct node));
new->key=k;
new->next=NULL;
if(h[i]==NULL)
{
(h[i])=new;
}
else
{
new->next=(h[i]);
(h[i])=new;
}
return;
}

void search(struct node*h[],int k)
{
int i;
i=hashfn(k);
struct node*t=(h[i]);
int flag=0;
while(t)
{
if(t->key==k)
{
flag=1;
break;
}
t=t->next;
}
if(flag==1)
printf("%d FOUND\n",i);
else
printf("%d NOT FOUND\n",i);
return;
}


int main()
{

float b;
scanf("%f",&b);

if(b-(int)b!=0||b<=0)
{
printf("invalid\n");
exit(0);
}
c=(int)b;
int k,i;
struct node**hash=(struct node**)malloc(c*sizeof(struct node));
for(i=0;i<c;i++)
(hash[i])=NULL;
char ch;
do
{
scanf(" %c",&ch);
switch(ch)
{
case 's':exit(0);
case 'i':scanf("%d",&k);
	 //i=hashfn(k);
	 insert(hash,k);
	 break;
case 'f':scanf("%d",&k);
	 search(hash,k);
	 break;
default:printf("wrong choice enter again\n");
	break;
}}while(ch='s');

return 0;
}
