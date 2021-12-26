//To verify the identity (A.B)' = B' . A'

#include <iostream>
using namespace std;

void enterData(int A[][10], int B[][10], int rA, int cA, int rB, int cB);
void product(int A[][10], int B[][10], int product[][10], int rA, int cA, int rB, int cB);
void display(int AB[][10], int rA, int cB);
void transpose(int mat[][10], int matT[][10], int row, int col);

int main()
{
	int A[10][10], B[10][10], AB[10][10], TA[10][10], TB[10][10], TAB[10][10], TBTA[10][10],rA, cA, rB, cB, i, j, k;

	cout << "Enter the number of rows and columns for  matrix A: " << endl;
	cin >> rA >> cA;

	cout << "Enter the number of rows and columns for  matrix B: " << endl;
	cin >> rB >> cB;

	if (cA != rB)
	{
		cout << "Error! No. of columns of matrix A is not equal to no. of rows of matrix B." << endl;
		return 0;
	}

    enterData(A, B, rA, cA, rB, cB);
    product(A, B, AB, rA, cA, rB, cB);        
    transpose(A, TA, rA, cA);
    transpose(B, TB, rB, cB);
    transpose(AB, TAB, rA, cB);       
    product(TB, TA, TBTA, cB, rB,cA, rA);
                

    cout << "Matrix A:" << endl;
    display(A, rA, cA);
        
    cout << "Transpose of matrix A:" << endl;
    display(TA, cA, rA);
        
    cout << "Matrix B:" << endl;
    display(B, rB, cB);
        
    cout << "Transpose of matrix B:" << endl;
    display(TB, cB, rB); 

    cout << "Matrix AB:" << endl;
    display(AB, rA, cB);
        
    cout << "Transpose of matrix AB:" << endl;
    display(TAB, cB, rA); 
        
    cout << "Matrix (TB * TA):" << endl;
    display(TBTA, cB, rA); 
              
	return 0;
}

void enterData(int A[][10], int B[][10], int rA, int cA, int rB, int cB)
{
	int i, j;
	cout << endl << "Enter the elements of matrix A:" << endl;
	for(i = 0; i < rA; ++i)
	{
		for(j = 0; j < cA; ++j)
		{
			cout << "Enter element a"<< i + 1 << j + 1 << ": ";
			cin >> A[i][j];
		}
	}

	cout << endl << "Enter the elements of matrix B:" << endl;
	for(i = 0; i < rB; ++i)
	{
		for(j = 0; j < cB; ++j)
		{
			cout << "Enter element b" << i + 1 << j + 1 << ": ";
			cin >> B[i][j];
		}
	}
}

void product(int A[][10], int B[][10], int AB[][10], int rA, int cA, int rB, int cB)
{
	int i, j, k;

	for(i = 0; i < rA; ++i)
	{
		for(j = 0; j < cB; ++j)
		{
			AB[i][j] = 0;
		}
	}

	for(i = 0; i < rA; ++i)
	{
		for(j = 0; j < cB; ++j)
		{
			for(k=0; k<cA; ++k)
			{
				AB[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

void display(int AB[][10], int rA, int cB)
{
	int i, j;

	for(i = 0; i < rA; ++i)
	{
		for(j = 0; j < cB; ++j)
		{
			cout << AB[i][j] << " ";
			if(j == cB - 1)
				cout << endl << endl;
		}
	}
}


void transpose(int mat[][10], int matT[][10], int row, int col)
{
	int i, j;

	for(i = 0; i < col; ++i)
	{
		for(j = 0; j < row; ++j)
		{
			matT[i][j] = 0;
		}
	}

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            matT[j][i] = mat[i][j];
    }
}
