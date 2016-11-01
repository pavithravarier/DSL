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
int noe;
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
unsigned int *a=(unsigned int *)malloc(noe*sizeof(unsigned int));
if(a==NULL||tempo==NULL)
{
printf("memory unallocated!");
goto ret;
}

int i;
for(i=0;i<noe;i++)
{
scanf("%f",(tempo+i));
if(validinput(*(tempo+i))==0||*(tempo+i)<0)
{
printf("invalid input");
goto ret;
}
*(a+i)=(unsigned int)(*(tempo+i));
if(*(a+i)<0)
{
printf("invalid input");
goto ret;
}
}
int j;
unsigned int k;
for(i=1;i<noe;i++)
{
k=*(a+i);
for(j=i-1;j>0,*(a+j)>k;j--)
{

*(a+j+1)=*(a+j);
}
*(a+j+1)=k;
}
printf("\n");
for(i=0;i<noe;i++)
printf("%u ",*(a+i));
free(a);
free(tempo);
}
ret: return 0;
}
