//Finding the duplicates and it's multiplicity
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int count;
    struct node *left;
    struct node *right;
};

struct node *createNode(struct node *root, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->count = 1;
    temp->left = NULL;
    temp->right = NULL;

    root = temp;
    return root;
}

struct node *insertElement(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(root, data);
    }

    if (root->data > data)
    {
        root->left = insertElement(root->left, data);
    }

    else if (root->data < data)
    {
        root->right = insertElement(root->right, data);
    }

    else if (root->data == data)
    {
        root->count++;
    }

    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        printf("Count - %d\n", root->count);
        printf(" Number of duplicates - %d\n", root->count-1);
        inorder(root->right);
    }
}

void main()
{
    struct node *root;

    int array[10] = {9, 7, 11, 8, 10, 12, 6, 8, 9, 8};

    for (int i = 0; i < 10; i++)
    {
        root = insertElement(root, array[i]);
    }

    inorder(root);
}