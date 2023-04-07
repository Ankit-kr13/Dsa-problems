#include <stdio.h>
#include <stdlib.h>

struct bst
{
    int value;
    struct bst *l;
    struct bst *r;
} *root = NULL, *temp = NULL, *t2, *t1;

void insert();
void inorder(struct bst *t);
void create();
void search(struct bst *t);
void preorder(struct bst *t);
void postorder(struct bst *t);
int smallest(struct bst *t);
int largest(struct bst *t);

void create()
{
    int data;

    printf("Enter data of node to be inserted : ");
    scanf("%d", &data);
    temp = (struct bst *)malloc(1 * sizeof(struct bst));
    temp->value = data;
    temp->l = temp->r = NULL;
}
void insert()
{
    create();
    if (root == NULL)
        root = temp;
    else
        search(root);
}

void search(struct bst *t)
{
    if ((temp->value > t->value) && (t->r != NULL))
        search(t->r);
    else if ((temp->value > t->value) && (t->r == NULL))
        t->r = temp;
    else if ((temp->value < t->value) && (t->l != NULL))
        search(t->l);
    else if ((temp->value < t->value) && (t->l == NULL))
        t->l = temp;
}

void inorder(struct bst *t)
{
    if (root == NULL)
    {
        printf("No elements to display");
        return;
    }
    if (t->l != NULL)
        inorder(t->l);
    printf("%d -> ", t->value);
    if (t->r != NULL)
        inorder(t->r);
}

void preorder(struct bst *t)
{
    if (root == NULL)
    {
        printf("No elements to display");
        return;
    }
    printf("%d -> ", t->value);
    if (t->l != NULL)
        preorder(t->l);
    if (t->r != NULL)
        preorder(t->r);
}

void postorder(struct bst *t)
{
    if (root == NULL)
    {
        printf("No elements to display ");
        return;
    }
    if (t->l != NULL)
        postorder(t->l);
    if (t->r != NULL)
        postorder(t->r);
    printf("%d -> ", t->value);
}

int smallest(struct bst *t)
{
    t2 = t;
    if (t->l != NULL)
    {
        t2 = t;
        return (smallest(t->l));
    }
    else
        return (t->value);
}

int largest(struct bst *t)
{
    if (t->r != NULL)
    {
        t2 = t;
        return (largest(t->r));
    }
    else
        return (t->value);
}

void main()
{
    int ch;

    printf("\nOPERATIONS ---");
    printf("\n1 - Insert an element into tree\n");
    printf("2 - Inorder \n");
    printf("3 - Preorder \n");
    printf("4 - Postorder \n");
    printf("5 - Find smallest\n");
    printf("6 - Find largest\n");
    printf("7 - exit\n");
    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            int b = smallest(root);
            printf("%d", b);
            break;
        case 6:
            int a = largest(root);
            printf("%d", a);
            break;
        case 7:
            exit(0);
        default:
            printf("Wrong choice");
            break;
        }
    }
}
