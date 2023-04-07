#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front, *back;
int isfull(struct node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}
void enqueue(int d)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (isfull(ptr))
    {
        printf("\nqueue is full\n");
        return;
    }
    ptr->data = d;
    ptr->next = NULL;
    if (front == NULL)
    {
        front = ptr;
        back = ptr;
        return;
    }
    back->next = ptr;
    back = ptr;
}
void dequeue()
{
    struct node *ptr;
    if (isempty())
    {
        printf("queue is empty");
        return;
    }
    ptr = front;
    front = front->next;
    free(ptr);
}
void display()
{
    printf("\n");
    struct node *ptr;
    ptr = front;
    if (isempty())
    {
        printf("queue is empty");
        return;
    }
    printf("the current queue is\n");
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
int main()
{
    int n, i, d;
    printf("enter the number of elements you want to enter in queue : ");
    scanf("%d", &n);
    printf("enter %d numbers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        enqueue(d);
    }
    display();
    printf("enter the number of elements you want to remove from queue : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        dequeue();
    }
    display();
    return 0;
}