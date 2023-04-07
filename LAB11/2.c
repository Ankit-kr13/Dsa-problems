#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createnode(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void insertnode(struct node **root, int data)
{
    struct node *p, *ptr = *root;
    if (*root == NULL)
    {
        *root = createnode(data);
    }
    else
    {
        p = *root;
        while (p != NULL)
        {
            ptr = p;
            if (p->data == data)
            {
                p->data = data;
                return;
            }
            else if (p->data < data)
            {
                p = p->right;
            }
            else
            {
                p = p->left;
            }
        }
        if (ptr->data < data)
        {
            ptr->right = createnode(data);
        }
        else
        {
            ptr->left = createnode(data);
        }
    }
}
void preorder(struct node *root)
{
    struct node *save[100];
    int top = 0;

    if (root == NULL)
    {
        return;
    }

    save[top++] = root;
    while (top != 0)
    {
        root = save[--top];

        printf("[%d] ", root->data);

        if (root->right != NULL)
            save[top++] = root->right;
        if (root->left != NULL)
            save[top++] = root->left;
    }
    printf("\n");
}
void postorder(struct node *root)
{
    struct
    {
        struct node *node;
        unsigned vleft : 1;
        unsigned vright : 1;
    } save[100];
    int top = 0;
    save[top++].node = root;
    while (top != 0)
    {
        if (root->left != NULL && !save[top].vleft)
        {
            save[top].vleft = 1;
            save[top++].node = root;
            root = root->left;
            continue;
        }
        if (root->right != NULL && !save[top].vright)
        {
            save[top].vright = 1;
            save[top++].node = root;
            root = root->right;
            continue;
        }
        printf("[%d] ", root->data);
        save[top].vleft = 0;
        save[top].vright = 0;
        root = save[--top].node;
    }
    printf("\n");
}
void inorder(struct node *root)
{
    struct node *save[100];
    int top = 0;
    while (root != NULL)
    {
        while (root != NULL)
        {
            if (root->right != NULL)
            {
                save[top++] = root->right;
            }
            save[top++] = root;
            root = root->left;
        }
        root = save[--top];
        while (top != 0 && root->right == NULL)
        {
            printf("[%d] ", root->data);
            root = save[--top];
        }
        printf("[%d] ", root->data);
        root = (top != 0) ? save[--top] : (struct node *)NULL;
    }
    printf("\n");
}
int main()
{
    struct node *root = NULL;
    int n, i, x, a;
    printf("\nenter number of node you want to add : ");
    scanf("%d", &n);
    printf("enter %d numbers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insertnode(&root, x);
    }
    printf("\ntree in inorder is\n");
    inorder(root);
    printf("\ntree in preorder is\n");
    preorder(root);
    printf("\ntree in postorder is\n");
    return 0;
}