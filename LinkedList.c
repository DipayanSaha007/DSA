#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* Insert_At_Beginning(struct Node* head, int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = head;
	
	return newNode;
}

struct Node* Insert_At_End(struct Node* head, int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	
	if (head == NULL)
	{
		return newNode;
	}
	
	struct Node* current = head;
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = newNode;
	return head;
}

struct Node* Delete_Node(struct Node* head, int value)
{
	if(head == NULL)
	{
		return NULL;
	}
	
	if(head->data == value)
	{
		struct Node* newhead = head->next;
		free(head);
		return newhead;
	}
	
	struct Node* current = head;
	while(current->next != NULL && current->next->data != value)
	{
		current = current->next;
	}
	
	if(current->next != NULL)
	{
		struct Node* temp = current->next;
		current->next = current->next->next;
		free(temp);
	}
	return head;
}

void display(struct Node* head)
{
	printf("Linked List Elements:");
	struct Node* current = head;
	while(current != NULL)
	{
		printf("%d -> ",current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main()
{
	struct Node* head = NULL;
	int choice, value;
	
	do
	{
		printf("Menu:\n1.Insert at beginning, 2.Insert at end, 3.Delete, 4.Display, 5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the value to enter at the beginning:");
				scanf("%d",&value);
				head = Insert_At_Beginning(head, value);
				break;
			case 2:
				printf("Enter the value to enter at the end:");
				scanf("%d",&value);
				head = Insert_At_End(head, value);
				break;
			case 3:
				printf("Enter the value you want to delete:");
				scanf("%d",&value);
				head = Delete_Node(head, value);
				break;
			case 4:
				display(head);
				break;
			case 5:
				printf("Exiting.....\n");
				break;
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}while(choice != 5);
	
	return 0;
}


