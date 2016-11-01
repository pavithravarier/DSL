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
int noe,m;
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
float *a=(float *)malloc(noe*sizeof(float));
if(a==NULL)
{
printf("memory unallocated!");
goto ret;
}


int i;
for(i=0;i<noe;i++)
scanf("%f",(a+i));
m=noe;
int j;
float temporary;
for(i=0;i<m;i++)
{
for(j=0;j<noe-1;j++)
{
if(*(a+j)>*(a+j+1))
{
temporary=*(a+j);
*(a+j)=*(a+j+1);
*(a+j+1)=temporary;
}
}
noe--;
} 
printf("\n");
for(i=0;i<m;i++)
printf("%f ",*(a+i));
free(a);
}
ret: return 0;
}
