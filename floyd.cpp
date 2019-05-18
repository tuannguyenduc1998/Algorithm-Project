#include <iostream>
using namespace std;
// Number of vertices in the graph 
#define V 4 
#define Vocuc 99999 

void printSolution(int dist[][V]); 

void floydWarshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 

	for (i = 0; i < V; i++) 
		for (j = 0; j < V; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < V; k++) 
	{ 
		
		for (i = 0; i < V; i++) 
		{ 
			
			for (j = 0; j < V; j++) 
			{ 
				
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	printSolution(dist); 
} 

void printSolution(int dist[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == Vocuc) 
				cout<<" "<<"Vocuc"; 
			else
				cout<<"    "<<dist[i][j]; 
		} 
		cout<<"\n"; 
	} 
} 

// driver program to test above function 
int main() 
{ 
	int graph[V][V] = { {0, 9, Vocuc, 3}, 
						{Vocuc, 0, 8, Vocuc}, 
						{5, Vocuc, 0, Vocuc}, 
						{Vocuc, 4, 1, 0} 
					}; 

	// Print the solution 
	floydWarshall(graph); 
	return 0; 
} 

