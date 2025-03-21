#include<stdio.h>
#include<stdlib.h>

#define Max_Vertices 10

struct Graph
{
	int Vertices;
	int adjMatrix[Max_Vertices][Max_Vertices];
};

void initialize(struct Graph* graph, int Vertices)
{
	graph->Vertices = Vertices;
	
	for(int i = 0 ; i < Vertices ; ++i)
	{
		for(int j = 0 ; j < Vertices ; ++j)
		{
			graph->adjMatrix[i][j] = 0;	
		}
	}
}

void addEdge(struct Graph* graph, int source, int destination)
{
	if(source >= 0 && source <= graph->Vertices && destination >= 0 && destination <= graph->Vertices)
	{
		graph->adjMatrix[source][destination] = 1;
		graph->adjMatrix[destination][source] = 1;
	}
}

void dfs(struct Graph* graph, int vertex, int visited[])
{
	printf("%d", vertex);
	visited[vertex] = 1;
	
	for(int i = 0 ; i <= graph->Vertices ; ++i)
	{
		if(graph->adjMatrix[vertex][i] == 1 && !visited[i])
		{
			dfs(graph , i , visited);
		}
	}
}

int main()
{
	struct Graph graph;
	int ch ,Vertices ,edge;
	int source , destination;
	
	printf("Enter the number of vertices(<= %d) and edges::", Max_Vertices);
	scanf("%d %d",&Vertices , &edge);
	initialize(&graph , Vertices);
	
	for(int i = 0 ; i < edge ; ++i)
	{
		printf("Enter the edge number %d in the format of source to destination (space-seperated):",i+1);
		scanf("%d %d",&source,&destination);
		addEdge(&graph , source , destination);
	}
	
	printf("Enter the starting vertex: ");
	int vertex;
	scanf("%d",&vertex);		
	int visited[Max_Vertices] = {0};
	printf("DFS Traversal From The Starting Vertex %d Visited: ", vertex);
	dfs(&graph , vertex , visited);
	printf("\n");

	return 0;
}

