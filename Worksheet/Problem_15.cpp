// Bubble sort using recursion

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int temp;
    if (n == 1){
        return;
    }
    for(int i = 0; i < n-1 ; i++){
        if(arr[i+1] < arr[i])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
        bubble_sort(arr, n-1);
    }
}

int main()
{
    int num;
    cout << "Enter the number of elements in the array: " << endl;
    cin >> num;
    int array [num];
    cout<<"Enter " << num << " Numbers: ";
    for (int i = 0; i < num; i++)
        cin >> array[i];
    
    bubble_sort(array, num);    

    for (int i = 0; i < num; i++){
        cout << array[i];
    } 
    return 0;
}
