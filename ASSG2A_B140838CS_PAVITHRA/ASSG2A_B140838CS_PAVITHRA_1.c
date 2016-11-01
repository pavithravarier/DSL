#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int validinput(float a)
{
if(floor(a)==ceil(a))
return 1;
else
return 0;
}


int main()
{
int n,k,i,flag=0;
float noe;
scanf("%f",&noe);
if(noe<=0||validinput(noe)==0)
{
printf("invalid input");
goto ret;
}
n=floor(noe);

int *a=(int *)malloc(n*sizeof(int));
for(i=0;i<n;i++)
{
scanf("%f",&noe);
if(validinput(noe)==0)
{
printf("invalid input");
goto ret;
}
*(a+i)=floor(noe);
if(i>=1)
if(*(a+i)<*(a+i-1))
{
printf("invalid input");
goto ret;
}
}
scanf("%d",&k);
int j;
for(i=0,j=n-1;i<j;)
{
if(a[i]+a[j]==k)
{
printf("%d %d",a[i],a[j]);
flag=1;
break;
}
if(a[i]+a[j]<k)
{
i++;
continue ;
}
if(a[i]+a[j]>k)
{
j--;
continue;
}
}
if(flag==0)
printf("NO TWO ELEMENTS SUM UP TO %d",k);
free(a);
ret: return 0;
}

