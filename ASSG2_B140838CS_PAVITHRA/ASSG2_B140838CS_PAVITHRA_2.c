#include<stdio.h>
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
int column,row,rowt,columnt,k,flag=0;
float columnf,rowf;
scanf("%f%f",&rowf,&columnf);

if(columnf<=0||rowf<=0)
{
printf("invalid input");
goto ret;
}
if(validinput(columnf)==0||validinput(rowf)==0)
{
printf("invalid input");
goto ret;
}
column=(int)columnf;
row=(int)rowf;
float *tempo=(float *)malloc(column*row*sizeof(float));
int *M=(int *)malloc(column*row*sizeof(int));
if(M==NULL||tempo==NULL)
{
printf("memory unallocated!");
goto ret;
}

for(rowt=0;rowt<row;rowt++)
{
for(columnt=0;columnt<column;columnt++)
{
scanf("%f",(tempo+rowt*column+columnt));
if(validinput(*(tempo+rowt*column+columnt))==0)
{
printf("invalid input");
goto ret;
}
*(M+rowt*column+columnt)=*(tempo+rowt*column+columnt);
}
}
scanf("%d",&k);
for(rowt=0;rowt<row;rowt++)
{
for(columnt=0;columnt<column;columnt++)
{if(*(M+rowt*column+columnt)==k)
{printf("%d %d\n",rowt+1,columnt+1);
flag++;}
}
}
free(M);
free(tempo);
if(flag==0)
printf("NOT FOUND");
ret :return 0;
}


