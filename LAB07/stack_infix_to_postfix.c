#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
    struct node *next;
    int precedence;
};
struct node *top;
void push(char, int, char *, int *);
char pop();
void push(char exp, int a, char *new_exp, int *j)
{
    struct node *ptr;
    char n;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nstack is full\n");
        return;
    }
    else
    {
        ptr->precedence = a;
        ptr->data = exp;
        if (top == NULL)
        {
            ptr->next = NULL;
            top = ptr;
            return;
        }
        else if (ptr->precedence > top->precedence)
        {
            ptr->next = top;
            top = ptr;
            return;
        }
        else if (ptr->precedence <= top->precedence)
        {
            while ((top->data != '(') && (ptr->precedence <= top->precedence))
            {
                n = pop();
                new_exp[*j] = n;
                *j = *j + 1;
            }
            ptr->next = top;
            top = ptr;
            return;
        }
    }
}
char pop()
{
    char n;
    struct node *ptr;
    ptr = top;
    n = top->data;
    top = top->next;
    free(ptr);
    return n;
}
int main()
{
    char exp[100], new_exp[100];
    printf("\nenter the expression : \n");
    scanf("%s", exp);
    int i, j = 0, len;
    char ch;
    len = strlen(exp);
    exp[len] = ')';
    len = len + 1;
    exp[len] = '\0';
    for (i = len; i >= 0; i--)
    {
        exp[i+1]=exp[i];
    }
    exp[0]='(';
    for (i = 0; exp[i]; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i], 5, new_exp, &j);
        }
        else if (exp[i] == '+' || exp[i] == '-')
        {
            push(exp[i], 1, new_exp, &j);
        }
        else if (exp[i] == '/' || exp[i] == '*')
        {
            push(exp[i], 2, new_exp, &j);
        }
        else if (exp[i] == '^')
        {
            push(exp[i], 3, new_exp, &j);
        }
        else if (exp[i] == ')')
        {
            ch = pop();
            while (ch != '(')
            {
                new_exp[j] = ch;
                j++;
                ch = pop();
            }
        }
        else
        {
            new_exp[j] = exp[i];
            j++;
        }
    }
    new_exp[j] = '\0';
    printf("\n%s", new_exp);
    return 0;
}