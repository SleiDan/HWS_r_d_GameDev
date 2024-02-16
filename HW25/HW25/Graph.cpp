#include "Graph.h"

#include <queue>

GraphAdjList::GraphAdjList(int Vertixes, ConnectionType type)
	: Graph(Vertixes, type)
{
	m_list.resize(Vertixes);
}

void GraphAdjList::addEdge(int v, int w)
{
	m_list[v].push_back(w);
	if (m_connectionType == ConnectionType::undirected)
	{
		m_list[w].push_back(v);
	}
}

void GraphAdjList::BFS(int vertex)
{
	// Mark all the vertices as not visited
	std::vector<bool> visited;
	visited.resize(m_vertixes, false);

	std::list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[vertex] = true;
	queue.push_back(vertex);

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		int currentVertex = queue.front();
		
		//or make anything else with it: push to vector, string, pass to another object, whatever
		std::cout << currentVertex << " ";
		
		queue.pop_front();

		// Get all adjacent vertices
		for (int adjacent : m_list[currentVertex])
		{
			if (!visited[adjacent])
			{
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

int GraphAdjList::numberOfNodesInLevel(int level, int startingNode)
{
	level = level - 1;
	if (level < 0 || level >= m_vertixes)
		return 0; // Invalid level

	// Initialize the BFS traversal from the starting vertex
	std::vector<bool> visited(m_vertixes, false);
	std::queue<int> q;
	q.push(startingNode);
	visited[startingNode] = true;

	// Count nodes at the specified level
	int currentLevel = 0;
	int nodesAtLevel = 0;

	while (!q.empty() && currentLevel <= level)
	{
		int size = q.size();
		for (int i = 0; i < size; ++i)
		{
			int vertex = q.front();
			q.pop();
			if (currentLevel == level)
				++nodesAtLevel;
			for (int adjacent : m_list[vertex])
			{
				if (!visited[adjacent])
				{
					q.push(adjacent);
					visited[adjacent] = true;
				}
			}
		}
		++currentLevel;
	}

	return nodesAtLevel;
}

int GraphAdjList::findStartVertex() const {
	for (int i = 0; i < m_vertixes; ++i) {
		if (!m_list[i].empty()) {
			return i; // Return the first vertex with outgoing edges
		}
	}
	return 0; // Default to vertex 0 if no outgoing edges found
}


bool GraphAdjList::isStronglyConnected() const
{
	for (int i = 0; i < m_vertixes; ++i)
	{
		std::vector<bool> visited(m_vertixes, false);
		std::queue<int> q;
		q.push(i);
		visited[i] = true;

		while (!q.empty())
		{
			int vertex = q.front();
			q.pop();
			for (int adjacent : m_list[vertex])
			{
				if (!visited[adjacent])
				{
					q.push(adjacent);
					visited[adjacent] = true;
				}
			}
		}

		for (bool visit : visited)
		{
			if (!visit)
				return false; // Not strongly connected
		}
	}
	return true; // All nodes are reachable from every node
}



