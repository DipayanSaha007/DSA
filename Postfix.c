#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
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

void push(struct Stack* stack, int value)
{
	if(stack->top == N-1)
	{
		printf("stack Overflow!!\n");
	}
	
	stack->data[++stack->top] = value;
}

int pop(struct Stack* stack)
{
	if(stack->top == -1)
	{
		printf("Stack Underflow!!\n");
		exit(EXIT_FAILURE);
	}
	
	return stack->data[stack->top--];
}

int postfix(char* exp)
{
	struct Stack stack;
	initialize(&stack);
	
	for(int i = 0 ; exp[i] != '\0' ; ++i)
	{
		if(isdigit(exp[i]))
		{
			push(&stack , exp[i] - '0');
		}
		else if(exp[i] == ' ')
		{
			continue;
		}
		else
		{
			int operand2 = pop(&stack);
			int operand1 = pop(&stack);
			
			switch(exp[i])
			{
				case '+':
					push(&stack , operand1 + operand2);
					break;
				case '-':
					push(&stack , operand1 - operand2);
					break;
				case '*':
					push(&stack , operand1 * operand2);
					break;
				case '/':
					push(&stack , operand1 / operand2);
					break;
				default:
					printf("Invalid Operator. \n");
					exit(EXIT_FAILURE);
			}
		}
	}
	
	return pop(&stack);
}

int main()
{
	char exp[N];
	
	printf("Enter a postfix expression:");
	scanf("%s",exp);
	
	int result = postfix(exp);
	printf("Result: %d. \n", result);
	
	return 0;
}


















