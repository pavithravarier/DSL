#include<stdio.h>
#include<stdlib.h>
void makeheap(int a[],int);
void heapify(int a[],int,int);
void heap__sort(int a[],int);
int validinput(float a)
{
if(a-(int)a==0.0)
return 1;
else
return 0;
}


int left(int i)
{
return 2*i;
}
int right(int i)
{
return ((2*i)+1);
}
int parent(int i)
{
return i/2;
}


int main()
{
int n;
float noe;
scanf("%f",&noe);
if(noe<=0||validinput(noe)==0)
{
printf("invalid array dimension\n");
goto ret;
}
n=(int)noe;
float *tempo=(float *)malloc(n*sizeof(float));
int *a;
a=(int *)malloc(n*sizeof(int));
if(a==NULL||tempo==NULL)
{
printf("memory unallocated!");
goto ret;
}

int i;
for(i=0;i<n;i++)
{
scanf("%f",(tempo+i));
if(validinput(*(tempo+i))==0)
{
printf("invalid input");
goto ret;
}
*(a+i)=(int)(*(tempo+i));

}

heap__sort(a,n);
printf("\n");
for(i=0;i<n;i++)
{
printf("%d ",*(a+i));
}
free(a);
ret:return 0;
}


void heap__sort(int a[],int n)
{
int t,i;
makeheap(a,n);
int hs=n-1;
while(hs>0)
{
t=*(a+hs);
*(a+hs)=*(a+0);
*(a+0)=t;
hs--;
heapify(a,0,hs);
}
return;
}

void makeheap(int a[],int n)
{
int hs=n-1;
int i;
for(i=hs/2;i>=0;i--)
heapify(a,i,hs);
return ;
}

void heapify(int a[],int i,int hs )
{
int l=left(i);
int r=right(i);
int large=i,temp;
if(l<=hs)
{
if(a[l]>a[i])
{
large=l;
}
}
if(r<=hs)
{
if(a[r]>a[large])
{
large=r;
}
}

if(large!=i)
{
temp=a[i];
a[i]=a[large];
a[large]=temp;

heapify(a,large,hs);
}
return;
}

