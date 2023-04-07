#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void addnodelast(int data)
{
    struct node *ptr, *p;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("can't add the node");
        exit;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
}
void display(struct node *ptr)
{
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void create()
{
    int n, num;
    printf("enter size of single linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a number : ");
        scanf("%d", &num);
        addnodelast(num);
    }
}
void rearrange()
{
    struct node *ptr=head,*p,*q;
    while(ptr->next->next!=NULL)
    {
        p=ptr;
        q=p->next;
        while(q->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        q->next=ptr->next;
        ptr->next=q;
        p->next=NULL;
        ptr=ptr->next->next;
    }
}
int main()
{
    create();
    printf("\noriginal linkedlist");
    display(head);
    rearrange();
    printf("\nnew rearranged linkedlist");
    display(head);
    return 0;
}