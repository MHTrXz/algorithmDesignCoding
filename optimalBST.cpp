#include<iostream>
using namespace std;
int sum(double P[], int i, int j);
int optCost(double P[], int i, int j);
int optimalBST(int K[], double P[], int n);
int main()
{
	int n;
	cout << "how many keys in BST ?" << endl;
	cin >> n;
	int* K = new int[n];
	cout << "Enter your keys" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> K[i];
	}
	double* P = new double[n];
	cout << "enter your keys possibility" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> P[i];
	}
	cout << "Cost of Optimal BST is "<< optimalBST(K, P, n);
	return 0;
}


int optCost(double P[], int i, int j)
{
	if (j < i)
		return 0;
	if (j == i)
		return P[i];
	int fsum = sum(P, i, j);
	int min = INT_MAX;

	for (int r = i; r <= j; ++r)
	{
		int cost = optCost(P, i, r - 1) +
			optCost(P, r + 1, j);
		if (cost < min)
			min = cost;
	}
	return min + fsum;
}

int optimalBST(int K[],double P[], int n)
{
	return optCost(P, 0, n - 1);
}

int sum(double P[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
		s += P[k];
	return s;
}