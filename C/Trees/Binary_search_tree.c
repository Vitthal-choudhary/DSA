#include<stdio.h>
#include<stdlib.h>

struct BST_Node{
    int data;
    struct BST_Node *left, *right;
};

struct BST_Node* Create_BST(int val){
    struct BST_Node *new_bst_node = (struct BST_Node*)malloc(sizeof(struct BST_Node));
    new_bst_node->data = val;
    new_bst_node->left = NULL;
    new_bst_node->right = NULL;
    return new_bst_node;
}

struct BST_Node* Insert_Node(struct BST_Node *root, int data){
    if (root == NULL)
    {
        root = Create_BST(data);
    }
    else if (data<=root->data)
    {
        root->left = Insert_Node(root->left,data);
    }
    else{
        root->right = Insert_Node(root->right, data);
    }

    return root;   
}

struct BST_Node* Search(struct BST_Node *root, int val){
    if (root == NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    if (root->data == val)
    {
        printf("Found\n");
        return root;
    }
    else if (root->data > val)
    {
        return Search(root->left, val);
    }
    else
    {
        return Search(root->right, val);
    }
}


void InOrder(struct BST_Node *root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);	
	}	
}

void PreOrder(struct BST_Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void PostOrder(struct BST_Node *root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

void freeTree(struct BST_Node *root)
{
	if (root != NULL)
	{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

int main(){
    // 1st Create a tree

    struct BST_Node *root = NULL;
    int vals;
    printf("Enter value for root  ");
    scanf("%d", &vals);

    root = Create_BST(vals);
    while (vals!=-1)
    {
        printf("Enter value for nodes  [-1 to stop]  ");
        scanf("%d", &vals);
        if (vals!=-1)
        {
            root = Insert_Node(root, vals);
        }
        else
            break;
    }

    // 2. Choices
    int choice;
    printf("Enter your Choice.\n1. For Pre Order Treaversal\n2. For In Order Traversal\n3. For Post Order Traversal\n4. To Search an Element\n5. To Exit");

    do
    {
        scanf("%d", &choice);
        if (choice==1){
            PreOrder(root);
            printf("\n");
        }
        else if (choice==2){
            InOrder(root);
            printf("\n");
        }
        else if (choice==3){
            PostOrder(root);
            printf("\n");
        }
        else if (choice==4)
        {
            printf("Enter value to Search  ");
            scanf("%d", &choice);
            Search(root, choice);
        }
        else if (choice==5)
        {
            freeTree(root);
            exit(0);
        }
        else
            printf("Wrong Choice\n");  
    } while (choice!=5);

    return 0;
}