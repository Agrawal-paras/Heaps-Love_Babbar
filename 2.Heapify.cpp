#include <iostream>
#include <heap>
#include <cmath>
using namespace std;

// with 1 based indexing
// if you wanna solve with 0 based indexing then put lest = 2*i + 1 and right = 2*i + 2

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i; // for 0- left=2*i+1
    int right = 2*i + 1; // for 0-right=2*i+2

    if (left <= n && arr[largest] < arr[left]) // for 0- left < n
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right]) // for 0- right < n
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }

}

int main(int argc, char const *argv[])
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n/2; i > 0 ; i--)    // for 0 for(int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "printing array " << endl;

    for (int i = 1; i <=n; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
    
    return 0;
}