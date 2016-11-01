#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
char el;
struct node*left;
struct node*right;
struct node*parent;
}*new,*root;

struct stack
{
struct node*stk[2000];
int top;
}s;

struct node*left(struct node*k)
{
return k->left;
}

struct node*right(struct node*k)
{
return k->right;
}

struct node*parent(struct node*k)
{
return k->parent;
}

char element(struct node*k)
{
return k->el;
}

struct node*make_tree(char pre[],int l)
{
s.top=-1;
if(l==1)
{
new=(struct node*)malloc(sizeof(struct node));
new->left=new->right=NULL;
new->parent=NULL;
new->el=pre[0];
return new;
}
int i;
for(i=0;i<l;i++)
{
if(pre[i]>='a'&&pre[i]<='z')
{
new=(struct node*)malloc(sizeof(struct node));
new->left=new->right=NULL;
new->parent=NULL;
new->el=pre[i];
s.top++;
s.stk[s.top]=new;
}
if(pre[i]=='^'||pre[i]=='/'||pre[i]=='*'||pre[i]=='+'||pre[i]=='-')
{
new=(struct node*)malloc(sizeof(struct node));
new->el=pre[i];
new->right=s.stk[s.top];
s.stk[s.top]->parent=new;
s.top--;
new->left=s.stk[s.top];
s.stk[s.top]->parent=new;
s.stk[s.top]=new;
}
}
return new;
}

void inorder(struct node*base)
{
int flag=0;
struct node*temp,*temp2;
temp=base;
if(temp==NULL)
return;
if(base==NULL)
return;
int x=1;
while(temp!=NULL)
{
if(temp->left==NULL)
{
printf("%c",temp->el);
struct node*x=temp;
while(x->parent!=NULL)
{
if(x==x->parent->right)
{printf(")");
x=x->parent;
}
else
break;
}
temp=temp->right;
}
else
{
if(flag!=1)
temp2=temp->left;
while(temp2->right!=NULL&&temp2->right!=temp)
{
temp2=temp2->right;
}
if(temp2->right==NULL)
{
if(flag==0)
temp2->right=temp;
temp=temp->left;
printf("(");
}
else
{
temp2->right=NULL;
printf("%c",temp->el);
temp=temp->right;
}
}
}
}

void preorder(struct node*base)
{
struct node* temp,*temp1;
temp=base;
if(temp==NULL)
return;
while(temp!=NULL)
{
if(temp->left==NULL)
{
printf("%c",temp->el);
temp=temp->right;
}
else
{
temp1=temp->left;
while(temp1->right!=NULL && temp1->right!= temp)
{
temp1=temp1->right;
}
if(temp1->right==temp)
{
temp1->right=NULL;
temp=temp->right;
}
else
{
printf("%c",temp->el);
temp1->right=temp;
temp=temp->left;
}
}
}
}
void postorder(struct node*base)
{

int where[4]={0,1,2,10};
int g=where[0];
struct node *temp1,*temp2;
temp1=base;
while(temp1!=NULL)
{

if(g==1)
{
	if(temp1->right==NULL)
        {
	printf("%c",temp1->el);
	temp2=temp1;
        temp1=temp1->parent;
        if(temp1==NULL)
break;
                    if(left(temp1)==temp2)
		g=where[1];
                else
                g=where[2];}
            else
                {temp1=temp1->right;
                 g=where[0];
                }
}
else if(g==0)
{	if(temp1->left!=NULL)
	temp1=left(temp1);
	else if(left(temp1)==NULL)
	{
	printf("%c",element(temp1));
	
	if(right(temp1)==NULL)
	{

	temp2=temp1;
	temp1=parent(temp1);
	if(temp1==NULL)
break;
	if(left(temp1)==temp2)
	g=where[1];
	else
	g=where[2];
	}
	else
	temp1=right(temp1);
	}
}

else if(g==2)
	{printf("%c",temp1->el);
             temp2=temp1;
            temp1=temp1->parent;
            if(temp1==NULL)
break;
            if(temp1->left=temp2)
                g=where[1];
                else
                g=where[2];
}
}
ret:return;
}

           
int main()
{
int cn=0;
char pre[2000];
scanf("%s",pre);
int u,i,m;
if(pre[0]=='+'||pre[0]=='-'||pre[0]=='/'||pre[0]=='*'||pre[0]=='^')
{
printf("invalid");
exit(0);
}
if(strlen(pre)==1)
{
for(u=0;u<3;u++)
{
printf("%s",pre);
printf("\n");
}
exit(0);
}



m=strlen(pre);
for(i=m-1;i>=0;i--)
{
if(!(pre[i]>='a'&&pre[i]<='z'))
{
 if(!(pre[i]=='^'||pre[i]=='/'||pre[i]=='*'||pre[i]=='+'||pre[i]=='-'))
  {
    printf("invalid");
    exit(0);
  }

}
}

root=make_tree(pre,strlen(pre));
//printf("%d\n",ht(root));
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
printf("\n");
}




