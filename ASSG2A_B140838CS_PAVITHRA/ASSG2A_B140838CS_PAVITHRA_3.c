#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int division(int s[],int a,int b)
{
int j, t,i;
int temp;
t=s[b];
i=a-1;
for(j=a;j<b;j++)
{
if(s[j]<t)
{
temp=s[i+1];
s[i+1]=s[j];
s[j]=temp;
i++;
}
}
temp=s[i+1];
s[i+1]=s[b];
s[b]=temp;
return i+1;
}

void quick__sort(int s[],int a,int b)
{
if(a<b)
{
int c=division(s,a,b);
quick__sort(s,a,c-1);
quick__sort(s,c+1,b);
}
return;
}

int main()
{
FILE *f;
f=fopen("Bigfile","w+");
int i,rd,j;
char str[7]="file01";
srand(time(NULL));
for(i=0;i<67108864;i++)
{
rd=rand()%1000;
fprintf(f,"%d\n",rd);
}
fclose(f);
printf("\ncreated!");
FILE *fp;
int x[1048576];
f=fopen("Bigfile","r");
for(i=1;i<=64;i++)
{
str[4]=(char)((i/10)+'0');
str[5]=(char)((i%10)+'0');
fp=fopen(str,"w+");
for(j=0;j<1048576;j++)
{
fscanf(f,"%d",&x[j]);
}
quick__sort(x,0,j-1);
for(j=0;j<1048576;j++)
{
fprintf(fp,"%d\n",x[j]);
}
fclose(fp);
}
fclose(f);
FILE *a[8];

j=1;
int k=1;
char s[4]="801";


l1:for(i=0;i<8;i++)
{
str[4]=(char)((j/10)+'0');
str[5]=(char)((j%10)+'0');
a[i]=fopen(str,"r");
j++;
}

FILE *b;
s[2]=(char)((k%10)+'0');
b=fopen(s,"w");
int temp[8];
int small;
int index;

int num=8;


l2:for(i=0;i<num;i++)
{
fscanf(a[i],"%d",&temp[i]);
}
small=temp[0];
index=0;
int m;
for(m=1;m<num;m++)
{
if(temp[m]<small)
{
small=temp[m];
index=m;
}
}
fprintf(b,"%d",small);
for(m=0;m<num;m++)
{
if(m==index)
continue;
else
fseek(a[m],-sizeof(int),SEEK_CUR);
}
for(m=0;m<num;m++)
{
if(feof(a[m]))
{
fclose(a[m]);
int n;
for(n=m+1;n<num;n++)
{

a[m]=a[m+1];
}

num--;
}
}
if(num!=0) 
goto l2;
else
{
j++;
k++;
if(j<=56)
goto l1;
}






 return 0;
}





