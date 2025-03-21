#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

struct Node* insertNode(struct Node* root, int value)
{
	if(root == NULL)
	{
		return createNode(value);
	}
	
	if(value < root->data)
	{
		root->left = insertNode(root->left, value);
	}
	else if(value > root->data)
	{
		root->right = insertNode(root->right, value);
	}
	return root;
}

void preorder(struct Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	struct Node* stack[100];
	int top = -1;
	stack[++top] = root;
	while(top >= 0)
	{
		struct Node* current = stack[top--];
		printf("%d ",current->data);
		
		if(current->right != NULL)
		{
			stack[++top] = current->right;
		}
		if(current->left != NULL)
		{
			stack[++top] = current->left;
		}
	}
}

void inorder(struct Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	struct Node* stack[100];
	int top = -1;
	struct Node* current = root;
	
	while(current != NULL || top >= 0)
	{
		while(current != NULL)
		{
			stack[++top] = current;
			current = current->left;
		}
		current = stack[top--];
		printf("%d ",current->data);
		current = current->right;
	}
}

void postorder(struct Node* root)
{
	if(root == NULL)
	{
		return;
	}
	
	struct Node* stack1[100];
	struct Node* stack2[100];
	int top1 = -1;
	int top2 = -1;
	
	stack1[++top1] = root;
	while(top1 >= 0)
	{
		struct Node* current = stack1[top1--];
		stack2[++top2] = current;
		if(current->left != NULL)
		{
			stack1[++top1] = current->left;
		}
		if(current->right != NULL)
		{
			stack1[++top1] = current->right;
		}
	}
	while (top2 >= 0) 
	{
        	printf("%d ", stack2[top2--]->data);
        }
}

// Function to calculate the height of the BST
int calculateHeight(struct Node* root , int k) 
{
	if (root == NULL) 
	{
		return 0;
	}
	return k;
    
}


int main()
{
	struct Node* root = NULL;
	int ch , value , k = 0;
	
	do
	{
		printf("BST Menu:\n1.Insert Value, 2.Preorder Traversel, 3.Inorder Traversel, 4.Postorder Traversel, 5.Height of the tree, 6.Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&value);
				root = insertNode(root, value);
				k++;
				break;
			case 2:
				printf("Preorder Traversel:");
				preorder(root);
				printf("\n");
				break;
			case 3:
				printf("Inorder Traversel:");
				inorder(root);
				printf("\n");
				break;
			case 4:
				printf("Postorder Traversel:");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("Height of the BST: %d\n", calculateHeight(root , k));
				break;

			case 6:
				printf("Exitting....\n");
				break;
			default:
				printf("Invalid Choice!!\n");
		}
	}while(ch != 6);
	return 0;
}


































