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
int flag=0;
static int call=0;

struct node* findMin(struct node*bas)
{
struct node*base=bas;
if(base==NULL)
return base;
while(base->left!=NULL)
base=base->left;
return base;
}

struct node* findMax(struct node*bas)
{
struct node*base=bas;
if(base==NULL)
return base;
while(base->right!=NULL)
base=base->right;
return base;
}

struct node* search(struct node*bas,int e)
{
struct node*base=bas;
//printf("%d\n",call);
if(base==NULL)
{
if(call==0)
printf("NOT FOUND\n");
return NULL;
}
else if(e==base->el)
{
//printf("%d\n",call);
if(call==0)
printf("FOUND\n");
return base;
}
else
{
if(e<base->el)
return search(base->left,e);
else
return search(base->right,e);
}
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


struct node* successor(struct node*bas,int x)
{
struct node*base=bas;
struct node*y;
call=1;
struct node*xn=search(base,x);
if(xn==NULL)
{
printf("NOT FOUND\n");
flag=1;
call=0;
return NULL;
}

if(xn->right!=NULL)
{
struct node*succ=findMin(xn->right);
call=0;
//flag=1;
return succ;
}
else
{
y=xn->parent;
while(y!=NULL && xn==y->right)
{
xn=y;
y=y->parent;
}
}
call=0;
return y;
}


struct node* predecessor(struct node*bas,int x)
{
struct node*base=bas;
struct node*y;
call=1;
struct node*xn=search(base,x);
if(xn==NULL)
{
printf("NOT FOUND\n");
flag=1;
call=0;
return NULL;
}

if(xn->left!=NULL)
{
struct node*pred=findMax(xn->left);
//flag=1;
call=0;
return pred;
}
else
{
y=xn->parent;
while(y!=NULL && xn==y->left)
{
xn=y;
y=y->parent;
}
}
call=0;
return y;
}

struct node*delete(struct node*bas,int zn)
{
struct node*base=bas;
call=1;
struct node *y,*z=search(base,zn);
if(z==NULL)
{
printf("NOT FOUND\n");
return NULL;
}
else
{
struct node *x;
if(z->left==NULL || z->right==NULL)
{
y=z;
}
else
y=successor(base,zn);
if(y->left!=NULL)
x=y->left;
else
x=y->right;
if(x!=NULL)
x->parent=y->parent;
if(y->parent==NULL)
root=x;
else if(y==(y->parent)->left)
{
y->parent->left=x;
}
else
y->parent->right=x;
if(y!=z)
{
z->el=y->el;
}
}
call=0;
//root=base;
return y;
}

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

void postorder(struct node*base)
{

if(base!=NULL)
{
postorder(base->left);
postorder(base->right);
printf("%d ",base->el);
}
/*else
{
printf("EMPTY\n");
}*/
return;
}

void inorder(struct node*base)
{
if(base!=NULL)
{
inorder(base->left);
printf("%d ",base->el);
inorder(base->right);
}
/*else
{
printf("EMPTY\n");
}*/
return;
}

void main()
{
struct node*p;
char str[5];
int m;
do
{
scanf("%s",str);
if(strcmp(str,"stop")==0)
{
exit(0);
}
else if(strcmp(str,"insr")==0)
{
scanf("%d",&m);
if(m<0)
{
printf("invalid\n");
exit(0);
}
insert(root,m);
}
else if(strcmp(str,"srch")==0) 
{
scanf("%d",&m);
if(m<0)
{
printf("invalid\n");
exit(0);
}
p=search(root,m);
}
else if(strcmp(str,"minm")==0)
{
p=findMin(root);
if(p==NULL)
printf("NIL\n");
else
printf("%d\n",p->el);
}
else if(strcmp(str,"maxm")==0)
{
p=findMax(root);
if(p==NULL)
printf("NIL\n");
else
printf("%d\n",p->el);
}
else if(strcmp(str,"succ")==0)
{
scanf("%d",&m);
if(m<0)
{
printf("invalid\n");
exit(0);
}
p=successor(root,m);
if(p==NULL && flag==0)
printf("NIL\n");
else if(p!=NULL)
{
printf("%d\n",p->el);
}
flag=0;
}
else if(strcmp(str,"pred")==0)
{
scanf("%d",&m);
if(m<0)
{
printf("invalid\n");
exit(0);
}
p=predecessor(root,m);
if(p==NULL && flag==0)
printf("NIL\n");
else if(p!=NULL)
{
printf("%d\n",p->el);
}
flag=0;
}
else if(strcmp(str,"delt")==0)
{
scanf("%d",&m);
if(m<0)
{
printf("invalid\n");
exit(0);
}
p=delete(root,m);
}
else if(strcmp(str,"inor")==0)
{
inorder(root);
printf("\n");
}
else if(strcmp(str,"prer")==0)
{
preorder(root);
printf("\n");
}
else if(strcmp(str,"post")==0)
{
postorder(root);
printf("\n");
}
else
{
printf("wrong choice\n");
}
}while(strcmp(str,"stop")!=0);

}

