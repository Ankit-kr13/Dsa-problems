#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front,back;
    int size;
    int a[];
};
struct queue q;
void creation()
{
    printf("enter the size of queue\n");
    scanf("%d",&q.size);
    q.front=q.back=-1;
    q.a[q.size];
}
void enqueue()
{
    if(q.back==(q.size-1))
    {
        printf("queue is full");
        return;
    }
    q.back++;
    printf("enter a number : ");
    scanf("%d",&q.a[q.back]);
}
int dequeue()
{
    int x;
    if(q.back==q.front)
    {
        printf("can't remove from queue the queue is empty");
        return -99;
    }
    q.front++;
    x=q.front;
    if(q.back==q.front)
    {
        q.back=q.front=-1;
    }
    return x;
}
void display()
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
    creation();
    int n,i,x;
    printf("enter number of elements you want to enter in queue : ");
    scanf("%d",&n);
    for(i=q.front+1;i<n;i++)
    {
        enqueue();
    }
    display();
    printf("enter number of elements you want to remove from queue : ");
    scanf("%d",&n);
    for(i=q.front+1;i<n;i++)
    {
        x=dequeue();
        if(x==-99)
        break;
        printf("%d is dequeued from the queue\n",x);
    }
    display();
    return 0;
}