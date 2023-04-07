#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int front, back;
    int size;
    int *a;
};
void enqueue(struct queue *q, int n)
{
    if (q->back == (q->size - 1))
    {
        printf("stack is full");
        return;
    }
    q->back++;
    q->a[q->back] = n;
}
int dequeue(struct queue *q)
{
    if (q->back == q->front)
    {
        printf("stack is empty");
        return -99;
    }
    q->front++;
    int x = q->a[q->front];
    if (q->back == q->front)
    {
        q->front = q->back = -1;
    }
    return x;
}
void push(struct queue *q, int n)
{
    struct queue q1;
    q1.size = q->size;
    q1.front = q1.back = -1;
    q1.a = (int *)malloc(q1.size * sizeof(int));
    enqueue(&q1, n);
    while (q->front != q->back)
    {
        enqueue(&q1, dequeue(q));
    }
    *q = q1;
}
int pop(struct queue *q)
{
    int x;
    x = dequeue(q);
    return x;
}
void display(struct queue q)
{
    int i;
    printf("\nyour queue is\n");
    for (i = q.front + 1; i <= q.back; i++)
    {
        printf("| %d |\n", q.a[i]);
    }
    printf("-----\n");
}
int main()
{
    struct queue q;
    printf("enter the size of stack\n");
    scanf("%d", &q.size);
    q.front = q.back = -1;
    q.a = (int *)malloc(q.size * sizeof(int));
    int i, n, a, b;
    printf("\nenter number of elements you want to push in the stack : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter the data to be pushed : ");
        scanf("%d", &b);
        push(&q, b);
    }
    printf("\ncontents of stack are\n");
    display(q);
    printf("\nenter number of elements you want to pop from the stack : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a = pop(&q);
        if (a == -99)
        {
            break;
        }
        printf("value poped from stack is %d\n", a);
    }
    printf("\ncontents of stack are\n");
    display(q);
    return 0;
}