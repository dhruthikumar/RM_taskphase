// Euclidean algorithm to find the greatest common divisor

#include <iostream>
using namespace std;

int main ()
{
    int a, b, R;
    cout << "Enter two natural numbers: " << endl;
    cin >> a >> b;
    while ( a%b > 0)
    {
        R = a % b;
        a = b;
        b = R;
    }
    cout << "The GCD of the given two numbers is: " << b;
    return 0;
}
