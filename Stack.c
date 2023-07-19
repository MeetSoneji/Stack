#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int isEmpty(struct Node *root)
{
    return (root == NULL);
}
void push(struct Node **root, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *root;
    *root = newNode;
    printf("%d pushed into stack.\n", data);
}

int pop(struct Node **root)
{
    if (isEmpty(*root))
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    struct Node *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(struct Node *root)
{
    if (isEmpty(root))
    {
        printf("Stack is empty!\n");
        exit(1);
    }
    return root->data;
}
void display(struct Node *root)
{
    if (isEmpty(root))
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements:\n");
    while (root != NULL)
    {
        printf("%d\n", root->data);
        root = root->next;
    }
}
int main()
{
    struct Node *stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(stack);
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(stack));
    display(stack);
    return 0;
}
