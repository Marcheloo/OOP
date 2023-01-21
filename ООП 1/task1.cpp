#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void Clear(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void GetIndexMax(int** matrix, int n)
{
    int j_ind, i_ind;
    int max_el = -10000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > max_el)
            {
                max_el = matrix[i][j];
                j_ind = j;
                i_ind = i;
            }
        }
    }
    cout << "Index of max element: " << i_ind << " " << j_ind << endl;
}

void CoutNegative(int** matrix, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] < 0)
                count++;
        }
    }
    cout << "negative elements: " << count << endl;
}

bool IsSimple(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        return true;
    }
}

void GetGeometr(int** matrix, int n)
{
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
                if (IsSimple(matrix[i][j]) && matrix[i][j] > 0)
                    count *= matrix[i][j];
        }
    }
    cout << "geometry mean : " << pow(count, 1.0 / n) << endl;
}

void transpose(int** matrix, int n)
{
    int t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}

void task2(int** matrixB, int n)
{
    int** matrixBT = matrixB;
    transpose(matrixBT, n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << 3 * matrixB[j][i] + matrixBT[j][i] << " ";
        }
        cout << endl;
    }
}

int main()
{

    cout << "Poryadok matrix: " << endl;

    int n;
    cin >> n;

    cout << "Elements matrix: ";

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    };

    GetIndexMax(matrix, n);
    CoutNegative(matrix, n);
    GetGeometr(matrix, n);

    cout << "Poryadok matrix: " << endl;

    int m;
    cin >> m;

    cout << "Elements matrix: ";

    int** matrix2 = new int* [m];
    for (int i = 0; i < m; i++)
        matrix2[i] = new int[m];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix2[i][j];
        }
    };
    task2(matrix2, m);

    Clear(matrix, n);
    Clear(matrix2, m);

    return 0;
}