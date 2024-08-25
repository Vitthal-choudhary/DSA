//Program to make a binary tree and all kind of traversals using STACKS
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
};

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

struct StackNode* createStackNode(struct TreeNode* node) 
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->node = node;
    stackNode->next = NULL;
    return stackNode;
}

void push(struct StackNode **stack,struct TreeNode *node)
{
    struct StackNode *stackNode = createStackNode(node);
    stackNode->next = *stack;
    *stack = stackNode;
}

struct TreeNode* pop(struct StackNode** stack) 
{
    if (*stack == NULL)
        return NULL;
    struct StackNode* temp = *stack;
    *stack = (*stack)->next;
    struct TreeNode* poppedNode = temp->node;
    free(temp);
    return poppedNode;
}

int isEmpty(struct StackNode* stack) 
{
    return (stack == NULL);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) 
	{
        while (current != NULL) 
		{
            printf("%d ", current->data);
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        current = current->right;
    }
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }

        current = pop(&stack);
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;

    push(&stack1, root);

    while (!isEmpty(stack1)) {
        struct TreeNode* current = pop(&stack1);
        push(&stack2, current);

        if (current->left != NULL)
            push(&stack1, current->left);
        if (current->right != NULL)
            push(&stack1, current->right);
    }

    while (!isEmpty(stack2)) {
        struct TreeNode* current = pop(&stack2);
        printf("%d ", current->data);
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

	root = createNode();
	inorderTraversal(root);
	printf("\n");
	preorderTraversal(root);
	printf("\n");
	postorderTraversal(root);
	
	freeTree(root);
	
	return 0;
}
