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
    if(ptr==NULL)
    {
        printf("can't add the node");
        return;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
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
void display(struct node *ptr)
{
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
void search(int val)
{
    struct node *ptr;
    ptr = head;
    int i=1;
    while(ptr!=NULL)
    {
        if(ptr->data==val)
        {
            printf("\n%d is present in the list in node number %d",val,i);
            return;
        }
        i++;
        ptr=ptr->next;
    }
    printf("\n%d is not present in the list",val);
}
int main()
{
    int i, num, n,val;
    printf("enter size of linkedlist : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nenter a number : \n");
        scanf("%d", &num);
        addnodelast(num);
    }
    printf("\nthe following linklist is\n");
    display(head);
    printf("\nenter the value to be serched : ");
    scanf("%d",&val);
    search(val);
    return 0;
}