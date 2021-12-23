//To check if the given number is a hill number or not

#include <iostream>
using namespace std;

int count_digit (int number) {
    int count = 0;
    while(number != 0) {
        number = number / 10;
        count++;
    }
    return count;
}

int main()
{
    int num = 0, len = 0 , i = 0, j = 0, max = 0, index = 0;
    cout << " Enter a natural number:";  
    cin >> num;
    len = count_digit (num);
    

    int arr[len]; 
    for (int i = len-1; i >= 0; i--)
    {
    arr[i] = num % 10;
    num = num/10;
    }

    for (i = 0; i < len; i++)
    {
        if(arr[i] > max)
        {
        max = arr[i];
        index = i;
        }
    }

    if (index == len - 1 || index == 0) {
        cout << "Not Hill Number";
        return 0;
    }

    for (j = index; j > 0; j--) {
        if (arr[j] <= arr[j-1]) {
            cout << "Not Hill Number";
            return 0;
            }
    }
    for (j = index; j < len-1; j++) {
        if (arr[j] <= arr[j+1]) {
            cout << "Not Hill Number";
            return 0;
            }
    }            

    cout << "Hill Number";    
    return 0; 
}