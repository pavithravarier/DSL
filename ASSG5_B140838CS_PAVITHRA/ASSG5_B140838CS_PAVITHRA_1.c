#include<stdio.h>
#include<stdlib.h>

int n1=0,n2=0,n3=0,n4=0;
int error=0;
struct set1
{
int x;
struct set1* rep;
}*t1,*t11,*t111,*new1;

struct set2
{
int x;
struct set2* rep;
int rank;
}*t2,*t22,*t222,*t2222,*new2;

struct l1
{
struct set1*node;
}*a1,*a2;

struct l2
{
struct set2*node;
}*a3,*a4;

int i=0,j=0,k=0,l=0;
int m;

void make(int val)
{
if(a1[val].node!=NULL)
{
printf("PRESENT");
return;
}
printf("%d ",val);
new1=(struct set1*)malloc(sizeof(struct set1));
struct set1*newm;
newm=(struct set1*)malloc(sizeof(struct set1));
struct set2* newone=(struct set2*)malloc(sizeof(struct set2));
new1->x=val;
newm->x=val;
new1->rep=new1;
newm->rep=newm;
a1[val].node=new1;
a2[val].node=newm;
i++;
j++;
new2=(struct set2*)malloc(sizeof(struct set2));
new2->x=val;
new2->rep=new2;
new2->rank=0;
newone->x=val;
newone->rep=newone;
newone->rank=0;
a3[val].node=new2;
a4[val].node=newone;
k++;
l++;
}

int flag=0;
struct set1* f1(int val)
{
flag=0;
t111=a1[val].node;
if(a1[val].node!=NULL)
{
n1++;
t111=a1[val].node;
flag=1;
while(t111)
{
if(t111->rep==t111)
break;
else
t111=t111->rep;
n1++;
}
}
return t111;
}
void u1(int v,int w)
{
error=0;
new1=(struct set1*)malloc(sizeof(struct set1));
struct set1*new3=(struct set1*)malloc(sizeof(struct set1));
new1=f1(v);
	if(flag==0)
		{
			printf("ERROR\n");
			error=1;			
			return;
		}
new3=f1(w);
	if(flag==0)
		{
			printf("ERROR\n");
			error=1;
			return;
		}
if(new1->x==new3->x)
{
printf("%d ",new1->x);
}
else
{
new3->rep=new1;
printf("%d ",new1->x);
}
}

int fl=0;
struct set2* f2(int val)
{
fl=0;
if(a1[val].node==NULL)
{
t222=NULL;
return t222;
}
fl=1;
t222=a3[val].node;
n2++;
while(t222)
{
if(t222->rep==t222)
break;
else
t222=t222->rep;
n2++;
}
return t222;
}

void u2(int v,int w)
{
new2=(struct set2*)malloc(sizeof(struct set2));
struct set2*new4=(struct set2*)malloc(sizeof(struct set2));
new2->rank=new4->rank=0;
new2=f2(v);
	if(fl==0)
		{
			printf("ERROR\n");
			return;
		}
new4=f2(w);
	if(fl==0)
		{
			printf("ERROR\n");
			return;
		}
//printf("(rank: %d %d )",new2->rank,new4->rank);
/*if(new2->x==new4->x)
	{
		printf("%d ",new2->x);
	}*/
if(new2->rank>new4->rank)
	{
		new4->rep=new2;
		printf("%d ",new2->x);
	}
else if(new2->rank<new4->rank)
	{
		new2->rep=new4;
		printf("%d ",new4->x);
	}
else
	{
		new4->rep=new2;
		printf("%d ",new2->x);
		//printf(" Rank increasing ");
		(new2->rank)++;
	}
//printf("(rank: %d %d )",new2->rank,new4->rank);
}

struct set1* fs3(struct set1 * b)
{
if(b!=b->rep)
	b->rep=fs3(b->rep);
n3++;
return b->rep;

}


int flg=0;

