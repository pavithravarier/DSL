#include<stdio.h>
#include<string.h>
#include<ctype.h>
struct STUDENT
{
char STUDENT_ID[100];
char STUDENT_NAME[100];
char MARK[4];
}s1;
int mark(char s[])
{
int n,p=0,i;
n=strlen(s);
for(i=0;i<n;i++)
p=(p*10)+(int)s[i]-48;
return p;
}
int main(int argc,char*argv[])
{
if(argc!=2)
{
printf("file not specified\n");
goto p;
}
int c,l=0,i,g,max=0;
FILE*f;
f=fopen(argv[1],"w+");
if(f==NULL)
printf("could not open file");
else
{
do
{
printf("\n1.Add student details\n2.Display the names of students who obtained less than 30 marks.\n3.Display the names of students who have insufficient attendance\n4.Display all the records in the file.\n5.Exit\nEnter your choice:");
scanf("%d",&c);
switch(c)
{
case 1:	fseek(f,0,SEEK_END);
	printf("Enter name,id and mark:\n");
	scanf(" %s%s%s",s1.STUDENT_NAME,s1.STUDENT_ID,s1.MARK);
	if(strlen(s1.STUDENT_NAME)>max)
	max=strlen(s1.STUDENT_NAME);
	if(strcmp(s1.MARK,"I")!=0&&strcmp(s1.MARK,"A")!=0)
	{
         for(g=0;g<strlen(s1.MARK);g++)
	  {
		if(!(s1.MARK[g]-48<=9 && s1.MARK[g]-48>=0))
		{printf("INVALID MARKS\n");
 		goto p;}
	 }
	}
	if(strlen(s1.MARK)>3||mark(s1.MARK)>100)
	{printf("INVALID MARKS\n");
	goto p;
	}

	fwrite(&s1,sizeof(s1),1,f);
        break;
case 2: fseek(f,0,SEEK_SET);
	printf("Students who scored less than 30:\n");
	while(fread(&s1,sizeof(s1),1,f)==1)
	{
	if((strcmp(s1.MARK,"I")!=0)&&(strcmp(s1.MARK,"A")!=0))
	{
	if(mark(s1.MARK)<=30)
	printf("\n%s\n",s1.STUDENT_NAME);
	}
	}
	break;
case 3: fseek(f,0,SEEK_SET);
	printf("Students with insufficient attendance\n");
	while(fread(&s1,sizeof(s1),1,f)==1)
	{
	if((strcmp(s1.MARK,"I"))==0)
	printf("\n%s",s1.STUDENT_NAME);
	}

       break;
case 4: fseek(f,0,SEEK_SET);
		if(max<strlen("STUDENT_NAME"))
		max=strlen("STUDENT_NAME");
		printf("\n+----------+");
		for(i=0;i<max;i++)
		printf("-");
		printf("+----+\n");
		printf("|Student_ID|");
		printf("Student_Name");
		for(i=strlen("STUDENT_NAME");i<max;i++)
		printf(" ");
		printf("|MARK|");
		printf("\n+----------+");
		for(i=0;i<max;i++)
		printf("-");
		printf("+----+\n");

	while(fread(&s1,sizeof(s1),1,f)==1)
	{
        printf("|%s",s1.STUDENT_ID);
	l=strlen(s1.STUDENT_ID);
	for(i=l;i<10;i++)
	printf(" ");
	printf("|%s",s1.STUDENT_NAME);
	l=strlen(s1.STUDENT_NAME);
	for(i=l;i<max;i++)
	printf(" ");
	printf("|%s",s1.MARK);
	l=strlen(s1.MARK);
	for(i=l;i<4;i++)
	printf(" ");
	printf("|\n");	
	}
	
	printf("+----------+");
		for(i=0;i<max;i++)
		printf("-");
		printf("+----+\n");

      break;
}
}while(c>=1&&c<5);
}
fclose(f);
p:return 0;
}

