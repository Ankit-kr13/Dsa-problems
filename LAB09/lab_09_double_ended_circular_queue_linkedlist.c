#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front,*back;
int isempty();
int isfull(struct node*);
void enqueue(int);
void dequeue();
void display();
int isfull(struct node*ptr)
{
    if(ptr==NULL)
    {
        return 1;
    }
    return 0;
}
int isempty()
{
    if(front==NULL)
    {
        return 1;
    }
    return 0;
}
void enqueueback(int d)
{
    struct node*ptr,*p;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(isfull(ptr))
    {
        printf("\nqueue is full\n");
        return;
    }
    ptr->data=d;
    if(front==NULL)
    {
        front=ptr;
        back=ptr;
        ptr->next=front;
        return;
    }
    back->next=ptr;
    ptr->next=front;
    back=ptr;
}
void enqueuefront(int d)
{
    struct node*ptr,*p;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(isfull(ptr))
    {
        printf("\nqueue is full\n");
        return;
    }
    ptr->data=d;
    if(front==NULL)
    {
        front=ptr;
        back=ptr;
        ptr->next=front;
        return;
    }
    ptr->next=front;
    back->next=ptr;
    front=ptr;
}
int dequeuefront()
{
    struct node *ptr;
    int x;
    if(isempty())
    {
        printf("queue is empty");
        return -99;
    }
    if(front==back)
    {
        ptr=front;
        front=back=NULL;
        free(ptr);
        return x;
    }
    ptr=front;
    front=front->next;
    back->next=front;
    x=ptr->data;
    free(ptr);
    return x;
}
int dequeueback()
{
    struct node *ptr;
    int x;
    if(isempty())
    {
        printf("queue is empty");
        return -99;
    }
    if(front==back)
    {
        ptr=front;
        front=back=NULL;
        free(ptr);
        return x;
    }
    ptr=front;
    while(ptr->next != back)
    {
        ptr=ptr->next;
    }
    ptr->next=front;
    x=back->data;
    free(back);
    back=ptr;
    return x;
}
void display()
{
    printf("\n");
    struct node *ptr;
    ptr=front;
    if(isempty())
    {
        printf("queue is empty");
        return;
    }
    printf("the current queue is\n");
    do
    {
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    } while (ptr!=front);
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