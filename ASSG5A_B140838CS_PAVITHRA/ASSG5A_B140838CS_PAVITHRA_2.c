#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void floyd();
float weightt(int,int);

float INF=10001;
struct node
{
int label;
struct node*next;
float weight;
}*head,*trk,*new;

struct array
{
struct node*list;
};
struct array*adj;
int n;

void main()
{

scanf("%d",&n);
getchar();
if(n<1||n>1000)
{
printf("INVALID\n");
exit(0);
}
char ch;
char str[100000];
int prev=0;
adj=(struct array*)malloc(n*sizeof(struct array));
int i,j,v,num;
for(j=0;j<n;j++)
{
head=NULL;
num=0;
prev=0;
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
if(num<prev)
{
printf("invalid");
exit(0);
}
prev=num;
new->label=num;
new->next=NULL;
new->weight=INF;
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
//printf("\nJ for weight\n");
trk=adj[j].list;
float nu=0;
 gets(str);
int temp;
for(i=0;i<strlen(str);)
{
nu=0;
temp=i;
if(str[i]>='0'&&str[i]<='9')
{
while(str[i]>='0'&&str[i]<='9')
{
nu*=10;
nu+=(float)(str[i]-'0');
i++;
}
if(str[i]=='.')
{
int poow=-1;
i++;
while(str[i]<='9'&&str[i]>='0')
{
nu=nu+(float)((str[i]-'0')*pow(10,poow));
poow--;
i++;
}
}
if(str[temp-1]=='-')
{
nu=nu*-1.0;
}
if(!(nu<=10000&&nu>=-10000))
{
printf("invalid");
exit(0);
}
if(trk!=NULL)
{
//printf("%f\n",nu);
trk->weight=nu;
trk=trk->next;
}

}
else
i++;
}
}

floyd();
}

void floyd()
{
//printf("IN FLOYD\n");
float *distance = (float *)malloc(n * n * sizeof(float));
 int k;
int i, j, count = 0;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++);
	{	
		if(i!=j)
		*(distance+i*n+j)=10001;
		else
		*(distance+i*n+j)=0;
	}
}
for(i=0;i<n;i++)
{	
	for(j=0;j<n;j++)
		{	//printf("%d ",weightt(i,j));
			*(distance+i*n+j)=weightt(i,j);
		}
}
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(*(distance+i*n+k)+*(distance+k*n+j)<*(distance+i*n+j))
{
*(distance+i*n+j)=*(distance+i*n+k)+*(distance+k*n+j);
}
}
}
}
for(k=0;k<n;k++)
{
if(*(distance+k*n+k)<0)
{
printf("NEGATIVE CYCLE: INVALID");
exit(0);
}
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(*(distance+i*n+j)==INF)
printf("INF ");
else
{
if(*(distance+i*n+j)-(int)*(distance+i*n+j)==0)
printf("%d ",(int)*(distance+i*n+j));
else
printf("%f ",*(distance+i*n+j));
}
}
printf("\n");
}

}

float weightt(int s,int d)
{
float wt=INF;
struct node*p=adj[s].list;
if(s==d)
return 0;
while(p!=NULL)
{
if(p->label==d)
{
wt=p->weight;
break;
}
p=p->next;
}
return wt;
}

 


