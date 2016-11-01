#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isthere(int b);
int n;
int non=0;
int get0()
{
return 0;
}
int left(int i)
{
return 2*i;
}
int right(int i)
{
return ((2*i)+1);
}
int parent(int i)
{
return i/2;
}

//void floyd();
//float weightt(int,int);

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

int hs;
int size;
int cap;
int * x;

struct heap
{
int v;
float wt;
};
struct heap a[1000];




void heapify(struct heap a[],int i)
{
int l=left(i);
int r=right(i);
int small=i;
struct heap temp;
if(l<=hs)
{
if(a[l].wt<a[i].wt)
{
small=l;
}
}
if(r<=hs)
{
if(a[r].wt<a[small].wt)
{
small=r;
}
}

if(small!=i)
{
x[a[small].v]=i;
x[a[i].v]=small;
temp=a[i];
a[i]=a[small];
a[small]=temp;

heapify(a,small);
}
return;
}

struct heap extract_min(struct heap a[])
{
if(hs==0)
{
//printf("EMPTY\n");
return;
}
struct heap temp=a[0];
//printf("%ld\n",a[0].el);
a[0]=a[hs-1];
x[temp.v]=hs-1;
x[a[hs].v]=0;
hs--;
//noe--;
heapify(a,0);
return temp;
}

decrease_priority(struct heap a[], int q, float u)
{
struct heap temp;
int i;
int flag=0;
int y=x[q];
a[y].wt=u;
/*for(i=0;i<=n;i++)
{
if(a[i].v==q)
{
flag=1;
break;
}
}
if(flag==0)
{
//printf("element not present\n");
return;
}
if(a[i].wt==u)
return;
else if(a[i].wt<u)
{}
//printf("element already has lower priority\n");
else
{
a[i].wt=u;*/

i=y;
while(a[i].wt<a[parent(i)].wt&&i)
{
x[a[i].v]=parent(i);
x[a[parent(i)].v]=i;
temp=a[parent(i)];
a[parent(i)]=a[i];
a[i]=temp;
i=parent(i);
}
}


void apsp(int s)
{
x=(int*)malloc(n*sizeof(int));
hs=0;
cap=n;
float *dist=(float *)malloc(n*sizeof(float));

int i;
for(i=0;i<n;i++)
{
dist[i]=INF;
a[i].v=i;
a[i].wt=INF;
x[i]=i;
}

a[s].v=s;
x[s]=s;
a[s].wt=INF;
dist[s]=0;
decrease_priority(a,s,dist[s]);

hs=n;

while(hs!=0)
{

struct heap temp;
temp=extract_min(a);

int ver=temp.v;

trk=adj[ver].list;

while(trk!=NULL)
{
int vv=trk->label;

if(dist[ver]!=INF && isthere(vv)==1  && (trk->weight+dist[ver])<dist[vv])
{
dist[vv]=dist[ver]+trk->weight;
if(non==get0())
{
non=0;
}

decrease_priority(a,vv,dist[vv]);
}
trk=trk->next;
}
}
for(i=0;i<n;i++)
{
if(dist[i]==INF)
{
printf("INF ");
}
else if(dist[i]-(int)dist[i]==0)
printf("%d ",(int)dist[i]);
else
printf("%f ",dist[i]);
}
}
void sssp(int s,int d)
{
hs=0;
cap=n;
float *dist=(float *)malloc(n*sizeof(float));
x=(int*)malloc(n*sizeof(int));
int i;
for(i=0;i<n;i++)
{
dist[i]=INF;
a[i].v=i;
a[i].wt=INF;
x[i]=i;
}

a[s].v=s;
x[s]=s;
a[s].wt=INF;
dist[s]=0;
decrease_priority(a,s,dist[s]);

hs=n;

while(hs!=0)
{

struct heap temp;
temp=extract_min(a);

int ver=temp.v;

trk=adj[ver].list;

while(trk!=NULL)
{
int vv=trk->label;

if(isthere(vv)==1 && (trk->weight+dist[ver])<dist[vv] && dist[ver]!=INF )
{
dist[vv]=dist[ver]+trk->weight;
if(non!=0)
{non=0;
}
decrease_priority(a,vv,dist[vv]);
}
trk=trk->next;
}
}

i=d;
if(dist[i]==INF)
{
printf("UNREACHABLE ");
}
else if(dist[i]-(int)dist[i]==0)
printf("%d ",(int)dist[i]);
else
printf("%f ",dist[i]);

}


void main()
{
int s,d;
scanf("%d",&n);
getchar();
if(n<1||n>1000)
{
printf("INVALID\n");
exit(0);
}
int prev=0;
char ch;
char str[100000];
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
printf("Invalid");
exit(0);
nu=nu*-1.0;
}
if(!(nu<=10000.00&&nu>=0))
{
printf("invaliD");
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
char opt[5];

do
{
scanf("%s",opt);
getchar();

if(strcmp("apsp",opt)==0)
{
scanf("%d",&s);
if(s<0||s>=n)
{
printf("INVALID\n");
exit(0);
}
apsp(s);
printf("\n");
}

else if(strcmp("sssp",opt)==0)
{
scanf("%d%d",&s,&d);
if(s<0||s>=n||d<0||d>=n)
{
printf("INVALID\n");
exit(0);
}
sssp(s,d);
printf("\n");
}

else if(strcmp("stop",opt)==0)
{
printf("\n");
exit(0);
}
else
{
printf("Invalid option\n");
exit(0);
}
}while(strcmp("stop",opt)!=0);
}


int isthere(int b)
{
if (x[b]<hs)
return 1;
else return 0;
}

