#include<stdio.h>
int main()
{
char s1[20],s2[10];
printf("enter the two strings,max size 9 each!!");
scanf("%s%s",s1,s2);
char*p1=s1;
char*p2=s2;
int i=0;
for(;*p1!='\0';p1++)
{
i++;
}
for(;*p2!='\0';p2++)
{
*p1=*p2;
p1++;
i++;
if(i==19)
break;
}
printf("\n %s \n",s1);
return 0;
}


