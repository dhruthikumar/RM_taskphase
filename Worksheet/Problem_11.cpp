// Binary Search using recursion

#include <iostream>
using namespace std;
int Binary_Search(int arr[], int first, int last, int key)
{
    int mid;
    if (first > last)
        return 0;
    mid = (first + last)/2;

    if(arr[mid] == key)
        return (mid + 1);
    else if(arr[mid] > key)
        Binary_Search(arr, first, mid-1, key);
    else if(arr[mid] < key)
        Binary_Search(arr, mid+1, last, key);
}

 
int main() {
 
    int i, n, first, last, position;
    cout << "Enter the number of elements in your array: \n";
    cin >> n;
    int array [n];
 
    cout << "Enter the sorted elements of the array in order: \n";
    for(i = 0; i < n; i++) {
        cin >> array[i];
    }
    
    int search_val;
    cout << "Enter the element to be searched: \n";
    cin >> search_val;
    
    first = 0;
    last = n-1;
 
    position = Binary_Search (array, first, last, search_val);
    cout << "The element '" << search_val << "' is at position: " << position << "(from the left)";
    return 0;
}