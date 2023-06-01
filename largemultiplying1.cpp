#include<iostream>

using namespace std;

int largemultiplying(int u , int v);
int Size(int x);
int Pow(int x, int y);

int main()
{
	int num1, num2;
	cout << "Enter your numbers" << endl;
	cin >> num1;
	cin >> num2;

	cout << num1 << " * " << num2 << " = " << largemultiplying(num1, num2) << endl;
}

int largemultiplying(int u, int v)
{
	int sizeu = Size(u);
	int sizev = Size(v);
	int n = max(sizeu, sizev);
	if (u==0 || v==0)
	{
		return 0;
	}
	else if (n <=3)
	{
		return u * v;
	}
	else
	{
		int m = n / 2;
		int p = Pow(10, m);
		int x = u / p;
		int y = u % p;
		int w = v / p;
		int z = v % p;
		return largemultiplying(x, w)*p*p + (largemultiplying(x , z)+ largemultiplying(w ,y))*p + largemultiplying(y,z);
	}
}

int Size(int x)
{
	int count=0;
	for (int i = 0; i < x; i++)
	{
		x = x / 10;
		count++;
	}
	return count;
}

int Pow(int x, int y)
{
	int res=1;
	for (int i = 0; i < y; i++)
	{
		res = x * res;
	}
	return res;
}