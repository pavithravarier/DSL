#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char el;
struct node*left;
struct node*right;
}*new,*root=NULL;


struct stack
{
struct node*stk[2000];
int top;
}s;


struct node*make_tree(char pre[],int l)
{
s.top=-1;
if(l==1)
{
new=(struct node*)malloc(sizeof(struct node));
new->left=new->right=NULL;
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
new->el=pre[i];
s.top++;
s.stk[s.top]=new;
}


if(pre[i]=='^'||pre[i]=='/'||pre[i]=='*'||pre[i]=='+'||pre[i]=='-')
{
new=(struct node*)malloc(sizeof(struct node));
new->el=pre[i];
new->right=s.stk[s.top];
s.top--;
new->left=s.stk[s.top];
s.stk[s.top]=new;
}
}
return new;
}

void inorder(struct node*base)
{
if(base!=NULL)
{
if(base->left!=NULL)
printf("(");
inorder(base->left);
printf("%c",base->el);

inorder(base->right);
if(base->right!=NULL)
printf(")");
}
return;
}

void preorder(struct node*base)
{
if(base!=NULL)
{
printf("%c",base->el);
preorder(base->left);
preorder(base->right);
}
return;
}

void postorder(struct node*base)
{

if(base!=NULL)
{
postorder(base->left);
postorder(base->right);
printf("%c",base->el);
}
return;
}

int main()
{
char pre[2000];
scanf("%s",pre);
int u;
if(strlen(pre)==1)
{
for(u=0;u<3;u++)
{
printf("%s",pre);
printf("\n");
}
exit(0);
}

if(pre[0]!='^'&&pre[0]!='/'&&pre[0]!='*'&&pre[0]!='+'&&pre[0]!='-')
{
printf("invalid!");
exit(0);
}

char str[2000][2000],s[2000],temp[2000];
int m=strlen(pre);
int head=-1,i;
for(i=m-1;i>=0;i--)
{
if(pre[i]>='a'&&pre[i]<='z')
{
s[0]=pre[i];
s[1]='\0';
head++;
strcpy(str[head],s);
}
else if(pre[i]=='^'||pre[i]=='/'||pre[i]=='*'||pre[i]=='+'||pre[i]=='-')
{
s[0]=pre[i];
s[1]='\0';
strcpy(temp,str[head]);
head--;
strcat(temp,str[head]);
strcat(temp,s);
strcpy(str[head],temp);
//head++;
}
else
{
printf("invalid");
exit(0);
}

}
strcpy(pre,str[0]);
root=make_tree(pre,strlen(pre));
//printf("%d\n",ht(root));
inorder(root);
printf("\n");
preorder(root);
printf("\n");
postorder(root);
printf("\n");
}
