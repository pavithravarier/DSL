#include<stdio.h>
#include<stdlib.h>

static int c;
static int top=-1;
static int flag=0;

void push(long int stk[],long int e);
long int pop(long int stk[]);
void print(long int stk[]);

int main()
{
float cn;
scanf("%f",&cn);
if(cn<=0||cn>=1000||cn-(int)cn!=0)
{
printf("invalid number of elements!");
goto ret;
}
c=(int)cn;
long int p;
double r;
char ch;
long int *stk=(long int *)malloc(c*(sizeof(long int)));
do
{
//printf("\n");
l:scanf(" %c",&ch);
switch (ch)
{
case 'a':scanf("%lf",&r);
	 if(r<0||r-(long int)r!=0||r>2147483648)
	 {
	  printf("\ninvalid");
		goto ret;
	 }
	 p=(long int)r;
	 push(stk,p);
	 break;
case 'r':p=pop(stk);
	 if(flag!=0)
	 printf("%li\n",p);
	 break;
case 'p':print(stk);
	 break;
case 's':printf("\n");
	 break;
default: printf("\nwrong choice, enter again");
}
}while(ch!='s');
ret:return 0;
}

void push(long int stk[],long int e)
{
if(top==-1)
{
top=0;
stk[top]=e;
}
else if(top==c-1)
printf("OVERFLOW\n");
else
{
top++;
stk[top]=e;
}
}

long int pop(long int stk[])
{
long int a=-1;
if(top==-1)
{
flag=0;
printf("EMPTY\n");
}
else 
{flag=1;
a=stk[top];
top--;
}
return a;
}

void print(long int stk[])
{
int i;
if(top==-1)
printf("EMPTY\n");
else
{
for(i=top;i>=0;i--)
printf("%li ",stk[i]);
printf("\n");
}

}



