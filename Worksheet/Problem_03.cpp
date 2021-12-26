// For all zero elements, corresponding row and column must be replaced with zeroes

#include <iostream>
#include <iomanip>
using namespace std;

int
main ()
{
	int row, col, row0, col0, arrVal;
	cout << "Enter the number of rows: ";
	cin >> row;
	cout << "Enter the number of columns: ";
	cin >> col;

  	int array[row][col];		
  	int i, j;

  	cout << "Enter the elements of your matrix:" << endl;

  	for (i = 0; i < row; i++)
    {
    	for (j = 0; j < col; j++)
		{
		cout << "Enter element [" << i << "][" << j << "]: ";
		cin >> array[i][j];
		}
    }

  	cout << "Matrix: " << endl;

  	for (i = 0; i < row; i++)
    {
      	for (j = 0; j < col; j++)
	{
	  	cout << setw (3) << array[i][j];
	}
      	cout << endl;
    }

  	for (i = 0; i < row; i++)
    {
      	for (j = 0; j < col; j++)
		{
	  	arrVal = array[i][j];

			if (arrVal == 0)
			{
				for (row0 = 0; row0 < row; row0++)
				{
					array[i][row0] = -1;
				}
				for (col0 = 0; col0 < col; col0++)
				{
					array[col0][j] = -1;
				}
			}
	  		else if (arrVal != 0) {}
		}
    }
  
   	for (i = 0; i < row; i++)
    {
      	for (j = 0; j < col; j++)
		{
	  		if(array[i][j] == -1) 
	  		{
	     		array[i][j] = 0; 
	  		}
		}  
    }
  
   	cout << "Result:" << endl;

  	for (i = 0; i < row; i++)
    {
      	for (j = 0; j < col; j++)
		{
	  		cout << setw (3) << array[i][j];	//show row in one line
		}
    cout << endl;
    }
}
