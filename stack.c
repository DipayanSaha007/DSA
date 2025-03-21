#include<stdio.h>
#include<stdlib.h>
#define N 100

struct Stack
{
	int top;
	int data[N];
};

void initialize(struct Stack* stack)
{
	stack->top = -1;
}

int isFull(struct Stack* stack)
{
	return stack->top == N-1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

int push(struct Stack* stack, int value)
{
	if (isFull(stack))
	{
		printf("Stack is Full!!\n");
	}
	else
	{
		stack->data[++stack->top] = value;
		printf("%d inserted.\n",value);
	}
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("Stack is Empty!!\n");
	}
	else
	{
		printf("%d deleted.\n",stack->data[stack->top--]);
	}
}

int display(struct Stack* stack)
{	
	if (isEmpty(stack))
	{
		printf("Stack is Empty!!\n");
	}
	else
	{
		printf("Stack Elements:");
		for(int i = 0 ; i<= stack->top ; i++)
		{
			printf("%d ",stack->data[i]);
		}
		printf("\n");
	}

}

int main()
{
	struct Stack stack;
	initialize(&stack);
	int choice, value;
	
	do
	{
		printf("Menu:\n1.Push , 2.Pop , 3.Display , 4.Exit:\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the number you want to insert: ");
				scanf("%d",&value);
				push(&stack,value);
				break;
			case 2:
				pop(&stack);
				break;
			case 3:
				display(&stack);
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




















