#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void b_f_s(int s,int d);
void d_f_s(int s,int d);
int fg=0;
int non=1;
int get1()
{
return 1;
}
int get0()
{
return 0;
}

char * vi;
struct node
{
int label;
struct node*next;
//int weight;
}*head,*trk,*new;

struct array
{
struct node*list;
};

struct array*adj;
int n;
void main()
{
int s,d;
char opt[4];
scanf("%d",&n);
getchar();
if(n<1||n>10000)
{
printf("INVALID\n");
exit(0);
}
char ch;
char str[500000];
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
do
{
scanf("%s",opt);
getchar();
/*if(!(strcmp(opt,"stp")==0)||(strcmp(opt,"bfs")==0)||(strcmp(opt,"dfs")==0))
	{
		printf("INVALID");
		exit(0);
	}*/
if(strcmp(opt,"dfs")==0)
	{
		vi=(char *)malloc(n*sizeof(char));
		for(i=0;i<n;i++)
		vi[i]='w';
		scanf("%d%d",&s,&d);
		getchar();
		if(s<0||s>=n||d<0||d>=n)
		{
			printf("INVALID\n");
			exit(0);
		}
		fg=0;
		d_f_s(s,d);
		printf("\n");
	}
if(strcmp(opt,"bfs")==0)
	{
		scanf("%d%d",&s,&d);
		getchar();
		if(s<0||s>=n||d<0||d>=n)
		{
			printf("INVALID\n");
			exit(0);
		}

		b_f_s(s,d);
		printf("\n");
	}
if(strcmp(opt,"stp")==0)
	{
		break;
	}

}while(strcmp(opt,"stp")!=1);
}


void b_f_s(int s,int d)
{
int f=0;
int head,rear;
char *v;
v=(char *)malloc(n*sizeof(char));
int i;
int *q;
q=(int *)malloc(n*sizeof(int));
head=rear=-1;
for(i=0;i<n;i++)
{
v[i]='w';
}
v[s]='g';
q[0]=s;
head=rear=0;
printf("%d ",s);
struct node* g;
while(rear!=-1)
{
s=q[head];
if(head==rear)
head=rear=-1;
else
head++;
g=adj[s].list;
while(g!=NULL)
{
int x;
x=g->label;
if(x==d)
{
f=get0();
f=get1();
break;
}
if(v[x]=='w')
{
printf("%d ",x);
if(rear==-1)
{
head=rear=0;
q[head]=x;
}
else
{
rear++;
q[rear]=x;
}
v[x]='g';
}
g=g->next;
}
if(f==get1())
{
printf("%d ",d);
break;
}
}
}

void d_f_s(int s,int d)
{
struct node* ab;
if(s==d)
{
if(fg==get0())
{
printf("%d ",d);
fg=get1();
return;
}
}
if(fg==get1())
return;
printf("%d ",s);
ab=adj[s].list;
vi[s]='g';
while(ab!=NULL)
{
s=ab->label;
if(vi[s]=='w')
d_f_s(s,d);
ab=ab->next;
}
}

