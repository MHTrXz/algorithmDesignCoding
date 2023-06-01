#include<iostream>

using namespace std;

void mergeofarrays(int a[], int low, int mid, int high);
void mergesort(int a[], int low, int high);
int main()
{
    int n;
    cout << "Enter size of your array" << endl;
    cin >> n;
    int* a = new int[n];
    cout << "Enter your numbers :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n-1);
    cout << "Merge Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    delete a;
}

void mergesort(int a[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergesort(a, low, middle);
        mergesort(a, middle + 1, high);
        mergeofarrays(a, low, middle, high);
    }
}

void mergeofarrays(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, index = low, temp[100], k;
    while ((i <= mid) && (j <= high))
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            i++;
        }
        else {
            temp[index] = a[j];
            j++;
        }
        index++;
    }
    if (i > mid) {
        while (j <= high) {
            temp[index] = a[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid) {
            temp[index] = a[i];
            i++;
            index++;
        }
    }
    for (k = low; k < index; k++)
    {
        a[k] = temp[k];
    }
}