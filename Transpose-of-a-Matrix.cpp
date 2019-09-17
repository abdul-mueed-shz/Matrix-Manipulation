#include <iostream>
using namespace std;

bool checksymmetric(int**, int**,int,int);


int main()
{
	cout << "Enter the number of row: "; int rows; cin >> rows;
	cout << "Enter the number of columns:"; int columns; cin >> columns;
	system("cls");

	int **matrix = new int*[rows];
	for (int x = 0; x < rows; x++)
	{
		matrix[x] = new int[columns];
	}
	cout << "FILL THE MATRIX:" << endl;

	for (int g = 0; g < rows; g++)
	{
		for (int d = 0; d < columns; d++)
		{
			cout << "Enter row:" << g + 1;
			cout << " Element:" << d + 1 << endl;
			cin >> matrix[g][d];
			system("cls");
		}
	}
	system("cls");
	cout << "MATRIX IS:" << endl;
	for (int f = 0; f < rows; f++)
	{
		for (int a = 0; a < columns; a++)
		{
			cout << matrix[f][a]<<" ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;

	cout << "TRANSPOSE OF A MATRIX IS:" << endl;

	int row2 = columns;
	int columns2 = rows;


	int **transpose = new int*[row2];
	for (int s = 0; s < row2; s++)
	{
		transpose[s] = new int[columns2];
	}

	for (int i = 0; i < row2; i++)
	{
		for (int j = 0; j < columns2; j++)
		{
			transpose[i][j] = matrix[j][i];
		}
	}

	for (int g = 0; g < row2; g++)
	{
		for (int k = 0; k < columns2; k++)
		{
			cout << transpose[g][k]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	if (checksymmetric(matrix, transpose, rows, columns) == true)
	{
		cout << endl;
		cout << "<Entered Matrix is symmetric>" << endl;
	}
	else if (checksymmetric(matrix, transpose, rows, columns) == false)
	{
		cout << endl;
		cout << "<Entered matrix is not symmetric>" << endl;
	}
	system("pause");
}

bool checksymmetric(int**matrix, int**transpose,int rows,int columns)
{
	if (rows != columns)
	{
		//cout << "Dimensions are not equal,Hence matrix can't be symmetric " << endl;
		return false;
	}
	else if (rows == columns)
	{
		bool condi = true;

		for (int f = 0; f < rows; f++)
		{
			for (int m = 0; m < columns; m++)
			{
				if (matrix[f][m] != transpose[f][m])
				{
					condi = false;
				}
			}
		}
		return condi;
	}

}