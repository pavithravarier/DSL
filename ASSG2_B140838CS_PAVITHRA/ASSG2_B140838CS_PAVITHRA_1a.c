#include<stdio.h>
#include<stdlib.h>
int validinput(float a)
{
if(a-(int)a==0.0)
return 1;
else
return 0;
}

int main()
{
int noe,flag=0;
float n;
scanf("%f",&n);
if(n<=0||validinput(n)==0)
{
printf("invalid input");
goto ret;
}
noe=(int)n;
float *tempo=(float *)malloc(noe*sizeof(float));
int *a=(int *)malloc(noe*sizeof(int));
if(a==NULL||tempo==NULL)
{
printf("memory unallocated!");
goto ret;
}

int i,k;
for(i=0;i<noe;i++)
{
scanf("%f",(tempo+i));
if(validinput(*(tempo+i))==0)
{
printf("invalid input");
goto ret;
}
*(a+i)=(int)(*(tempo+i));
if(i>=1)
{
if(!(*(a+i-1)<*(a+i)))
{
printf("invalid input");
goto ret;
}
}
}

scanf("%d",&k);
int b=0,mid=0,e=noe;
while(b<=e)
{
mid=((b+e)/2);
if(a[mid]==k)
{
printf(" %d",mid+1);
flag=1;
break;
}
else if(a[mid]>k)
e=mid-1;
else
b=mid+1;
}
free(a);
free(tempo);

if(flag==0)
printf("NOT FOUND");

ret:return 0;
}
