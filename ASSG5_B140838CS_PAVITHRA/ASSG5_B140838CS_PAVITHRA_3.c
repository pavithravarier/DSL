#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int label;
struct node*next;
int weight;
}*head,*trk,*new;

struct array
{
struct node*list;
};
struct array*adj;
int n;
void main()
{
char b;
int s,d;
char opt[4];
scanf("%d",&n);
b=getchar();
if(n<1||n>1000)
{
printf("INVALID\n");
exit(0);
}
char ch;
char str[1000000];
adj=(struct array*)malloc(n*sizeof(struct array));
int i,j,v,num;
for(j=0;j<n;j++)
{
head=NULL;
num=0;
 gets(str);
for(i=0;i<strlen(str);)
{
num=0;
if(str[i]>='0'&&str[i]<='9')
{
while(str[i]>='0'&&str[i]<='9')
{
num*=10;
num+=str[i]-'0';
i++;
}
if(num>=n)
{
printf("INVALID");
exit(0);
}
new=(struct node*)malloc(sizeof(struct node));
new->label=num;
new->next=NULL;
if(head==NULL)
{
head=trk=new;
}
else
{
trk->next=new;
trk=new;
}
}
else
i++;
}
adj[j].list=head;
trk=adj[j].list;
}
for(j=0;j<n;j++)
{
trk=adj[j].list;
num=0;
 gets(str);
for(i=0;i<strlen(str);)
{
num=0;
if(str[i]>='0'&&str[i]<='9')
{
while(str[i]>='0'&&str[i]<='9')
{
num*=10;
num+=str[i]-'0';
i++;
}
trk->weight=num;
trk=trk->next;
}
}
}

for(i=0;i<n;i++)
{
trk=adj[i].list;
while(trk)
{
printf("%d ",trk->label);
trk=trk->next;
}
printf("\n");
}

for(i=0;i<n;i++)
{
trk=adj[i].list;
while(trk)
{
printf("%d ",trk->weight);
trk=trk->next;
}
printf("\n");
}
}
