#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int validinput(float a)
{
if(a-(int)a==0.0)
return 1;
else
return 0;
}

int main()
{
int n;
float noe;
char temp[11],t[11];

scanf("%f",&noe);
if(noe<=0||validinput(noe)==0)
{
printf("INVALID");
goto ret;
}
n=(int)noe;

int i,p;
char **a;
a=(char**)malloc(n*sizeof(char*));
if(a==NULL)
{
printf("memory unallocated!");
goto ret;
}

for(i=0;i<n;i++)
a[i]=(char*)malloc(11*sizeof(char));

int j;
for(i=0;i<n;i++)
scanf("%s",a[i]);
for(i=0;i<n;i++)
{
if(strlen(a[i])>10)
{
printf("invalid input");
goto ret;
}
for(p=0;p<strlen(a[i]);p++)
{
if(!(a[i][p]<='z'&& a[i][p]>='a'))
{
printf("invalid input");
goto ret;
}
}
}
for(i=0;i<n;i++)
{
strcpy(temp,a[i]);
p=i;
for(j=i+1;j<n;j++)
{
if(strcmp(a[j],temp)<0)
{
strcpy(temp,a[j]);
p=j;
}
}
strcpy(t,a[i]);
strcpy(a[i],a[p]);
strcpy(a[p],t);
}
for(i=0;i<n;i++)
{
printf("%s ",a[i]);
}
free(a);


ret: return 0;
}


