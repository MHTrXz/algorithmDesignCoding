#include<iostream>
#include<string>
using namespace std;
#define V 100
#define INF 99999
int Size;
int graph[V][V];
int dist[V][V];
void printSolution();
void floydWarshall();
int main()
{
	cout << "Enter size of your graph vortexes" << endl;
	cin >> Size;
	cout << "Enter your graph" << endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			string x;
			cin >> x;
			if(x=="INF")
				graph[i][j] =INF;
			else
			{
				int number = stoi(x);
				graph[i][j] = number;
			}
		}
	}
	floydWarshall();
	return 0;
}

void floydWarshall()
{
	int  i, j, k;
	for (i = 0; i < Size; i++)
		for (j = 0; j < Size; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < Size; k++) {
		for (i = 0; i < Size; i++) {
			for (j = 0; j < Size; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution();
}

void printSolution()
{
	cout << "The following matrix shows the shortest ""distances"" between every pair of vertices \n";
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
				<< "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}