struct set1* f3(int val)
{

flg=0;
if(a1[val].node==NULL)
{
t1=NULL;
return t1;
}
//if(flg!=0)
flg=1;
t1=fs3(a2[val].node);
return t1;
}

void u3(int v,int w)
{
new1=(struct set1*)malloc(sizeof(struct set1));
struct set1*new3=(struct set1*)malloc(sizeof(struct set1));
new1=f3(v);
	if(flg==0)
	{
		printf("ERROR\n");
		return;
	}
new3=f3(w);
	if(flg==0)
	{
		printf("ERROR\n");
		return;
	}
if(new1->x==new3->x)
{
printf("%d ",new1->x);
}
else
{
new3->rep=new1;
printf("%d ",new1->x);
}
}	

struct set2* fs4(struct set2 * h)
{
n4++;
if(h!=h->rep)
	h->rep=fs4(h->rep);
return h->rep;
}


int fg=0;

struct set2* f4(int val)
{
fg=0;
if(a1[val].node==NULL)
{
t2222=NULL;
return t2222;
}
fg=1;
t2222=fs4(a4[val].node);
return t2222;
}

void u4(int v,int w)
{
struct set2*new5=(struct set2*)malloc(sizeof(struct set2));
struct set2*new6=(struct set2*)malloc(sizeof(struct set2));
new5->rank=new6->rank=0;
new5=f4(v);
	if(fg==0)
		{
			printf("ERROR\n");
			return;
		}
new6=f4(w);
	if(fg==0)
		{
			printf("ERROR\n");
			return;
		}
//if(new5->x==new6->x)
//	{
//		printf("A%d ",new5->x);
//	}
if(new5->rank>new6->rank)
	{
		new6->rep=new5;
		printf("%d ",new5->x);
	}
else if(new5->rank<new6->rank)
	{
		new5->rep=new6;
		printf("%d ",new6->x);
	}
else
	{
		new6->rep=new5;
		printf("%d ",new5->x);
		//printf(" Rank increasing ");
		(new5->rank)++;
	}
}

void no_of_find()
{
printf("%d %d %d %d",n1,n2,n3,n4);
printf("\n");
}

void initialize()
{
int r;
for(r=0;r<1000;r++)
a1[r].node=NULL;
}

void main()
{
a1=(struct l1*)malloc(10000*sizeof(struct l1));
initialize();
a2=(struct l1*)malloc(10000*sizeof(struct l1));
a3=(struct l2*)malloc(10000*sizeof(struct l2));
a4=(struct l2*)malloc(10000*sizeof(struct l2));

char c;
int val,val1;

do
{
scanf(" %c",&c);
switch(c)
{
case 'm': 
		scanf("%d",&val);
		if(val<0||val>10000)
		{
			printf("INVALID\n");
			break;
		}
		make(val);
		printf("\n");
		break;

case 'f':
		scanf("%d",&val);
		if(val<0||val>10000)
		{
			printf("INVALID\n");
			break;
		}

		t1=f1(val);
		if(flag==0)
			{
			 	printf("NOT FOUND\n");
			 	break;
			}
		else
			{
			 printf("%d ",t1->x);
			}
		t2=f2(val);
			printf("%d ",t2->x);
		t11=f3(val);
			printf("%d ",t11->x);
		t22=f4(val);
			printf("%d ",t22->x);
		printf("\n");
		break;

case 'u':
		scanf("%d%d",&val,&val1);
		if(val<0||val>10000)
		{
			printf("INVALID\n");
			break;
		}
		if(val1<0||val1>10000)
		{
			printf("INVALID\n");
			break;
		}

		u1(val,val1);
		if(error==1)
		break;
		u2(val,val1);
		u3(val,val1);
		u4(val,val1);
		printf("\n");
		break;

case 's':
		no_of_find();
		break;

default:
		printf("\n");
}
}while(c!='s');

free(a1);
free(a2);
free(a3);
free(a4);
}

