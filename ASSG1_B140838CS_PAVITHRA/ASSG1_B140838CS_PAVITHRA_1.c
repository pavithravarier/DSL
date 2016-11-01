#include<stdio.h>
#include<string.h>
int main()
{
int i;
char str1[100000],str2[100000];
int temp1[26]={0},temp2[26]={0};
printf("\nEnter str1:");
gets(str1);
printf("\nEnter str2:");
gets(str2);

	for(i=0;i<strlen(str1);i++)
	{
	 if(!(str1[i]>='a'&&str1[i]<='z'))
	 {
	  printf("Invalid input\n");
	  goto p;
	 }
	 else
	 {
	  temp1[str1[i]-97]++;
	 }
	}
 	for(i=0;i<strlen(str2);i++)
	{
	 if(!(str2[i]>='a'&&str2[i]<='z'))
	 {
	  printf("Invalid input");
	  goto p;
	 }
	 else
	 {
	  temp2[str2[i]-97]++;
	 }
	}

	int flag=1;
	for(i=0;i<26;i++)
	{
	if(temp1[i]!=temp2[i])
	{
	flag=0;
	break;
	}
	}
	if(flag==1)
	printf("YES\n");
	else
	printf("NO\n");

	p:return 0;
	}
