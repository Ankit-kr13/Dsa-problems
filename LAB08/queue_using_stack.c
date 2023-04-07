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
        printf("\nqueue is full\n");
        return;
    }
    s->top += 1;
    s->a[s->top] = n;
}
int pop(struct stack *s)
{
    if (s->top == - 1)
    {
        printf("\nqueue is empty\n");
        return -99;
    }
    int x;
    x = s->a[s->top];
    s->top -= 1;
    return x;
}
void reverse(struct stack *s1,struct stack *s2)
{
    int i;
    for (i = s1->top; i >= 0; i--)
    {
        push(s2, pop(s1));
    }
}
void enqueue(struct stack *s,int n)
{
    push(s, n);
}
int dequeue(struct stack *s)
{
    struct stack s2;
    int x;
    s2.size = s->size;
    s2.top = -1;
    s2.a = (int *)malloc(s2.size * sizeof(int));
    reverse(s,&s2);
    x=pop(&s2);
    reverse(&s2,s);
    return x;
}
void display(struct stack *s)
{
    printf("\n");
    int i;
    for (i = 0; i <= s->top; i++)
    {
        printf("%d  ", s->a[i]);
    }
}
int main()
{
    struct stack s1;
    printf("enter size of the queue : ");
    scanf("%d", &s1.size);
    s1.top =-1;
    s1.a = (int *)malloc(s1.size * sizeof(int));
    int i, n, a, b;
    printf("\nenter number of elements you want to enqueue in the queue : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter the data to be enqueued : ");
        scanf("%d", &b);
        enqueue(&s1, b);
    } 
    printf("\ncontents of queue are\n");
    display(&s1);
    printf("\nenter number of elements you want to dequeue from the queue : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a=dequeue(&s1);
        if(a==-99)
        {
            break;
        }
        printf("%d is dequeued from the queue\n",a);
    }
    printf("\ncontents of queue are\n");
    display(&s1);
    return 0;
}