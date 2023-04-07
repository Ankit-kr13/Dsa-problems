#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    char *a;
    int top;
};
struct stack s;
void creation()
{
    printf("enter size of the stack : ");
    scanf("%d", &s.size);
    s.top = -1;
    s.a = (char *)malloc(sizeof(char));
}
int isfull()
{
    if(s.top==s.size-1)
    {
        return 1;
    }
    return 0;
}
void push(char exp)
{
    if (isfull())
    {
        printf("\nstack is full\n");
        return;
    }
    s.a[s.top + 1]=exp;
    s.top += 1;
}
int isempty()
{
    if (s.top == -1)
    {
        return 1;
    }
    return 0;
}
void pop(int m)
{
    int n;
    if (isempty())
    {
        printf("\nunbalanced expression\n");
        exit(0);
    }
    n=s.a[s.top];
    s.a[s.top]=' ';
    s.top -= 1;
    if((n+1)!=m)
    {
        printf("\nunbalanced expression\n");
        exit(0);
    }
}
int main()
{
    creation();
    char exp[100];
    printf("\nenter the expression : \n");
    scanf("%s",exp);
    int i;
    for(i=0;exp[i];i++)
    {
        if((exp[i]=='(')||(exp[i]=='{')||(exp[i]=='['))
        push(exp[i]);
        else if((exp[i]==')')||(exp[i]=='}')||(exp[i]==']'))
        pop(exp[i]);
    }
    if (isempty())
    {
        printf("\nbalanced expression\n");
    }
    else
    {
        printf("\nunbalanced expression\n");
    }
    return 0;
}