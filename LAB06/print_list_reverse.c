#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void createsingle()
{
    int n;
    printf("enter size of single linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct node *ptr, *p;
        p = head;
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == NULL)
        {
            printf("can't add the node");
            exit;
        }
        printf("\nenter a number : ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = ptr;
        }
    }
}
void reverse(struct node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        reverse(ptr->next);
        printf("%d ",ptr->data);
    }
}
void displaysingle()
{
    struct node *ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    createsingle();
    printf("the following list is\n");
    displaysingle();
    printf("\nthe following list in reverse is\n");
    reverse(head);
    return 0;
}