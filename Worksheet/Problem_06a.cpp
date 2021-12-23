// To find if the given pair of numbers are Amicable numbers or not

#include <iostream>
using namespace std;

int sum_pd (int num) {
    int sum = 0, i;
    for (i = 1; i <= num/2; i++ ) {
        if ( num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main (){
    int num1, num2, sum1, sum2;
    cout << "Enter the first number: " << endl;
    cin >> num1;
    cout << "Enter the second number: " << endl;
    cin >> num2;

    sum1 = sum_pd (num1);
    sum2 = sum_pd (num2);

    if (num1 == sum2 && num2 == sum1){
        cout << "The given numbers are Amicable numbers";
    }
    else {
        cout << "The given numbers are not Amicable numbers";
    }
return 0;
}
