#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
static int count=0;
static int countnode=0;
struct node *create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
} 
void insert(int data)
{
    struct node *new_node = create_node(data);
    if (new_node!=NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            printf("\nNode having data %d was inserted\n", data);
            return;
        }
        struct node *temp = root;
        struct node *prev = NULL;
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }
        printf("\nNode having data %d was inserted\n", data);
    }
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d\n",root->data);
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\n", root->data);
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
    printf("%d\n",root->data);
}
// Provide user defined function for finding the largest and smallest element in the BST
struct node *smallest_node(struct node *root)
{
    struct node *p = root;
    while (p != NULL && p->left != NULL)
   {
        p = p->left;
    }
    return p;
}
struct node *largest_node(struct node *root)
{
    struct node *p = root;
    while (p != NULL && p->right != NULL)
    {
        p = p->right;
    }
    return p;
} 
// Write a recursive function to find the number of leaf nodes in the tree
int leafnodes(struct node* temp)
{
    if(temp!= NULL)
    {
        leafnodes(temp->left);
        if((temp->left == NULL) && (temp->right == NULL))
        {
            count++;
        }
        leafnodes(temp->right);
    }
    return count;
 
}


int countnodes(struct node *root)
{
    if(root != NULL)
    {
        countnodes(root->left);
        countnode++;
        countnodes(root->right);
    }
    return countnode;
}
int main()
{
    int choice;
    int ch = 'Y';
    int data;
    struct node* result = NULL;
 
    while (ch == 'Y' || ch == 'y')
    {
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Largest Node in Tree:");
        printf("\n3. Smallest Node in Tree:");
        printf("\n4. Inorder ");
        printf("\n5. Post Order");
        printf("\n6. Pre Order");
        printf("\n7. Number of Leaf Node in Tree:\n");
        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);
        printf("\n");
 
        switch(choice)
        {
            case 1:
                printf("\nEnter Data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                result = largest_node(root);
                if (result != NULL)
                {
                    printf("\nLargest Data: %d\n", result->data);
                }
                break;
 
            case 3:
                result = smallest_node(root);
                if (result != NULL)
                {
                    printf("\nSmallest Data: %d\n", result->data);
                }
                break;
 
            case 4:
                inorder(root);
                break;
 
            case 5:
                postorder(root);
                break;
 
            case 6:
                preorder(root);
                break;
            case 7:
                int c=leafnodes(root);
                printf("The number of leaf Node:%d",c);
                break;
            case 8:
                int d=countnodes(root);
                printf("The number of Node in Tree:%d",d);
                break;
            default:
                printf("\n\tInvalid Choice\n");
                break;
        }
 
        printf("\nDo you want to continue? ");
        fflush(stdin);
        scanf(" %c", &ch);
    }
 
    return 0;
}