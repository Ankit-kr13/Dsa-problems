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
int largest(struct node *root)
{
    struct node *ptr=root;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
}
int smallest(struct node *root)
{
    struct node *ptr=root;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void countleafnode(struct node *root, int *i)
{
    if (root->left == NULL && root->right == NULL)
    {
        *i += 1;
        return;
    }
    if (root->left != NULL)
        countleafnode(root->left, i);
    if (root->right != NULL)
        countleafnode(root->right, i);
}
void countnode(struct node *root, int *i)
{
    if (root == NULL)
    {
        return;
    }
    countnode(root->left, i);
    *i += 1;
    countnode(root->right, i);
}
void treesum(struct node *root, int *sum)
{
    if (root == NULL)
    {
        return;
    }
    treesum(root->left, sum);
    *sum =*sum + root->data;
    treesum(root->right, sum);
}
int main()
{
    struct node *root = NULL;
    int n, i, x, a;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("press 1 to insert new node\npress 2 to traverse in inorder\npress 3 to traverse in preorder\npress 4 to traverse in postorder\npress 5 to get smallest element in the tree\npress 6 to get largest element in the tree\npress 7 to count number of leaf nodes in the tree\npress 8 to count number of nodes in the tree\npress 9 to find sum of all nodes in the tree\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("\nenter number of node you want to add : ");
            scanf("%d", &n);
            printf("enter %d numbers\n", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &x);
                insertnode(&root, x);
            }
            break;
        case 2:
            printf("\ntree in inorder is\n");
            inorder(root);
            break;
        case 3:
            printf("\ntree in preorder is\n");
            preorder(root);
            break;
        case 4:
            printf("\ntree in postorder is\n");
            postorder(root);
            break;
        case 5:
            printf("\n smallest element in the tree is: %d\n", smallest(root));
            break;
        case 6:
            printf("\n largest element in the tree is: %d\n", largest(root));
            break;
        case 7:
            int c = 0;
            countleafnode(root, &c);
            printf("\nnumber of leaf nodes in the tree : %d\n", c);
            break;
        case 8:
            c = 0;
            countnode(root, &c);
            printf("\nnumber of nodes in the tree : %d\n", c);
            break;
        case 9:
            int sum = 0;
            treesum(root,&sum);
            printf("\nsum of all nodes in the tree : %d\n",sum);
            break;
        default:
            printf("\ninvalid input\n");
        }
        printf("\ndo you want to continue(y/n): ");
        scanf(" %c", &ch);
    }
    return 0;
}