

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char blobsMap[200][200];
int BlobCount(int, int, int, int);
int blobCounter[200];

int Islands(int, int);
int N, R;

float xpos = 0.00;
float ypos = 0.00;
int rows, columns;



int main()
{

	int row, column;

	ifstream inFile;
	char karakter;
	string satir = "";
	char inFileName[40];


	cout << fixed << showpoint;
	cout << setprecision(2);


	cout << "\nPlease enter the input file name: ";
	cin >> inFileName;
	cout << endl;
	inFile.open(inFileName);


	if (inFile.is_open())
	{
		inFile >> row;
		inFile >> column;

		N = row;
		R = column;
		rows = row;
		columns = column;
		if (rows > 9)
			rows = rows / 10;
		else
			rows = 1;
		if (columns > 9)
			columns = columns / 10;
		else
			columns = 1;
		cout << "  ";
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j <= 9; j++)
				cout << j;
		}
		cout << endl;
		cout << " +";
		for (int i = 0; i < column; i++)
		{
			cout << "-";
		}
		cout << "+";
		cout << endl;

		getline(inFile, satir);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				getline(inFile, satir);


				cout << j << "|" << satir << "|" << j << endl;
			}

		}
		cout << " ";

		cout << "+";
		for (int i = 0; i < column; i++)
		{
			cout << "-";
		}
		cout << "+";
		cout << endl;
		cout << "  ";
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j <= 9; j++)
				cout << j;
		}
		cout << endl;

		cout << endl << endl << endl;


		cout << "+------+------------+---------+------------+" << endl;
		cout << "| BLOB | NoOfPixels | CoM Row | CoM Column |" << endl;
		cout << "+------+------------+---------+------------+" << endl;

		inFile.close();

	}
	else
	{
		cout << "there is an error.";
	}

	inFile.open(inFileName);


	if (inFile.is_open())
	{
		char s;
		inFile >> row;
		inFile >> column;
		{
			for (int i = 0; i < row + 1; i++)
			{
				for (int j = 0; j < column + 1; j++)
				{
					inFile.get(blobsMap[i][j]);
				}
			}
		}
		inFile.close();


		BlobCount(N, R, row, column);
		Islands(N, R);
		cout << "+------+------------+---------+------------+" << endl;
		cout << endl << endl << endl;
		cout << endl;
	}
	else
	{
		cout << endl << "The file cannot be open or the file does not exist." << endl;
	}

	return 0;
}


int BlobCount(int N, int R, int r, int c)
{

	if (r < 0 || r >= N || c - 1 < 0 || c > R)
		return 0;
	if (blobsMap[r][c] == ' ')

		return 0;

	else
	{
		blobsMap[r][c] = ' ';
		xpos = xpos + r;
		ypos = ypos + c;
		return (1 + BlobCount(N, R, r - 1, c - 1) +
			BlobCount(N, R, r - 1, c) +
			BlobCount(N, R, r - 1, c + 1) +
			BlobCount(N, R, r, c - 1) +

			BlobCount(N, R, r, c + 1) +
			BlobCount(N, R, r + 1, c - 1) +
			BlobCount(N, R, r + 1, c) +
			BlobCount(N, R, r + 1, c + 1));
	}

}


int Islands(int N, int R)
{
	int blobNumber = 0;
	int pixelSize;

	for (int i = 0; i < N*R; i++)
		blobCounter[i] = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < R; j++)
		{

			pixelSize = BlobCount(N, R, i, j);
			if (pixelSize > 0)
			{
				blobCounter[blobNumber] = pixelSize;


				blobNumber++;
				cout << "|" << setw(6) << right << blobNumber << "|" << setw(12) << right << pixelSize << "|" <<
					setw(9) << right << (xpos / pixelSize) << "|" <<
					setw(12) << right << (ypos / pixelSize) - 1 << "|" << endl;

				xpos = 0.00;
				ypos = 0.00;
			}
		}
	}


	return blobNumber;
}
