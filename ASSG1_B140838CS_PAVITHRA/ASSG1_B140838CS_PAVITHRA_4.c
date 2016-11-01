#include<stdio.h>
#include<math.h>
int main()
{
 long int a[100][100],b[100][100];
int i,j;
int n;
printf("ENTER THE SIZE OF Matrix (NxN)\n");
scanf("%d",&n);
printf("enter the elements\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{scanf("%li",&a[i][j]);
if(a[i][j]<0)
{printf("invalid input entered\n");
goto p;
}
}
}
if(n==1)
printf("\n%li",a[0][0]);
else
{
b[0][0]=lroundf((float)(a[0][0]+a[0][1]+a[1][0]+a[1][1])/4);
b[n-1][0]=lroundf((float)(a[n-1][0]+a[n-2][0]+a[n-1][1]+a[n-2][1])/4);
b[n-1][n-1]=lroundf((float)(a[n-1][n-1]+a[n-1][n-2]+a[n-2][n-1]+a[n-2][n-2])/4);
b[0][n-1]=lroundf((float)(a[0][n-1]+a[0][n-2]+a[1][n-1]+a[1][n-2])/4);
for(j=1;j<n-1;j++)
{
b[0][j]=lroundf((float)(a[0][j]+a[0][j-1]+a[0][j+1]+a[1][j-1]+a[1][j+1]+a[1][j])/6);
}
for(j=1;j<n-1;j++)
{
b[n-1][j]=lroundf((float)(a[n-1][j]+a[n-1][j-1]+a[n-1][j+1]+a[n-2][j]+a[n-2][j-1]+a[n-2][j+1])/6);
}
for(i=1;i<n-1;i++)
{
b[i][0]=lroundf((float)(a[i][0]+a[i-1][0]+a[i+1][0]+a[i][1]+a[i-1][1]+a[i+1][1])/6);
}
for(i=1;i<n-1;i++)
{
b[i][n-1]=lroundf((float)(a[i][n-1]+a[i-1][n-1]+a[i+1][n-1]+a[i][n-2]+a[i-1][n-2]+a[i+1][n-2])/6);
}
for(i=1;i<n-1;i++)
{
for(j=1;j<n-1;j++)
b[i][j]=lroundf((float)(a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i-1][j-1]+a[i-1][j+1]+a[i+1][j]+a[i+1][j-1]+a[i+1][j+1])/9);
}
for(i=0;i<n;i++)
{
printf("\n");
for(j=0;j<n;j++)
{
printf("%li\t",b[i][j]);
}
}
}
p:
return 0;
}

