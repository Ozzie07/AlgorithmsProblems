//#include <bits/stdc++.h>
//#define INT_MAX 0x0FFFFFFF
//using namespace std;
//
//int main() {
//	//	freopen("input.txt", "r", stdin);
//	//	freopen("output.txt", "w", stdout);
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	//\n faster than endl. endl makes buffer flush explicitly.
//	
//	//GetInputs
//	int numOfNodes;
//	int numOfEdges;
//	cin >> numOfNodes >> numOfEdges;
//	int** adjArray = new int* [numOfNodes];
//
//	for (size_t i = 0; i < numOfNodes; i++)
//	{
//		adjArray[i] = new int[numOfNodes];
//	}
//
//	int source, destination, weight;
//
//	for (size_t i = 0; i < numOfNodes; i++)
//	{
//		for (size_t j = 0; j < numOfNodes; j++)
//		{
//			adjArray[i][j] = 0;
//		}
//	}
//
//	for (size_t i = 0; i < numOfEdges; i++)
//	{
//		cin >> source >> destination >> weight;
//		source--;
//		destination--;
//		if(adjArray[source][destination] > weight || adjArray[source][destination] == 0)
//			adjArray[source][destination] = weight;
//		//adjArray[destination][source] = weight;
//	}
//
//	//Preparation of Floyd-Warshall algorithm.
//	int** ShortestPathArray = new int* [numOfNodes];
//
//	for (size_t i = 0; i < numOfNodes; i++)
//		ShortestPathArray[i] = new int[numOfNodes];
//
//	for (size_t i = 0; i < numOfNodes; i++)
//	{
//		for (size_t j = 0; j < numOfNodes; j++)
//		{
//			if (i == j) ShortestPathArray[i][j] = 0;
//			else if (adjArray[i][j]) ShortestPathArray[i][j] = adjArray[i][j];
//			else ShortestPathArray[i][j] = INT_MAX;
//		}
//	}
//
//	//Floyd-Washall algorithm
//	for (size_t k = 0; k < numOfNodes; k++)
//	{
//		for (size_t i = 0; i < numOfNodes; i++)
//		{
//			for (size_t j = 0; j < numOfNodes; j++)
//			{
//				ShortestPathArray[i][j] = 
//					min(ShortestPathArray[i][j], 
//					ShortestPathArray[i][k] + ShortestPathArray[k][j]);
//			}
//		}
//	}
//
//	//For You can't go.
//	for (size_t i = 0; i < numOfNodes; i++)
//	{
//		for (size_t j = 0; j < numOfNodes; j++)
//		{
//			if (ShortestPathArray[i][j] == INT_MAX)
//				ShortestPathArray[i][j] = 0;
//		}
//	}
//
//	//AnswerMaker
//	for (size_t i = 0; i < numOfNodes; i++)
//	{
//		for (size_t j = 0; j < numOfNodes; j++)
//		{
//			cout << ShortestPathArray[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//
//
//	return 0;
//}