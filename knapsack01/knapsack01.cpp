#include <iostream>
using namespace std;
int max(int a, int b);
void knapsack01(int W, int wt[], int val[], int n);
int main()
{
	cout << "enter Maximum size" << endl;
	int W;
	cin >> W;
	cout << "enter number of items" << endl;
	int n;
	cin >> n;
	int* val = new int[n];
	int* wt = new int[n];
	cout << "enter items value" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	cout << "enter items weight" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> wt[i];
	}
	knapsack01(W, wt, val, n);
	delete val;
	delete wt;
	return 0;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}

void knapsack01(int W, int wt[], int val[], int n)
{
	int i, w;
	int** K = new int* [n+1];
	for (int i = 0; i < n+1; ++i)
		K[i] = new int[W + 1];

	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	int res = K[n][W];
	cout << res << endl;

	w = W;
	for (i = n; i > 0 && res > 0; i--) {

		if (res == K[i - 1][w])
			continue;
		else {
			cout << " " << wt[i - 1];
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}