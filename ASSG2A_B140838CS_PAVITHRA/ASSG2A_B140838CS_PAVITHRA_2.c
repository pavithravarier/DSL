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



int merge(int a[],int p,int q,int r)
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
*(R+i)=a[q+i+1];

int j;
i=0;j=0;
int k=p;
int INVERSIONS=0;
int test=0;
while(i<n1 && j<n2)
{
if(test==0 && *(R+j)<*(L+i))
{
INVERSIONS=INVERSIONS+n1-i;
test=1;
}
if(*(L+i)<=*(R+j))
{
a[k]=*(L+i);
i++;
}
else
{
a[k]=*(R+j);
j++;
test=0;
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

retn:return INVERSIONS;
}
		
int NOI(int a[],int w,int y)
{
int invers=0;
int x;
if(w<y)
{

	x=(w+y)/2;
	invers=invers+NOI(a,w,x);
	invers=invers+NOI(a,x+1,y);
	invers=invers+merge(a,w,x,y);
}
return invers;
}




int main()
{
int n,i;
float noe;
int count;
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
}

count=NOI(a,0,n-1);
printf("\n%d",count);
ret: return 0;
}


