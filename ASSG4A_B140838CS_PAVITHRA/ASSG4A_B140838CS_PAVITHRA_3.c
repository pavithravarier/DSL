#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int el;
struct node*left;
struct node*right;
struct node*parent;
}*new,*root=NULL;

struct stack
{
struct node*stk[1000];
int top;
}st1,st2;

void preorder(struct node*base)
{
if(base!=NULL)
{
printf("%d ",base->el);
preorder(base->left);
preorder(base->right);
}
/*else
{
printf("EMPTY\n");
}*/
return;
}

void insert(struct node* base,int e)
{
if(base==NULL)
{
new=(struct node*)malloc(sizeof(struct node));
new->el=e;
new->left=new->right=new->parent=NULL;
base=new;
root=new;
}
else
{
new=(struct node*)malloc(sizeof(struct node));
new->el=e;
new->left=new->right=NULL;
struct node* p=base,*y;
while(p)
{
y=p;
if(p->el>e)
p=p->left;
else
p=p->right;
}
new->parent=y;
if(new->el<y->el)
y->left=new;
else if(new->el>y->el)
y->right=new;
}
}

void zigzag_print(struct node*root);

void main()
{
char str[1000];

gets(str);
//printf("%li",strlen(str));
int arr[1000];
int num,f=0;
int i,arri=0;
for(i=0;i<strlen(str);)
{
num=0;
if(str[i]>='0'&&str[i]<='9')
{
while(str[i]>='0'&&str[i]<='9')
{
//printf("hello\n");
f=1;
num*=10;
num+=str[i]-'0';
i++;
}

arr[arri]=num;

arri++;
f=0;
}
else
i++;
}
for(i=0;i<arri;i++)
insert(root,arr[i]);
//preorder(root);

//printf("\n");
/*preorder(root);
printf("\n");*/


zigzag_print(root);
}






void zigzag_print(struct node*base)
{



st1.top=st2.top=-1;
struct node*a;
if(base==NULL)
{
//printf("bye\n");
return;}
st2.top++;
st2.stk[st2.top]=base;

while(st2.top!=-1||st1.top!=-1)
{
	while(st2.top!=-1)
	{	
		a=st2.stk[st2.top];
		st2.top--;
		printf("%d ",a->el);
		if(a->left!=NULL)
		{
		st1.top++;
		st1.stk[st1.top]=a->left;
		}
		if(a->right!=NULL)
		{
		st1.top++;
		st1.stk[st1.top]=a->right;
		}
	}
	
	while(st1.top!=-1)
	{	
		a=st1.stk[st1.top];
		st1.top--;
		printf("%d ",a->el);
		if(a->right!=NULL)
		{
		st2.top++;
		st2.stk[st2.top]=a->right;
		}
		if(a->left!=NULL)
		{
		st2.top++;
		st2.stk[st2.top]=a->left;
		}
	}

	
}
}
