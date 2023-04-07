#include<stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void addnodelast(int data)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        head = ptr;
        ptr->prev = head;
        ptr->next = head;
        return;
    }
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = head;
    head->prev=ptr;
}
struct node *deletenodeindex(int index)
{
    struct node *p,*q,*r;
    int i=0;
    p=head;
    if(index==0)
    {
        q=head->prev;
        head=head->next;
        q->next=head;
        head->prev=q;
        free(p);
        return head;
    }
    else
    {
    while(i<index-1)
    {
        p=p->next;
        i++;
    }
    q=p->next;
    r=q->next; 
    p->next=r;
    r->prev=p;
    free(q);
    return r;
    }
}
void display(struct node *ptr)
{
    printf("\n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
}
int main()
{
    int i,j, num, n,index,a;
    struct node *p,*ptr;
    printf("enter size of linkedlist : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter a number : \n");
        scanf("%d", &num);
        addnodelast(num);
    }
    display(head);
    ptr=head;
    i=0;
    while (ptr->next != head)
    {
        j=i+1;
        p = ptr->next;
        while (p != head)
        {
            if(p->data==ptr->data)
            {
               p= deletenodeindex(j);
            }
            else
            {
            p=p->next;
            j++;
            }
        }
        ptr=ptr->next;
        i++;
    }
    display(head);
    return 0;
}