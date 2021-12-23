//Sum of digits of a number with recursion

#include <iostream>
using namespace std;

int sum_digits(int n){
    if (n == 0) {
        return 0;
    }
    return (n % 10 + sum_digits(n / 10));
}
 
int main()
{
    int num;
    cout << "Enter a positive integer:";
    cin >> num;
    int result = sum_digits(num);
    cout << "Sum of the digits of the number "<< num << " is "<< result ;
    return 0;
}
