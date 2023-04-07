#include<stdio.h>
#include <stdlib.h>
struct queue
{
    int front,back;
    int size;
    int *a;
};
struct stack
{
    int size;
    int top;
    int *a;
};
void enqueue(struct queue *q,int n)
{
    if(q->back==(q->size-1))
    {
        printf("queue is full");
        return;
    }
    q->back++;
    q->a[q->back]=n;
}
int dequeue(struct queue *q)
{
    q->front++;
    int x=q->a[q->front];
    if(q->back==q->front)
    {
        q->front= q->back =-1;
    }
    return x;
}
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
void reverse(struct queue *q)
{
    struct stack s;
    int x;
    s.size=q->back-q->front;
    s.top=-1;
    s.a = (int *)malloc(s.size * sizeof(int));
    while(q->back!=q->front)
    {
        push(&s,dequeue(q));
    }
    while(s.top != -1)
    {
        enqueue(q,pop(&s));
    }
}
void display(struct queue q)
{
    int i;
    printf("\nyour queue is\n");
    for(i=q.front+1;i<=q.back;i++)
    {
        printf("%d  ",q.a[i]);
    }
    printf("\n\n");
}
int main()
{
    struct queue q;
    printf("enter the size of queue\n");
    scanf("%d",&q.size);
    q.front=q.back=-1;
    q.a=(int *)malloc(q.size*sizeof(int));
    int n,i,num;
    printf("enter number of elements you want to enter in queue : ");
    scanf("%d",&n);
    for(i=q.front+1;i<n;i++)
    {
        printf("enter a number : ");
        scanf("%d",&num);
        enqueue(&q,num);
    }
    display(q);
    reverse(&q);
    display(q);
    return 0;
}