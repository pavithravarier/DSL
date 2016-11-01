#include<stdio.h>

struct node
{
long int el;
long int pr;
};

struct node pq[1058];

static int noe=0;
static int hs=0;

int left( int i)
{
return 2*i;
}
 int right( int i)
{
return ((2*i)+1);
}
 int parent( int i)
{
return i/2;
}

/*void makeheap(struct node a[],int n)
{

int i;
for(i=hs/2;i>=0;i--)
heapify(a,i,hs);
return ;
}*/


void heapify(struct node a[],int i)
{
int l=left(i);
int r=right(i);
int small=i;
struct node temp;
if(l<=hs)
{
if(a[l].pr<a[i].pr)
{
small=l;
}
}
if(r<=hs)
{
if(a[r].pr<a[small].pr)
{
small=r;
}
}

if(small!=i)
{
temp=a[i];
a[i]=a[small];
a[small]=temp;

heapify(a,small);
}
return;
}

void insert(struct node a[],long int ele,long int p)
{
//printf("hi");
if(hs==0)
{
a[0].el=ele;
a[0].pr=p;
//printf("hello");
hs++;
}
else
{
a[hs].el=ele;
a[hs].pr=p;
//printf("hello2");
struct node temp,t=a[hs];
int i=hs;

while(a[i].pr<a[parent(i)].pr)
{
temp=a[parent(i)];
a[parent(i)]=a[i];
a[i]=temp;
i=parent(i);

}
hs++;
}

return;
}

get_min(struct node a[])
{
if(noe==0)
printf("EMPTY\n");
else
printf("%ld\n",a[0].el);
}

extract_min(struct node a[])
{
if(hs==0)
{
printf("EMPTY\n");
return;
}
printf("%ld\n",a[0].el);
a[0]=a[hs-1];
hs--;
//noe--;
heapify(a,0);
}

decrease_priority(struct node a[],long int q,long int u)
{
struct node temp;
int i;
int flag=0;
for(i=0;i<=noe;i++)
{
if(a[i].el==q)
{
flag=1;
break;
}
}
if(flag==0)
{
printf("element not present\n");
return;
}
if(a[i].pr==u)
return;
else if(a[i].pr<u)
printf("element already has lower priority\n");
else
{
a[i].pr=u;

while(a[i].pr<a[parent(i)].pr)
{
temp=a[parent(i)];
a[parent(i)]=a[i];
a[i]=temp;
i=parent(i);

}
}
}



int main()
{
double x1,x2;
long int e,p;
char c;

do
{
//printf("afhf\n");

scanf(" %c",&c);
switch(c)
{
case 'a'://printf("");
	scanf("%lf ",&x1);
	 scanf("%lf",&x2);
	 if(x1-(long int)x1!=0||x1<0||x1>1073741824)
	 {printf("INVALID");
	 goto ret;
	}
	if(x2-(long int)x2!=0||x2<=0||x2>1073741824)
	 {printf("INVALID");
	 goto ret;
	}
       e=(long int)x1;
	p=(long int)x2;
	insert(pq,e,p);
	noe++;
	break;
case 'e':extract_min(pq);
	noe--;
	break;

case 'g':get_min(pq);
	break;
case 'd':scanf("%lf%lf",&x1,&x2);
	if(x1-(long int)x1!=0||x1<0||x1>1073741824)
	 {printf("INVALID");
	 goto ret;
	}
	if(x2-(long int)x2!=0||x2<=0||x2>1073741824)
	 {printf("INVALID");
	 goto ret;
	}
       e=(long int)x1;
	p=(long int)x2;
	decrease_priority(pq,e,p);
	break;
case 's'://printf("\n");
	break;
default:printf("wrong choice\n");
	
}

}while(c!='s');

ret:return 0;
}



