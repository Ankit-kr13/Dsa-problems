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
    struct stack s1, s2;
    printf("enter size of the stack : ");
    scanf("%d", &s1.size);
    s2.size = s1.size;
    s1.top = s2.top = -1;
    s1.a = (int *)malloc(s1.size * sizeof(int));
    s2.a = (int *)malloc(s2.size * sizeof(int));
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
    for (i = s1.top; i >= 0; i--)
    {
        push(&s2, pop(&s1));
    }
    printf("\ncontents of stack in reverse are\n");
    display(&s2);
    return 0;
}