#include<stdio.h>
int main()
{
int m,n,i,j;
long int a[100][100];
char ch;
printf("enter the no. of rows and columns:");
scanf("%d%d",&m,&n);
if(m<0||n<0)
{
printf("EXITING!!");
goto p;
}
printf("enter the elements\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
scanf("%li",&a[i][j]);
if(a[i][j]<0)
{
printf("EXITING");
goto p;
}
}
}
int s,t,q,r,num=0;
do
{
printf("\nMENU:\na.Clockwise spiral order traversal.\nb.Anti-clockwise spiral order traversal.\nc.Exit\nEnter your choice:\n");
scanf(" %c",&ch);
switch(ch)
{
case 'a': q=0;
	r=n-1;
	s=m-1;
	t=0;
	num=0;
	l:for(j=t;j<=r;j++)
	{
	printf("%li ",a[q][j]);
	num++;
	}	
	for(i=q+1;i<=s;i++)
	{
	printf("%li ",a[i][r]);
	num++;
	}
	for(j=r-1;j>=t;j--)
	{
	printf("%li ",a[s][j]);
	num++;
	}
	for(i=s-1;i>q;i--)
	{	
	printf("%li ",a[i][t]);
	num++;
	}	
	q++;
	t++;
	r--;
	s--;
	if(num!=m*n)	
	goto l;
	break;
case 'b': q=0;
	r=n-1;
	s=m-1;
	t=0;
	num=0;
	z:for(i=q;i<=s;i++)
	{
	printf("%li ",a[i][t]);
	num++;
	}	
	for(j=t+1;j<=r;j++)
	{
	printf("%li ",a[s][j]);
	num++;
	}
	for(i=s-1;i>=q;i--)
	{
	printf("%li ",a[i][r]);
	num++;
	}
	for(j=r-1;j>t;j--)
	{	
	printf("%li ",a[q][j]);
	num++;
	}	
	q++;
	t++;
	r--;
	s--;
	if(num!=m*n)	
	goto z;
	
	 break;
}
}while(ch=='a'||ch=='b');
p:return 0;
}

