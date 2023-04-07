#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size_862;
    int front_862;
    int rear;
    int *a;
};
void create(struct queue *q, int len)
{
    q->size_862 = len;
    q->front_862 = -1;
    q->rear = -1;
    q->a = malloc(q->size_862 * sizeof(int));
}
void enqueue(struct queue *q, int data)
{
    if (q->rear == q->size_862 - 1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        q->rear++;
        q->a[q->rear] = data;
    }
}
int average(struct queue *q)
{
    int sum = 0;

    for (int i = q->front_862 + 1; i <= q->rear; i++)
    {
        sum += q->a[i];
    }
    sum /= q->size_862;
    return sum;
}
void display(struct queue q)
{
    for (int i = q.front_862 + 1; i <= q.rear; i++)
    {
        printf("%d", q.a[i]);
    }
}
int main()
{
    struct queue q;
    enqueue(&q, 11);
    enqueue(&q, 22);
    enqueue(&q, 33);
    enqueue(&q, 44);
    enqueue(&q, 55);

    int sum = average(&q);
    printf("%d", sum);
    display(q);
    return 0;
}