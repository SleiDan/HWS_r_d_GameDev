#include <iostream>
#include "Graph.h"

int getTime() { return 1; }

int main()
{
	GraphAdjList graph(11);

	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);

	graph.addEdge(2, 5);
	graph.addEdge(3, 6);
	graph.addEdge(3, 7);
	
	graph.addEdge(4, 8);
	graph.addEdge(5, 9);
	graph.addEdge(6, 10);


#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif

	// Perform BFS
	std::cout << "BFS traversal: ";
	graph.BFS(1);
	std::cout << std::endl;

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif

	// Test numberOfNodesInLevel
	int startVertex = graph.findStartVertex();
	int level = 3;
	int nodesAtLevel = graph.numberOfNodesInLevel(3, startVertex); // Count nodes at level 3 starting from vertex 1
	std::cout << "Number of nodes at level " << level << ": " << nodesAtLevel << std::endl;

	// Test isStronglyConnected
	bool stronglyConnected = graph.isStronglyConnected();
	if (stronglyConnected)
		std::cout << "Graph is strongly connected.\n";
	else
		std::cout << "Graph is not strongly connected.\n";

	GraphAdjList stronglyConnectedGraph(11);

	// Adding edges to create a strongly connected graph
	stronglyConnectedGraph.addEdge(0, 1);
	stronglyConnectedGraph.addEdge(0, 2);
	stronglyConnectedGraph.addEdge(0, 3);
	stronglyConnectedGraph.addEdge(1, 4);
	stronglyConnectedGraph.addEdge(2, 5);
	stronglyConnectedGraph.addEdge(2, 6);
	stronglyConnectedGraph.addEdge(3, 7);
	stronglyConnectedGraph.addEdge(4, 8);
	stronglyConnectedGraph.addEdge(5, 9);
	stronglyConnectedGraph.addEdge(7, 10);
	stronglyConnectedGraph.addEdge(6, 9);
	stronglyConnectedGraph.addEdge(1, 9);
	stronglyConnectedGraph.addEdge(1, 3);


	bool stronglyConnected2 = stronglyConnectedGraph.isStronglyConnected();
	if (stronglyConnected2)
		std::cout << "Graph is strongly connected.\n";
	else
		std::cout << "Graph is not strongly connected.\n";
}
