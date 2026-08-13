#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;
//DECLARE
NODE *makenode(int data)
{

    NODE *temp=(NODE*) malloc(sizeof(NODE));
    temp->data=data;
    temp->next=NULL;
    return temp;
}
//DISPLAY
void display(NODE *l)
{
    while(l)
    {
        printf("%5d",l->data);
        l=l->next;
    }
}
//insert head
NODE *inserthead(NODE *l,int data)
{
    NODE *temp=makenode(data);
    temp->next=l;
    return temp;
}
//insert tail
NODE * inserttail(NODE *l,int data)
{
    if(!l) return makenode(data);
    NODE *t=l;
    while(t->next) t=t->next;
    t->next=makenode(data);
    return l;
}
NODE *get_node(NODE *l,int size)
{
    int temp;
    printf("ENTER ELEMENTS:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&temp);
        if(!l) l=makenode(temp);
        else {l=inserttail(l,temp);}
    }
    return l;
}
NODE *copy(NODE *l)
{
    if(!l) return NULL;
    NODE *t=makenode(l->data);
    t->next=copy(l->next);
    return t;
}
NODE *concat(NODE *l1, NODE *l2)
{
    if (!l1) return copy(l2);
    NODE *l3=copy(l1);
    NODE *temp=l3;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=copy(l2);
    return l3;
}
int main()
{
    NODE *l1=NULL;
    NODE *l2=NULL;
    int n,m;
    printf("ENTER SIZE 1:");
    scanf("%d",&n);
    printf("ENTER SIZE 2:");
    scanf("%d",&m);
    l1=get_node(l1,n);
    l2=get_node(l2,m);
    NODE *l3=concat(l1,l2);
    printf("\n CONCAT LIST:\n");
    display(l3);
    return 0;
}
