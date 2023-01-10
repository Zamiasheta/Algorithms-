//Binary Search Tree Traversal
#include <stdio.h>
#include <stdlib.h>
typedef struct linkedList linkedList;
struct linkedList
{
int data;
linkedList *pnode,*cnodeleft,*cnoderight;
};
void tree_Insert(linkedList **root);
void tree_Delete(linkedList **root);
void tree_Traversal(linkedList *root);
void nodemovement(linkedList **node);
void preorder(linkedList *root);
void postorder(linkedList *root);
void inorder(linkedList *root);
int main(void)
{
int choice;
linkedList *root=NULL ;
printf(" =======================\n");
printf(" <<<<<<<<Menu>>>>>>>>>>>\n");
printf(" =======================\n");
printf("\n\n");
printf("\tTo Insert Data into Tree, Press -> 1\n");
printf("\tTo Delete Data from Tree, Press -> 2\n");
printf("\tTo Display Node Traversal, Press -> 3\n");
printf("\tTo Exit From the Program, Press -> 4\n");
printf("\nYour Choice -> ");
scanf("%d",&choice);
while(choice!=4)
{
switch(choice)
{
case 1: printf("\nYou have selected to insert new Data");
tree_Insert(&root);
break;
case 2: printf("\nYou have selected to delete old Data");
tree_Delete(&root);
break;
case 3: printf("\nYou have selected to traverse the tree");
tree_Traversal(root);
break;
default: printf("Invalid Option Provided\n");
break;
}
printf("\tTo Insert Data into Tree, Press -> 1\n");
printf("\tTo Delete Data from Tree, Press -> 2\n");
printf("\tTo Display Node Traversal, Press -> 3\n");
printf("\tTo Exit From the Program, Press -> 4\n");
printf("\nYour Choice -> ");
scanf("%d",&choice);
}
return 0;
}
void tree_Insert(linkedList **root)
{
int d;
linkedList *x=*root;
linkedList *y=NULL;
linkedList *z=(linkedList*)malloc(sizeof(linkedList));
printf("=========");
printf("Insert");
printf("=========");
printf("\nEnter Data to be Inserted: ");
scanf("%d",&d);
z->data=d;
z->cnodeleft=z->cnoderight=NULL;
if(*root==NULL)
*root=z;
else
{
while(x!=NULL)
{
y=x;
if(z->data<x->data)
x=x->cnodeleft;
else
x=x->cnoderight;
}
z->pnode=y;
if(z->data<y->data)
y->cnodeleft=z;
else
y->cnoderight=z;
}
}
void tree_Delete(linkedList **root)
{
if(*root==NULL)
{
printf("Tree is empty. No data can be deleted from it.\n");
return;
}
int del_el;
linkedList *x=*root;
linkedList *y=NULL;
printf("=========");
printf("Insert");
printf("=========");
printf("\nEnter Data to be Deleted: ");
scanf("%d",&del_el);
while(x!=NULL && del_el!=x->data)
{
y=x;
if(del_el<x->data)
x=x->cnodeleft;
else
x=x->cnoderight;
}
if(x==NULL)
printf("Requested Data does not exist in Tree.\n");
else
{
if(x->cnoderight==NULL && x->cnodeleft==NULL)
{
if(x==y->cnodeleft)
y->cnodeleft=x->cnodeleft;
else
y->cnoderight=x->cnoderight;
}
else if(x->cnoderight==NULL && x->cnodeleft!=NULL)
{
if(x==y->cnodeleft)
y->cnodeleft=x->cnodeleft;
else
y->cnoderight=x->cnodeleft;
}
else if(x->cnoderight!=NULL && x->cnodeleft==NULL)
{
if(x==y->cnodeleft)
y->cnodeleft=x->cnoderight;
else
y->cnoderight=x->cnoderight;
}
else
nodemovement(&x);
}
}
void nodemovement(linkedList **node)
{
linkedList *y=*node;
linkedList *x=*node;
x=x->cnoderight;
while(x->cnodeleft!=NULL)
{
printf("%d\n",x->data);
x=x->cnodeleft;
}
if(x==y->cnoderight)
y->data=y->cnodeleft->data;
else
y->data=x->data;
x->pnode->cnodeleft=NULL;
}
void tree_Traversal(linkedList *root)
{
printf("=========");
printf("Traversal");
printf("=========");
printf("\nTraversal Paths of the Tree\n");
printf("\n PreOrder: ");
preorder(root);
printf("\n PostOrder: ");
postorder(root);
printf("\n InOrder: ");
inorder(root);
printf("\n");
}
void preorder(linkedList *root)
{
if(root!=NULL)
{
printf("%d ",root->data);
preorder(root->cnodeleft);
preorder(root->cnoderight);
}
}
void postorder(linkedList *root)
{
if(root!=NULL)
{
postorder(root->cnodeleft);
postorder(root->cnoderight);
printf("%d ",root->data);
}
}
void inorder(linkedList *root)
{
if(root!=NULL)
{
inorder(root->cnodeleft);
printf("%d ",root->data);
inorder(root->cnoderight);
}
}
