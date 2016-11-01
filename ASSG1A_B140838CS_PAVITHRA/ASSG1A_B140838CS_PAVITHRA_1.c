#include<stdio.h>
int main()
{
long int a[100][100];
int n;
printf("Enter dimension,n(nxn matrix,max 100):");
scanf("%d",&n);
if(n<0||n>100)
{
printf("invalid!");
goto p;
}
int i,j;
//taking input
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{scanf("%li",&a[i][j]);
if(a[i][j]<0)
{printf("invalid input!");
goto p;
}}
}
printf("Input matrix is:\n");
/*printing input array*/
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<n;j++)
printf("%li\t",a[i][j]);
}
long int temp;
for(i=0;i<n;i++)
{
for(j=i;j<n;j++)
{
temp=a[i][j];
a[i][j]=a[j][i];
a[j][i]=temp;
}
}
for(j=0;j<n/2;j++)
{
for(i=0;i<n;i++)
{
temp=a[i][j];
a[i][j]=a[i][n-1-j];
a[i][n-1-j]=temp;
}
}
//printing the output
printf("\n Rotated matrix is:");
for(i=0;i<n;i++)
{
printf("\n\n");
for(j=0;j<n;j++)
printf("%li\t",a[i][j]);
}
p:return 0;
}

