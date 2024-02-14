//Program to make a binary tree and all kind of traversals using RECURSION
#include <Stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

//Function with return type TreeNode Pointer :--- to create tree using recursion.
struct TreeNode* createNode() 	
{
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int value;
    printf("Enter value");
    scanf("%d", &value);
    if (value==-1)
    	return NULL;
    newNode->data = value;
    printf("Left child of %d -->  (-1 for no child)\n", value);
    newNode->left = createNode();									// every time it will return NewNode that will have the address eventually
    printf("Right child of %d -->  (-1 for no child)\n", value);
    newNode->right = createNode();
    return newNode;
}

void InOrder(struct TreeNode *root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);	
	}	
}

void PreOrder(struct TreeNode *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(struct TreeNode *root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

void freeTree(struct TreeNode *root)
{
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main()
{
	struct TreeNode *root = NULL;
	int choice,value,i;
        
	// Constructing the tree;
	root = createNode();
	
	do
	{
		printf("\nBinary Tree Operations\n1. In-order Traversal\n2. Pre-order Traversal\n3. Post-order Traversal\n4. Exit\n");
	    printf("Enter your choice: ");
        scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("In-order Traversal :\n");
				InOrder(root);
				printf("\n");
				break;
			case 2:
				printf("Pre-order Traversal:\n");
                PreOrder(root);
                printf("\n");
                break;
            case 3:
            	printf("Post-order Traversal:\n");
                PostOrder(root);
                printf("\n");
                break;
            case 4:
            	printf("Exiting!!!!!");
            	break;
            default:
            	printf("Wrong Choice !\n");
		}
	}while (choice != 4);
	
	freeTree(root);
	printf("Memory freed!");
	return 0;
}
