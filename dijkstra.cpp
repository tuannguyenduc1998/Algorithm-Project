#include <limits.h> 
#include <iostream>
using namespace std; 
#define V 7

int minDistance(int dist[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == false && dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 


int printSolution(int dist[], int n) 
{ 
	cout<<"Vertex Distance from Source\n"; 
	for (int i = 0; i < V; i++) 
		cout<<i<<"    "<<"tt"<<"      "<< dist[i]<<"\n"; 
} 

void dijkstra(int graph[V][V], int src) 
{ 
	int dist[V]; 

	bool sptSet[V];

	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 

	dist[src] = 0; 

	for (int count = 0; count < V - 1; count++) { 
		int u = minDistance(dist, sptSet); 
		sptSet[u] = true; 
		for (int v = 0; v < V; v++) 
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
				&& dist[u] + graph[u][v] < dist[v]) 
				dist[v] = dist[u] + graph[u][v]; 
	} 

	printSolution(dist, V); 
} 

int main() 
{ 
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 9, 0, 3, 0, 0, 6}, 
						{ 0, 0, 8, 0, 0, 0, 0}, 
						{ 0, 0, 0, 0, 5, 0, 0}, 
						{ 0, 4, 1, 0, 8, 0, 0}, 
						{ 0, 0, 0, 0, 0, 17, 0 }, 
						{ 0, 0, 0, 0, 0, 0, 12 }, 
						{ 0, 0, 0, 2, 4, 0, 0 } };

	dijkstra(graph, 0); 

	return 0; 
} 

