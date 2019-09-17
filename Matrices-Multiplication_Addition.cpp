#include <iostream>
using namespace std;
int** add(int**, int**, int, int, int, int);//prototpe
int** multi(int**, int**, int, int, int, int);//prototype


int main()
{
	cout << "Enter the size of rows of matrix :" << endl;
	int row1;
	cin >> row1;
	cout << "Enter size of coloumns of matrix: " << endl;
	int coloumn1;
	cin >> coloumn1;


	int**sarray = new int*[row1];

	for (int u = 0; u < row1; u++)//declaration of array 
	{
		sarray[u] = new int[coloumn1];
	}

	for (int l = 0; l < row1; l++)//loop for input
	{
		for (int h = 0; h < coloumn1; h++)
		{
			cin >> sarray[l][h];
		}
	}


	cout << "Enter the size of rows of matrix 2:" << endl;
	int rows2;
	cin >> rows2;
	cout << "Enter size of coloumns of matrix: 2" << endl;
	int coloumn2;
	cin >> coloumn2;


	int**barray = new int*[rows2];

	for (int u = 0; u < rows2; u++)//declaration of array 
	{
		barray[u] = new int[coloumn2];
	}

	for (int l = 0; l < rows2; l++)//loop for input
	{
		for (int h = 0; h < coloumn2; h++)
		{
			cin >> barray[l][h];
		}
	}
	system("cls");

	cout << "1st matrix is: " << endl;

	for (int s = 0; s < row1; s++)//loop for printing
	{
		for (int q = 0; q < coloumn1; q++)
		{
			cout << sarray[s][q] << " ";
		}
		cout << endl;
	}

	cout << "2nd matrix is: " << endl;

	for (int s = 0; s < rows2; s++)//loop for printing
	{
		for (int q = 0; q < coloumn2; q++)
		{
			cout << barray[s][q] << " ";
		}
		cout << endl;
	}


	if (row1 == rows2&&coloumn1 == coloumn2)//checks if matrixex can be added
	{

	/*	int **returnedadd;

		returnedadd = add(sarray, barray, row1, coloumn1, rows2, coloumn2);

		cout << "Added matrix is: " << endl;
		for (int s = 0; s < rows2; s++)
		{
			for (int q = 0; q < coloumn2; q++)
			{
				cout << returnedadd[s][q] << " ";
			}
			cout << endl;
		}
*/
		cout << "Matrix after multiplication is: " << endl;

		int **returnedmulti;
		returnedmulti = multi(sarray, barray, row1, coloumn1, rows2, coloumn2);

		for (int s = 0; s < row1; s++)//loop for printing
		{
			for (int q = 0; q < coloumn2; q++)
			{
				cout << returnedmulti[s][q] << " ";
			}
			cout << endl;
		}
	}

	else if (coloumn1 == rows2)//for multiplication
	{

		cout << "Matrix after multiplication is: " << endl;

		int **returnedmulti;
		returnedmulti = multi(sarray, barray, row1, coloumn1, rows2, coloumn2);

		for (int s = 0; s < row1; s++)//for printing
		{
			for (int q = 0; q < coloumn2; q++)
			{
				cout << returnedmulti[s][q] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "They cannot be added and multipied: " << endl;
	}

	for (int u = 0; u < row1; u++)//for deletion
	{
		delete[]sarray[u];
	}
	delete sarray;


	for (int u = 0; u < rows2; u++)//for deletion
	{
		delete[]barray[u];
	}
	delete barray;


	system("pause");
}
int** add(int**sarray, int**barray, int row1, int coloumn1, int rows2, int coloumn2)//for adding
{


	int **addarray = new int*[row1];

	for (int f = 0; f < row1; f++)//declaration
	{
		addarray[f] = new int[coloumn1];
	}

	for (int l = 0; l < rows2; l++)//adding
	{
		for (int d = 0; d < coloumn2; d++)
		{
			addarray[l][d] = sarray[l][d] + barray[l][d];
		}
	}

	return addarray;

}
int** multi(int**sarray, int**barray, int rows1, int coloumns1, int rows2, int coloumns2)//for multipication
{
	int **multiarray = new int*[rows1];

	for (int l = 0; l < rows1; l++)//declaration
	{

		multiarray[l] = new int[coloumns2];

	}
	cout << endl;

	for (int w = 0; w < rows1; w++)//initialization
	{
		for (int x = 0; x < coloumns2; x++)
		{
			multiarray[w][x] = 0;
		}

	}


	for (int s = 0; s < rows1; s++)//for multiplication 
	{
		for (int l = 0; l < coloumns2; l++)
		{
			for (int q = 0; q < coloumns1; q++)
			{
				multiarray[s][l] += sarray[s][q] * barray[q][l];
			}

		}

	}

	return multiarray;
}