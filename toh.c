#include<stdio.h>

void Tower_of_Hanoi(int n, char source, char auxiliary, char destination)
{
	if(n == 1)
	{
		printf("Move Disk %d from %c to %c. \n",n ,source ,destination);
		return;
	}
	
	Tower_of_Hanoi(n-1 ,source ,destination ,auxiliary);
	printf("Move Disk %d from %c to %c. \n",n ,source ,destination);
	Tower_of_Hanoi(n-1 ,auxiliary ,source ,destination);
}

int main()
{
	int n;
	
	printf("Enter the number of disk: ");
	scanf("%d",&n);
	
	Tower_of_Hanoi(n ,'A' ,'B' ,'C' );
	
	return 0;
}



