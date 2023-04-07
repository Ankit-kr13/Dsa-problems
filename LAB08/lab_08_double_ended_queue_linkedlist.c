#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front,*back;
void enqueueback(int d)
{
    struct node*ptr,*p;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nqueue is full\n");
        return;
    }
    ptr->data=d;
    ptr->next=NULL;
    if(front==NULL)
    {
        front=ptr;
        back=ptr;
        return;
    }
    back->next=ptr;
    back=ptr;
}
void enqueuefront(int d)
{
    struct node*ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nqueue is full\n");
        return;
    }
    ptr->data=d;
    ptr->next=NULL;
    if(front==NULL)
    {
        front=ptr;
        back=ptr;
        return;
    }
    ptr->next=front;
    front=ptr;
}
int dequeuefront()
{
    struct node *ptr;
    int x;
    if(front==NULL)
    {
        printf("queue is empty");
        return -99;
    }
    x=front->data;
    if(front==back)
    {
        ptr=front;
        front=back=NULL;
        free(ptr);
        return x;
    }
    ptr=front;
    front=front->next;
    free(ptr);
    return x;
}
int dequeueback()
{
    int x;
    struct node *ptr;
    if(front==NULL)
    {
        printf("queue is empty");
        return -99;
    }
    x=back->data;
    if(front==back)
    {
        ptr=front;
        front=back=NULL;
        free(ptr);
        return x;
    }
    ptr=front;
    while(ptr->next!=back)
    {
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(back);
    back=ptr;
    return x;
}
void display()
{
    printf("\n");
    struct node *ptr;
    ptr=front;
    if(front==NULL)
    {
        printf("queue is empty");
        return;
    }
    printf("the current queue is\n");
    do
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=NULL);
    printf("\n\n");
}
int main()
{
    int n,i,d,x;
    printf("enter the number of elements you want to enter in queue : ");
    scanf("%d",&n);
    printf("enter %d numbers\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&d);
        enqueueback(d);
    }
    display();
    printf("enter the number of elements you want to remove from queue : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        x=dequeueback();
        if(x==-99)
        break;
        printf("%d is dequeued from the queue\n",x);
    }
    display();
    return 0;
}