#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int p,int q,int r)
{
int n1,n2;
n1=q-p+1;
n2=r-q;
int i;
int *L;
L=(int *)malloc((n1)*sizeof(int));
if(L==NULL)
{
printf("memory unallocated!");
goto retn;
}

int *R;
R=(int *)malloc((n2)*sizeof(int));
if(R==NULL)
{
printf("memory unallocated!");
goto retn;
}

for(i=0;i<n1;i++)
*(L+i)=a[p+i];

for(i=0;i<n2;i++)
*(R+i)=a[q+1+i];
int j;
i=0;j=0;
int k=p;
while(i<n1 && j<n2)
{
if(*(L+i)<=*(R+j))
{
a[k]=*(L+i);
i++;
}
else
{
a[k]=*(R+j);
j++;
}
k++;
}
while(i<n1)
{
a[k]=*(L+i);
i++;
k++;
}
while(j<n2)
{
a[k]=*(R+j);
j++;
k++;
}
free(L);
free(R);
retn:return;
}

void merges(int a[],int p,int r)
{
if(p<r)
{
int q=(p+r)/2;
merges(a,p,q);
merges(a,q+1,r);
merge(a,p,q,r);
}
return;
}


int main()
{
int x[10000];
FILE *f;
f=fopen("NUMBERS","r+");

if(f==NULL)
{printf("could not open file");
goto ret;
}

int i=0;

while(fscanf(f,"%d",&x[i])>0)
{
i++;
}
int n;
n=i;
if(n<=0||n>=10000)
{
printf("invalid input file");
goto ret;
}

merges(x,0,n-1);
fclose(f);
f=fopen("SORTEDNUMBERS","w+");
if(f==NULL)
{printf("could not open file");
goto ret;
}

for(i=0;i<n;i++)
{
fprintf(f,"%d\n",x[i]);
}
fclose(f);
ret : return 0;
}


