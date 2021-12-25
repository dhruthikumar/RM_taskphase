// To input a decimal number and print equivalent hexadecimal, octal and binary forms

#include <iostream>
using namespace std;

void Octal(int n)
{
    int octal_arr[100];
    int i = 0;
    while (n != 0) 
    {
        octal_arr[i] = n % 8;
        n = n / 8;
        i++;
    } 
    cout << "Equivalent Octal form: "  ;
    for (int j = i - 1; j >= 0; j--) 
    {
        cout << octal_arr[j];
    }        
}

void Hexadecimal(int n)
{
    char hexadec_arr[100]; 
    int i = 0, temp = 0;
    while (n != 0) 
    {
        temp = n % 16;
        if (temp < 10) 
        {
            hexadec_arr[i] = temp + 48; //ASCII code for 0-9 = 48-57 
            i++;
        }
        else 
        {
            hexadec_arr[i] = temp + 55; //ASCII code for A-Z = 65-90 (10 + 55 = 65)
            i++;
        }
        n /= 16;
    }
    
    cout << "Equivalent Hexadecimal form: "  ;
    for (int j = i - 1; j >= 0; j--)
    {
        cout << hexadec_arr[j];
    }       
}



void Binary(int n)
{
    int binary_arr[100];
    int i = 0;
    while (n != 0) 
    {
        binary_arr[i] = n % 2;
        n = n / 2;
        i++;
    } 
    cout << "Equivalent Binary form: "  ;
    for (int j = i - 1; j >= 0; j--) 
    {
        cout << binary_arr[j];
    }        
}
 

int main()
{
    int dec;
    cout << "Enter an integer (less than 100 digits): ";
    cin >> dec;
    Hexadecimal(dec);
    cout << endl;
    Octal(dec);
    cout << endl;
    Binary(dec);
    return 0;
}