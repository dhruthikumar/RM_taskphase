// Sorting a character array alphabetically using bubble sort

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter a string: ";
    string toSort;
    cin >> toSort;
    int n = toSort.length();
    char char_array[n];
    
    strcpy(char_array, toSort.c_str());
    int i;
    char temp;

    for(int i = 0; i < n ; i++){

    for(int j = 0; j < n-i-1; j++)
    {
        if(char_array[j+1] < char_array[j])
        {
            temp = char_array[j];
            char_array[j] = char_array[j+1];
            char_array[j+1] = temp;
        }
    }
    }

    for (int i = 0; i < n; i++){
        cout << char_array[i];
    }
        
    return 0;
}
