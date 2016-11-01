#include<stdio.h>
float add(float,float);
float sub(float,float);
float mul(float,float);
float div(float,float); 
int main()
{
float a,b;
int p;
float (*choice[4])(float,float)={&add,&sub,&mul,&div};
printf("enter the numbers:");
scanf("%f %f",&a,&b);
label: printf("Menu:\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit\nEnter the choice:");
scanf("%d",&p);
if(p>=1&&p<=4)
{
choice[p-1](a,b);
goto label;
}
return 0;
}
float add(float a,float b)
{
printf("%f", a+b);
return;
}
float sub(float a,float b)
{
printf("%f",a-b);
return;
}
float mul(float a,float b)
{
printf("%f",a*b);
return;
}
float div(float a,float b)
{
if(b==0)
printf("DIVISION NOT POSSIBLE!\n");
else
printf("%f",a/b);
return;
}

