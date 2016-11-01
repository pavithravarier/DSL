#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
struct node
{
int el;
struct node*left;
struct node*right;
};

struct node*make(int v)
{
struct node*h=(struct node*)malloc(sizeof(struct node));
h->el=v;
h->left=NULL;
h->right=NULL;
return h;
}

void preorder(struct node*base)
{
if(base!=NULL)
{
printf("( ");
printf("%d ",base->el);
if(base->left==NULL&&base->right==NULL)
printf("( ) ( ) ");
/*if(base->right==NULL&&base->left!=NULL)
printf(" ( ) ");*/
preorder(base->left);
if(base->right==NULL&&base->left!=NULL)
printf("( ) ");
if(base->right!=NULL&&base->left==NULL)
printf("( ) ");
preorder(base->right);
printf(") ");
}
return;
}

static int po=0,io=0;

struct node* make_bst(int pre[],int in[],int one,int two)
{
int k=0;

if(one>two)
return NULL;

struct node*new=make(pre[po]);
/*{
new=(struct node*)malloc(sizeof(struct node));
new->el=pre[po];
new->left=NULL;
new->right=NULL;
}*/
po++;

if(one==two)
return new;

int i,j;
for(i=0;i<n;i++)
{
if(in[i]==new->el)
break;
}
j=i;

new->left=make_bst(pre,in,one,j-1);
new->right=make_bst(pre,in,j+1,two);

return new;
}




void main()
{
float b;
scanf("%f",&b);
if(b<=0||b-(int)b!=0)
{
printf("invalid\n");
exit(0);
}
 n=(int)b;
/*int pre[100];
int in[100];*/
int *pre=(int *)malloc(n*sizeof(int));
int *in=(int *)malloc(n*sizeof(int));
int i;
for(i=0;i<n;i++)
{
scanf("%f",&b);
if(b-(int)b!=0)
{
printf("invalid\n");
exit(0);
}
pre[i]=(int)b;
}
for(i=0;i<n;i++)
{
scanf("%f",&b);
if(b-(int)b!=0)
{
printf("invalid\n");
exit(0);
}
in[i]=(int)b;
}
struct node*iroot=(struct node*)malloc(sizeof(struct node));
iroot=make_bst(pre,in,0,n-1);

preorder(iroot);

return;
}
