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
    q.size+=1;
    q.front=q.back=0;
    q.a[q.size];
}
void enqueue()
{
    if(((q.back+1)%q.size)==(q.front))
    {
        printf("queue is full");
        return;
    }
    q.back=(q.back+1)%q.size;
    printf("enter a number : ");
    scanf("%d",&q.a[q.back]);
}
int dequeue()
{
    int x;
    if(q.back==q.front)
    {
        printf("queue is empty");
        return -99;
    }
    q.front=(q.front+1)%q.size;
    x=q.front;
    if(q.back==q.front)
    {
        q.back=q.front=0;
    }
    return x;
}
void display()
{
    printf("\n");
    if(q.back==q.front)
    {
        printf("queue is empty");
        return;
    }
    int i;
    i=q.front;
    while(i!=q.back)
    {
        i=(i+1)%q.size;
        printf("%d  ",q.a[i]);
    }
    printf("\n\n");
}
int main()
{
    creation();
    int n,i;
    printf("enter number of elements you want to enter in queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        enqueue();
    }
    display();
    printf("enter number of elements you want to remove from queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        dequeue();
    }
    display();
    return 0;
}