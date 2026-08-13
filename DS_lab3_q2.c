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
//count nodes
int count_nodes(NODE *l)
{
    int cc=0;
    while(l)
    {
        cc++;
        l=l->next;
    }
    return cc;
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
//check same or not
bool check_same(NODE *l1,NODE *l2)
{
    int nl1=count_nodes(l1);
    int nl2=count_nodes(l2);
    if(nl1!=nl2) return false;
    else{
        while(l1)
        {
            if(l1->data!=l2->data) return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
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
    printf("\n SAME? %s\n",check_same(l1,l2)?"TRUE":"FALSE");
    display(l1);
    printf("\n");
    display(l2);
    return 0;
}
