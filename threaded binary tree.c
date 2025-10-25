#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int val;
    struct tree *right;
    struct tree *left;
    int thread; // 1 => right pointer is a thread (inorder successor)
};

struct tree *root = NULL;

struct tree* insert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{ 											//Null 4 Null 
											//4 2 Null 
											//Null 2 4 
											//4 6 Null 
											//Null 6 Null
    if (root == NULL)
    {
        root = ptr;
        if (rt != NULL)
        {
            root->right = rt;
            root->thread = 1; // make a thread to inorder successor
        }
    }
    else if (ptr->val < root->val)   //2<4 	
									//6<4
    {
        root->left = insert_node(root->left, ptr, root);
    }
    else if (root->thread == 1) 
    {
        root->right = insert_node(NULL, ptr, rt);
        root->thread = 0; 
    }
    else 
    {
        root->right = insert_node(root->right, ptr, rt); //Null 6 Null
    }
    return root;
}

struct tree* create_threaded_tree()
{
    struct tree *ptr;
    int num;

    printf("\nEnter the elements, press -1 to terminate: ");
    scanf("%d", &num);

    while (num != -1)
    {
        ptr = (struct tree*)malloc(sizeof(struct tree));
        ptr->val = num;
        ptr->left = ptr->right = NULL;
        ptr->thread = 0;

        root = insert_node(root, ptr, NULL); //Null 4 Null
											//4 2 Null 
											//4 6 Null
        printf("Enter the next element: ");
        scanf("%d", &num);
    }
    return root;
}

void inorder(struct tree *root)
{
    if (root == NULL) return;

    struct tree *ptr = root, *prev = NULL;

    do
    {
        while (ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        if (prev != NULL)
        {
            printf(" %d", prev->val);
            ptr = prev->right;

            while (prev != NULL && prev->thread)
            {
                printf(" %d", ptr->val);
                prev = ptr;
                ptr = ptr->right;
            }
        }
    } while (ptr != NULL);
}

int main()
{
    create_threaded_tree();

    printf("\nThe in-order traversal of the tree is: ");
    inorder(root);

    return 0;
}

/*
Sample Run:
Enter the elements, press -1 to terminate: 4
Enter the next element: 2
Enter the next element: 6
Enter the next element: 1
Enter the next element: 3
Enter the next element: 5
Enter the next element: 7
Enter the next element: -1

The in-order traversal of the tree is: 1 2 3 4 5 6 7
*/
