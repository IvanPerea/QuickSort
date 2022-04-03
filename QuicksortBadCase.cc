#include<cstring>
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

int particionamiento(int arr[], int l, int r, int k);
int Smallest(int arr[], int l, int r, int k);

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {

        int n = h-l+1;
        int med = Smallest(arr, l, h, n/2);
        int p = particionamiento(arr, l, h, med);

        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
    }

    int Media(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n/2]; 
}
 

int Smallest(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = Media(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = Media(arr+l+i*5, n%5);
            i++;
        }

        int Med = (i == 1)? median[i-1]:
                                 Smallest(median, 0, i-1, i/2);

        int pos = particionamiento(arr, l, r, Med);

        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1) 
            return Smallest(arr, l, pos-1, k);
 
        return Smallest(arr, pos+1, r, k-pos+l-1);
    }

    return INT_MAX;
}
 
void inter(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
int particionamiento(int arr[], int l, int r, int x)
{

    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    inter(&arr[i], &arr[r]);
 
    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            inter(&arr[i], &arr[j]);
            i++;
        }
    }
    inter(&arr[i], &arr[r]);
    return i;
}
 

void Array(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 

int main()
{
    int arr[] = {1000, 10, 7, 8, 9, 30, 900, 1, 5, 6, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout << "La matriz es\n";
    Array(arr, n);
    return 0;
}

