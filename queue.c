#include<stdio.h>
#include<stdlib.h>

// making a node
struct Node
{
	int data;
	struct Node* next;	
};

//making a queue
struct Queue
{
	struct Node* front;
	struct Node* rear;
};
int isEmpty(struct Queue* queue)
{
	return(queue->front == NULL);
}

//initializing the queue
void initialize(struct Queue* queue)
{
	queue->front = NULL;
	queue->rear = NULL;
}

// Enqueue function
int enqueue(struct Queue* queue, int value)
{	
	//making new node
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = value;
	newnode->next = NULL;
	
	if(isEmpty(queue))
	{
		queue->front = newnode;
		queue->rear = newnode;
	}
	else
	{
		queue->rear->next = newnode;
		queue->rear = newnode;
	}
	printf("Enqueued: %d \n",value);
}

// Dequeue function
int dequeue(struct Queue* queue)
{
	if(isEmpty(queue))
	{
		printf("The Queue is Empty!!");
	}
	else
	{
		struct Node* temp = queue->front;
		printf("Dequeued: %d \n", temp->data);
		queue->front = temp->next;
		
		if(queue->front == NULL)
			queue->rear == NULL;
		
		free(temp);
	}
}

// Display function
int display(struct Queue* queue)
{
	if(isEmpty(queue))
	{
		printf("The Queue is Empty!!");
	}
	else
	{
		printf("Queue Elements: ");
		struct Node* current = queue->front;
		while(current != NULL)
		{
			printf("%d -> ",current->data);
			current = current->next;
		}
		printf("NULL \n");
	}
}

int main()
{
	struct Queue q;
	initialize(&q);
	int choice, value;
	
	do
	{
		printf("Menu:\n1.Enqueue , 2.Dequeue , 3.Display , 4.Exit:\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number you want to enqueue: ");
				scanf("%d",&value);
				enqueue(&q,value);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				display(&q);
				break;
			case 4:
				printf("Exiting....\n");
				break;
			default:
				printf("Invalid Choice!!\n");
				break;
		}
	}while(choice != 4);
	
	
	return 0;
}



































