#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int front,back;
    int size;
    int *a;
};
struct queue q;
int isfull();
int isempty();
void display();
void enqueueback();
void enqueuefront();
int dequeueback();
int dequeuefront();
void creation()
{
    printf("enter the size of queue\n");
    scanf("%d",&q.size);
    q.size+=1;
    q.front=q.back=0;
    q.a=(int *)malloc(q.size*sizeof(int));
}
int isfull()
{
    if(q.front==(q.back+1)%q.size)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if(q.back==q.front)
    {
        return 1;
    }
    return 0;
}
void enqueuefront()
{
    if(isfull())
    {
        printf("queue is full");
        return;
    }
    printf("enter a number : ");
    scanf("%d",&q.a[q.front]);
    q.front=((q.size-1)+q.front)%q.size;
}
void enqueueback()
{
    if(isfull())
    {
        printf("\nqueue is full can not enter from back\n");
        return;
    }
    q.back=(q.back+1)%q.size;
    printf("enter a number : ");
    scanf("%d",&q.a[q.back]);
}
int dequeuefront()
{
    if(isempty())
    {
        printf("can't remove from queue the queue is empty");
        return -99;
    }
    q.front++;
    return q.front;
}
int dequeueback()
{
    if(isempty())
    {
        printf("can't remove from queue the queue is empty");
        return -99;
    }
    int x=q.back;
    q.back--;
    return x;
}
void display()
{
    printf("\n");
    int i=q.front;
    do
    {
        i=(i+1)%q.size;
        printf("%d  ",q.a[i]);
    }
    while(i!=q.back);
    printf("\n\n");
}
int main()
{
    creation();
    int n,i,x;
    printf("enter number of elements you want to enter in queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        enqueueback();
    }
    display();
    printf("enter number of elements you want to remove from back of queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        x=dequeueback();
        if(x==-99)
        break;
        printf("%d is dequeued from the queue\n",x);
    }
    display();
    printf("enter number of elements you want to enter from front of queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        enqueuefront();
    }
    display();
    printf("enter number of elements you want to remove from front of queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        x=dequeuefront();
        if(x==-99)
        break;
        printf("%d is dequeued from the queue\n",x);
    }
    display();
    return 0;
}