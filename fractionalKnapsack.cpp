#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
double fractionalKnapsack(struct Item arr[], int N, int size);
bool cmp(struct Item a, struct Item b);
struct Item
{
	int value;
	int weight;
	void set(int v, int w)
	{
		value = v;
		weight = w;
	}
};
int main()
{
	int W;
	cout << "Enter your Knapsack maximum weight:" << endl;
	cin >> W;
	int size;
	cout << "Enter number of your items" << endl;
	cin >> size;

	Item* arr = new Item[size];
	cout << "enter your items value and weight" << endl;
	for (int i = 0; i < size; i++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		arr[i].set(x, y);
	}
	cout << "Maximum profit earned = "
		<< fractionalKnapsack(arr, W, size);
	delete arr;
	return 0;
}
double fractionalKnapsack(struct Item arr[],int N, int size)
{
	sort(arr, arr + size, cmp);
	int curWeight = 0;
	double finalvalue = 0.0;

	for (int i = 0; i < size; i++) {
		if (curWeight + arr[i].weight <= N) {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}
		else {
			int remain = N - curWeight;
			finalvalue += arr[i].value
				* ((double)remain
					/ arr[i].weight);

			break;
		}
	}
	return finalvalue;
}
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}
