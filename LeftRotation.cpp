#include <bits/stdc++.h>
using namespace std;
 
/*Function to reverse arr[] from index start to end*/
void reverseArray(int arr[], int start, int end)
{
    while (start < end) {
        
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
 
/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
        return;
    // in case the rotating factor is
    // greater than array length
    d = d % n;
 
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, n-d-1);
    reverseArray(arr, n-d, n-1);
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
 
/* Driver program to test above functions */
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output1.txt","w",stdout);
    #endif

    int arr[] = { 1, 2, 3, 4, 5, 6, 7 ,8 ,9 ,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;
 
    // Function calling
    leftRotate(arr, d, n);
    printArray(arr, n);
 
    return 0;
}