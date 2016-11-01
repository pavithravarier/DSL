#include<stdio.h>
#include<stdlib.h>
int validinput(float a)
{
if(a-(int)a==0.0)
return 1;
else
return 0;
}

void binary_search(int a[],int k,int n,int m)
{
if(a[(m+n)/2]==k)
{
printf(" %d",((m+n)/2)+1);
return ;
}
else if(n==m)
{
printf("NOT FOUND");
return ;
}

else if(a[(m+n)/2]>k)
{
binary_search(a,k,((m+n)/2),m);
return;
}
else
{
binary_search(a,k,n,((m+n)/2)+1);
return;
}
return;
}


int main()
{
int noe,flag=0,m=0;
float n;
scanf("%f",&n);
if(n<=0||validinput(n)==0)
{
printf("invalid input");
goto ret;
}
else
{
noe=(int)n;
float *tempo=(float *)malloc(noe*sizeof(float));
int *a=(int *)malloc(noe*sizeof(int));
if(a==NULL||tempo==NULL)
{
printf("memory unallocated!");
goto ret;
}

int i,k;
for(i=0;i<n;i++)
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
binary_search(a,k,n-1,m);
free(a);
free(tempo);
}

ret : return 0;
}

