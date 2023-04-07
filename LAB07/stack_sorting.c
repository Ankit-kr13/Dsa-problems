#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *a;
};
void push(struct stack *s, int n)
{
    if (s->top == s->size - 1)
    {
        printf("\nstack is full\n");
        return;
    }
    s->top += 1;
    s->a[s->top] = n;
}
int pop(struct stack *s)
{
    int x;
    x = s->a[s->top];
    s->top -= 1;
    return x;
}
void sort(struct stack *s1,struct stack *s2,struct stack *s3)
{
    int x;
    while(s1->top != -1)
    {
        x=pop(s1);
        if(s2->a[s2->top] == -1 || s2->a[s2->top]>=x)
        {
            push(s2,x);
        }
        else
        {
            while (s2->a[s2->top]<x && s2->top != -1)
            {
                push(s3,pop(s2));
            }
            push(s2,x);
            while (s3->top != -1)
            {
                push(s2,pop(s3));
            }
        }
    }
}
void display(struct stack *s)
{
    printf("\n");
    int i;
    for (i = s->top; i >= 0; i--)
    {
        printf("| %d |\n", s->a[i]);
    }
    printf("-----");
}
int main()
{
    struct stack s1, s2, s3;
    printf("enter size of the stack : ");
    scanf("%d", &s1.size);
    s3.size = s2.size = s1.size;
    s1.top = s2.top = s3.top = -1;
    s1.a = (int *)malloc(s1.size * sizeof(int));
    s2.a = (int *)malloc(s2.size * sizeof(int));
    s3.a = (int *)malloc(s3.size * sizeof(int));
    int i, n, a, b;
    printf("\nenter number of elements you want to push in the stack : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter the data to be pushed : ");
        scanf("%d", &b);
        push(&s1, b);
    } 
    printf("\ncontents of stack are\n");
    display(&s1);
    sort(&s1,&s2,&s3);
    printf("\ncontents of stack after sorting are\n");
    display(&s2);
    return 0;
}