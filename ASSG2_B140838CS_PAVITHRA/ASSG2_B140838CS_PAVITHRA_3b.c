#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct STUDENT
{
char ROLL_NO[10];
char NAME[50];
int MARK;
};
int validinput(float a)
{
if(a-(int)a==0.0)
return 1;
else
return 0;
}

int validroll(char s[])
{
if(isupper(s[0]))
{ 
	int i;
	for(i=1;i<7;i++)
	{	
	if(!(isdigit(s[i])))
	goto retu;
	}
	if(isupper(s[7])&&isupper(s[8]))
	return 1;
}
retu: return 0;
}

void bubble__sort(struct STUDENT s[],int i,int n)
{
struct STUDENT temp;
int j,w,k;
int m=n;
for(j=0;j<n;j++)
{
for(k=0;k<m-1;k++)
{
if(s[k].ROLL_NO[i]>s[k+1].ROLL_NO[i])
{
temp=s[k];
s[k]=s[1+k];
s[k+1]=temp;
}
}
m--;
}
return;
}



void radix__sort(struct STUDENT s[],int n)
{
int i;
for(i=8;i>=0;i--)
bubble__sort( s,i,n);
return;
}

int main()
{
int n;
float noe;
scanf("%f",&noe);
if(noe<=0||validinput(noe)==0)
{
printf("invalid input");
goto ret;
}
n=(int)noe;
struct STUDENT *STUDENT_LIST;
STUDENT_LIST=(struct STUDENT*)malloc(n*sizeof(struct STUDENT));

if(STUDENT_LIST==NULL)
{
printf("memory unallocated!");
goto ret;
}

int i;
for(i=0;i<n;i++)
{
scanf(" %s %s %d[^\n] ",((STUDENT_LIST+i)->ROLL_NO),((STUDENT_LIST+i)->NAME),&((STUDENT_LIST+i)->MARK));
if(!(STUDENT_LIST[i].MARK>=0 && STUDENT_LIST[i].MARK<=100))
{
printf("invalid marks");
goto ret;
}
if(strlen(STUDENT_LIST[i].ROLL_NO)!=9)
{
printf("invalid input");
goto ret;
}
if(validroll((STUDENT_LIST+i)->ROLL_NO)!=1)
{
printf("invalid input");
goto ret;
}

}
radix__sort(STUDENT_LIST,n);
for(i=0;i<n;i++)
{
printf("%s ",(STUDENT_LIST[i].ROLL_NO));
printf("%s ",(STUDENT_LIST[i].NAME));
printf("%d",(STUDENT_LIST[i].MARK));
printf("\n");
}
free(STUDENT_LIST);
ret:return 0;
}

