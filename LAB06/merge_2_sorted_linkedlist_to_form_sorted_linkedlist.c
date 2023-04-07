#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addnodelast(struct node **head, int data)
{
    struct node *new, *p;
    p = *head;
    new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL)
    {
        printf("can't add the node");
        exit;
    }
    new->data = data;
    new->next = NULL;
    if (*head == NULL)
    {
        
        *head = new;
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new;
}
struct node * create(struct node *head)
{
    int n, num;
    printf("enter size of single linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a number : ");
        scanf("%d", &num);
        addnodelast(&head, num);
    }
    return head;
}
void display(struct node *head)
{
    printf("\n");
    struct node *ptr;
    ptr=head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct node * sorted_merge(struct node **head1,struct node **head2,struct node *head3)
{
    struct node *ptr1=*head1,*ptr2=*head2;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data<=ptr2->data)
        {
            addnodelast(&head3,ptr1->data);
            ptr1=ptr1->next;
        }
        else
        {
        addnodelast(&head3,ptr2->data);
        ptr2=ptr2->next;
        }
    }
    while(ptr2 != NULL)
    {
        addnodelast(&head3,ptr2->data);
        ptr2=ptr2->next;
    }
    while(ptr1 != NULL)
    {
        addnodelast(&head3,ptr1->data);
        ptr1=ptr1->next;
    }
    return head3;
}
int main()
{
    struct node *head1 = NULL,*head2 = NULL,*head3 = NULL;
    head1=create(head1);
    head2=create(head2);
    display(head1);
    display(head2);
    head3=sorted_merge(&head1,&head2,head3);
    display(head3);
    return 0;
}