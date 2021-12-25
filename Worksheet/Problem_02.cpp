//Multiplying two matrices

#include <iostream>
using namespace std;

int main()
{
    int r1, c1, r2, c2, i, j, k;

    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> r2 >> c2;
    int a[r1][c1], b[r2][c2], product[r1][c2];

    while (c1!=r2)
    {
        cout << "Error! No. of columns of first matrix is not equal to no. of rows of second matrix.";
    }

    cout << "Enter the elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            product[i][j]=0;
        }


    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                product[i][j] += a[i][k] * b[k][j];
            }

    cout << endl << "Product Matrix: " << endl;
    for(i = 0; i < r1; ++i)
    for(j = 0; j < c2; ++j)
    {
        cout << " " << product[i][j];
        if(j == c2-1)
            cout << endl;
    }
    return 0;
}
