#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *previous;
};
struct node *head;
void addnodelastdouble(int data)
{
    struct node *ptr, *p;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->previous = NULL;
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
    ptr->previous = p;
}
void createdouble()
{
    int n, num;
    printf("enter size of double linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a number : \n");
        scanf("%d", &num);
        addnodelastdouble(num);
    }
}
void addnodefirstdouble(int data)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->previous = NULL;
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        return;
    }
    head->previous = ptr;
    ptr->next = head;
    head = ptr;
}
void addnodeindexdouble(int index, int data)
{
    int i = 0;
    struct node *p, *ptr, *q;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->previous = NULL;
    ptr->data = data;
    ptr->next = NULL;
    if (index == 0)
    {
        head->previous = ptr;
        ptr->next = head;
        head = ptr;
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    q->previous = ptr;
    ptr->next = p->next;
    p->next = ptr;
    ptr->previous = p;
}
void deletenodefirstdouble()
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    head->previous = NULL;
    free(ptr);
}
void deletenodelastdouble()
{
    struct node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
}
void deletenodeindexdouble(int index)
{
    struct node *p, *q, *r;
    int i = 0;
    p = head;
    if (index == 0)
    {
        head = head->next;
        head->previous = NULL;
        free(p);
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    r = q->next;
    p->next = r;
    r->previous = p;
    free(q);
}
void forward_traversedouble()
{
    struct node *ptr, *p;
    ptr = head;
    printf("\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void addnodefirstcircular(int data)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        return;
    }
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    head = ptr;
    p->next = head;
}
void addnodelastcircular(int data)
{
    struct node *ptr, *p;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
        return;
    }
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
}
void createcircular()
{
    int n, num;
    printf("enter size of circularlinkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a number : \n");
        scanf("%d", &num);
        addnodelastcircular(num);
    }
}
void addnodeindexcircular(int index, int data)
{
    int i = 0;
    struct node *p, *ptr;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    if (index == 0)
    {
        ptr->next = head;
        head = ptr;
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void deletenodefirstcircular()
{
    struct node *ptr, *p;
    ptr = head;
    p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(ptr);
}
void deletenodelastcircular()
{
    struct node *p, *q;
    p = head;
    q = head->next;
    while (q->next != head)
    {
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
}
void deletenodeindexcircular(int index)
{
    struct node *ptr, *p, *q;
    int i = 0;
    p = head;
    ptr = head;
    if (index == 0)
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head = head->next;
        ptr->next = head;
        free(p);
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}
void displaycircular()
{
    struct node *ptr;
    ptr = head;
    printf("\n");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
void addnodelastsingle(int data)
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
void createsingle()
{
    int n, num;
    printf("enter size of single linkedlist : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nenter a number : ");
        scanf("%d", &num);
        addnodelastsingle(num);
    }
}
void addnodefirstsingle(int data)
{
    struct node *ptr;
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
    ptr->next = head;
    head = ptr;
}
void addnodeindexsingle(int index, int data)
{
    int i = 0;
    struct node *p, *ptr;
    p = head;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("can't add the node");
        exit;
    }
    ptr->data = data;
    ptr->next = NULL;
    if (index == 0)
    {
        ptr->next = head;
        head = ptr;
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void deletenodefirstsingle()
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
}
void deletenodelastsingle()
{
    struct node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
}
void deletenodeindexsingle(int index)
{
    struct node *p, *q;
    int i = 0;
    p = head;
    if (index == 0)
    {
        head = head->next;
        free(p);
        return;
    }
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
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
    int i, num, n, index, a;
    char ch = 'y';
    printf("\npress 1 to create the linkedlist\npress 0 to exit\n");
    scanf("%d", &a);
    switch (a)
    {
    case (1):
        int s;
        printf("press 1 to create single linkedlist\npress 2 to create double linked list\npress 3 to create cicular linkedlist\n");
        scanf("%d", &s);
        switch (s)
        {
        case 1:
            createsingle();
            while (ch == 'y')
            {
                printf("\npress 1 to display the list\npress 2 to add a node at last\npress 3 to add a node at the beggining\npress 4 to add node at desired index\npress 5 to delete the last node\npress 6 to delete the first node\npress 7 to delete node from desired index\n");
                scanf("%d", &a);
                switch (a)
                {
                case (1):
                    displaysingle();
                    break;
                case (2):
                    printf("\nenter the num you want add in the new last node : \n");
                    scanf("%d", &num);
                    addnodelastsingle(num);
                    break;
                case (3):
                    printf("\nenter the num you want add in the new last node : \n");
                    scanf("%d", &num);
                    addnodefirstsingle(num);
                    break;
                case (4):
                    printf("\nenter the index and the num which you want at that index : \n");
                    scanf("%d %d", &index, &num);
                    addnodeindexsingle(index, num);
                    break;
                case (5):
                    deletenodelastsingle();
                    break;
                case (6):
                    deletenodefirstsingle();
                    break;
                case (7):
                    printf("\nenter the index from where you want to delete the node : \n");
                    scanf("%d", &index);
                    deletenodeindexsingle(index);
                    break;
                default:
                    printf("\ninvalid input\n");
                }
                printf("\ndo want to continue(y/n): ");
                scanf(" %c", &ch);
            }
            break;
        case 2:
            createdouble();
            while (ch == 'y')
            {
                printf("\npress 1 to display the list in forward\npress 2 to add a node at last\npress 3 to add a node at the beggining\npress 4 to add node at desired index\npress 5 to delete the last node\npress 6 to delete the first node\npress 7 to delete node from desired index\n");
                scanf("%d", &a);
                switch (a)
                {
                case (1):
                    forward_traversedouble();
                    break;
                case (2):
                    printf("\nenter the num you want add in the new last node : \n");
                    scanf("%d", &num);
                    addnodelastdouble(num);
                    break;
                case (3):
                    printf("\nenter the num you want add in the new first node : \n");
                    scanf("%d", &num);
                    addnodefirstdouble(num);
                    break;
                case (4):
                    printf("\nenter the index and the num which you want at that index : \n");
                    scanf("%d %d", &index, &num);
                    addnodeindexdouble(index, num);
                    break;
                case (5):
                    deletenodelastdouble();
                    break;
                case (6):
                    deletenodefirstdouble();
                    break;
                case (7):
                    printf("\nenter the index from where you want to delete the node : \n");
                    scanf("%d", &index);
                    deletenodeindexdouble(index);
                    break;
                default:
                    printf("\ninvalid input\n");
                }
                printf("\ndo want to continue(y/n): ");
                scanf(" %c", &ch);
            }
            break;
        case 3:
            createcircular();
            while (ch == 'y')
            {
                printf("\npress 1 to display the list\npress 2 to add a node at last\npress 3 to add a node at the beggining\npress 4 to add node at desired index\npress 5 to delete the last node\npress 6 to delete the first node\npress 7 to delete node from desired index\n");
                scanf("%d", &a);
                switch (a)
                {
                case (1):
                    displaycircular();
                    break;
                case (2):
                    printf("\nenter the num you want add in the new last node : \n");
                    scanf("%d", &num);
                    addnodelastcircular(num);
                    break;
                case (3):
                    printf("\nenter the num you want add in the new first node : \n");
                    scanf("%d", &num);
                    addnodefirstcircular(num);
                    break;
                case (4):
                    printf("\nenter the index and the num which you want at that index : \n");
                    scanf("%d %d", &index, &num);
                    addnodeindexcircular(index, num);
                    break;
                case (5):
                    deletenodelastcircular();
                    break;
                case (6):
                    deletenodefirstcircular();
                    break;
                case (7):
                    printf("\nenter the index from where you want to delete the node : \n");
                    scanf("%d", &index);
                    deletenodeindexcircular(index);
                    break;
                default:
                    printf("\ninvalid input\n");
                }
                printf("\ndo want to continue(y/n): ");
                scanf(" %c", &ch);
            }
            break;
        }
    case (0):
        exit(0);
    default:
        printf("\ninvalid input\n");
    }
    return 0;
}