#include<stdio.h>
#include <stdbool.h>
#define MAX 100
//STACK- FILO
typedef struct{
    char stk[MAX];
    int top;
}STACK;
//initialise
void sinitial(STACK *s)
{
    s->top=0;
}
//empty
bool check_empty(STACK *s)
{
    if(s->top==0) return true;
    else return false;
}
//full
bool check_full(STACK *s)
{
    if(s->top>=MAX-1) return true;
    else return false;
}
//push
void push(STACK *s, char str)
{
    if(!check_full(s))
    {
        s->stk[s->top]=str;
        s->top++;
    }
    else return;
}
char pop(STACK *s)
{
    if(!(check_empty(s)))
    {
        s->top--;
        return (s->stk[s->top]);
    }
    else return -1;
}
