//Sorting (bubble/selection) and Binary Search

#include <iostream>
using namespace std;

void Selection_Sort(int arr[], int n)
{   
    for(int i = 0; i < n - 1; ++i)
    {
        int min = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(arr[j] < arr[min])
            min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void Bubble_Sort(int arr[], int n)
{    
    char temp;
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j+1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int Binary_Search(int arr[], int n, int key)
{
    int first, last, mid;
    first = 0;
    last = (n-1);
    mid = (first+last)/2;
    while(first <= last)
    {
        if(arr[mid]<key){
            first = mid+1;}
        else if(arr[mid]==key){
            return (mid+1);}
        else
            {last = mid-1;}
        mid = (first+last)/2;
    }
    return -1;
}


int main()
{
    int n ;
    cout << "Enter the number of elements in your array: ";
    cin >> n;
    int arr[n];
    
    cout<<"Enter " << n << " Numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr [i];
    }

    char sort_type;
    cout << "Enter 's' for Selection sort and 'b' for Bubble sort: ";
    cin >> sort_type;

    if (sort_type == 's')
    {
        Selection_Sort(arr, n);
    }

    if (sort_type == 'b')
    {
        Bubble_Sort(arr, n);
    }

    cout << "The sorted array is: ";
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "Enter the element to be searched: ";
    int search_val, position;
    cin >> search_val;
    position = Binary_Search(arr, n, search_val);
    cout << position;
    if (position != -1)
    {
        cout << "The element '" << search_val << "' is at position: " << position << "(from the left)";
    }
    else
    {
        cout << "The element '" << search_val << "' was not found in the array";
    }
    
    return 0;
}