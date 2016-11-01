#include<stdio.h>
int gcd(int,int);
int main()
{
int a,b;
printf("Enter two numbers,larger first \n");
scanf("%d%d",&a,&b);
int y=gcd(a,b);
printf("\n gcd is %d",y);
return 0;
}
int gcd(int p,int q)
{
int t;
if(p%q==0)
return q;
else
{
t=p;
p=q;
q=t%p;
return gcd(p,q);
}
}
