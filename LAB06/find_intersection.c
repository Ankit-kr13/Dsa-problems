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
void intersect(struct node **head1,struct node **head2)
{
    struct node *ptr1=*head1,*ptr2=*head2;
    int n,i=1;
    printf("\nenter the node where you want to intersect\n");
    scanf("%d",&n);
    while(ptr2->next != NULL)
    {
        ptr2=ptr2->next;
    }
    while(i<n)
    {
        ptr1=ptr1->next;
        i++;
    }
    ptr2->next=ptr1;
}
void find_intersection(struct node **head1,struct node **head2)
{
    struct node *ptr1=*head1,*ptr2;
    int i=1;
    while(ptr1!= NULL)
    {
        ptr2=*head2;
        while(ptr2->next!= NULL)
        {
            if(ptr1 == ptr2->next)
            {
                printf("\nnode number %d is point of intersection\n",i);
                return;
            }
            ptr2=ptr2->next;
            
        }
        ptr1=ptr1->next;
        i++;
    }
}
int main()
{
    struct node *head1 = NULL,*head2 = NULL;
    printf("create first linked list\n");
    head1=create(head1);
    printf("create second linked list\n");
    head2=create(head2);
    display(head1);
    display(head2);
    intersect(&head1,&head2);
    display(head1);
    display(head2);
    find_intersection(&head1,&head2);
    return 0;
}