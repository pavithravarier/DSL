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
int division(struct STUDENT s[],int a,int b)
{
int j, t,i;
struct STUDENT temp;
t=s[b].MARK;
i=a-1;
for(j=a;j<b;j++)
{
if(s[j].MARK>t)
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

void quick__sort(struct STUDENT s[],int a,int b)
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
float noe;
scanf("%f",&noe);
int n;
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
printf("invalid input");
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
quick__sort(STUDENT_LIST,0,n-1);
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

