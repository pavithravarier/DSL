#include<stdio.h>
long int countones(long int n)
{
if(n==0)
return 0;
else
return(n%2+countones(n/2));
}

int main()
{
 long int num,c=0;

printf("ENTER A POSITIVE DECIMAL NUMBER");
scanf("%li",&num);
if(num<0)
printf("INVALID INPUT\n");
else
{
 long int temp=countones(num);
printf("THE BINARY REPRESENTATION OF %li CONTAINS %li 1s \n",num,temp);
}
return 0;
}
