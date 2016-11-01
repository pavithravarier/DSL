#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
int key;
//struct node*next;
}*new;

int c;
int hashdfn(int k)
{
if(k>=0)
return k%c;
else
return c+k%c;
}
int hashddfn(int k)
{
double a=k*0.6180339887;
double b;
b=a-(long int)a;
b=b*c;
b=floor(b);
return b;
}

int hashfn(int k,int p)
{
//if(k>=0)
return (hashdfn(k)+p*hashddfn(k))%c;
//else
//return ((hashdfn(k)+p)%c);
}
void search(struct node**hash,int k)
{
int j=0;
int i=hashfn(k,j);
while(j<c)
{
if(hash[i]==NULL)
goto la;
else if(hash[i]->key!=k)
{
//printf("hello,%d\n",hash[i]->key);
printf("%d ",i);
j++;
i=hashfn(k,j);
}
else if(hash[i]->key==k)
{
printf("%d FOUND\n",i);
return;
}
}
la:printf("%d NOT FOUND\n",i);
return;
}

void insert(struct node**hash,int k)
{
int j=0;
int i=hashfn(k,j);
while(hash[i]!=NULL && j<c)
{
printf("%d ",i);
j++;
i=hashfn(k,j);
}
if(j>=c)
printf("CANNOT INSERT\n");
else
{
printf("%d\n",i);
new=(struct node*)malloc(sizeof(struct node));
new->key=k;
hash[i]=new;
}
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
struct node**hash=(struct node**)malloc(c*sizeof(struct node*));
for(i=0;i<c;i++)
hash[i]=NULL;
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
