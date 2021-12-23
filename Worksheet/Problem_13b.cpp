//Sum of digits of a number without recursion

#include<iostream>
using namespace std;

int main()
{
    int num, n, sum_digits;
    cout << "Enter a positive integer: ";
    cin >> num;
    n = num;
    for(sum_digits = 0; n > 0; n = n / 10)
    {
        int r;
        r = n % 10;
        sum_digits = sum_digits + r;
    }
    cout << "Sum of the digits of the number "<< num << " is "<< sum_digits ;
    return 0;
}