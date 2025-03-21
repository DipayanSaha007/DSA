#include<stdio.h>
#include<stdlib.h>

#define Max_Vertices 10

struct Node
{
	int data;
	struct Node* next;
};

struct Graph
{
	int vertices;
	struct Node** list;
};

// Creating a new graph
struct Graph* createGraph(int vertices)
{
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->vertices = vertices;
	graph->list = (struct Node**)malloc(vertices * sizeof(struct Node*));
	
	for(int i = 0 ; i < vertices ; ++i)
	{
		graph->list[i] = NULL;
	}
	return graph;
}

// Adding Edges from source to destination
void addEdge(struct Graph* graph, int source, int destination)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = destination;
	newNode->next = graph->list[source];
	graph->list[source] = newNode;
	
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = source;
	newNode->next = graph->list[destination];
	graph->list[destination] = newNode;
}

void BFS(struct Graph* graph, int startVertex)
{
	int* visited = (int*)malloc(Max_Vertices * sizeof(int));
	for(int i = 0 ; i < graph->vertices ; ++i)
	{
		visited[i] = 0;
	}
	
	int* queue = (int*)malloc(Max_Vertices * sizeof(int));
	int front = -1 , rear = -1;
	
	visited[startVertex] = 1;
	queue[++rear] = startVertex;
	
	printf("BFS Traversel starting from %d visited: ",startVertex);
	
	while(front != rear)
	{
		int currentVertex = queue[++front];
		printf("%d ",currentVertex);
		struct Node* temp = graph->list[currentVertex];
		
		while(temp != NULL)
		{
			int adjVertex = temp->data;
			if(!visited[adjVertex])
			{
				visited[adjVertex] = 1;
				queue[++rear] = adjVertex;
			}
			temp = temp->next;
		}
	}
	free(visited);
	free(queue);
}

int main()
{
	int vertices , edges , source , destination , startVertex;
	//Entering number of vertices and edges
	printf("Enter the number of vertices(<= %d) and edges (space-seperated): ",Max_Vertices);
	scanf("%d %d",&vertices ,&edges);
	struct Graph* graph = createGraph(vertices);
	//Entering Edges
	for(int i = 0 ; i < edges ; ++i)
	{
		printf("Enter Edge Number %d in the form of source to destination (space-seperated): ", i+1);
		scanf("%d %d",&source , &destination);
		addEdge(graph,source,destination);
	}
	
	printf("Enter the starting vertex:");
	scanf("%d",&startVertex);
	BFS(graph,startVertex);
	printf("\n");
	
	return 0;
}




























