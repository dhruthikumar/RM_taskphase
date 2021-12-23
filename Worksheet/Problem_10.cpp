//First 40 terms of the Fibonacci sequence using recursion

#include <iostream>
using namespace std;

int fib(int y) {
   if(y <= 1) {
      return(y);
    }
   else {
      return(fib(y-1)+fib(y-2));
    }
}

int main() {
   int x = 40, i = 0;
   while(i < x) {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}