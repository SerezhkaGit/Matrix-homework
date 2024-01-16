#include <iostream>
using namespace std;

class Matrix
{
private:
    int Rows;
    int Cols;
    int** arr1;

public:
    Matrix(int Rows_ = 4, int Cols_ = 4) : Rows{ Rows_ }, Cols{ Cols_ }
    {
        arr1 = new int* [Rows];
        for (int i = 0; i < Rows; i++)
        {
            arr1[i] = new int[Cols];
        }
    }

    Matrix(const Matrix& other) : Rows{ other.Rows }, Cols{ other.Cols }
    {
        arr1 = new int* [Rows];
        for (int i = 0; i < Rows; i++)
        {
            arr1[i] = new int[Cols];
            for (int j = 0; j < Cols; j++)
            {
                arr1[i][j] = other.arr1[i][j];
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < Rows; i++)
        {
            delete[] arr1[i];
        }
        delete[] arr1;
    }

    void auto_filling()
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                arr1[i][j] = rand() % 9;
            }
        }
    }

    friend ostream& operator<<(ostream& out, const Matrix& matrix)
    {
        for (int i = 0; i < matrix.Rows; i++)
        {
            for (int j = 0; j < matrix.Cols; j++)
            {
                out << matrix.arr1[i][j] << ' ';
            }
            out << endl;
        }
        return out;
    }

    friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2)
    {
        Matrix result(matrix1.Rows, matrix1.Cols);
        for (int i = 0; i < matrix1.Rows; i++)
        {
            for (int j = 0; j < matrix1.Cols; j++)
            {
                result.arr1[i][j] = matrix1.arr1[i][j] + matrix2.arr1[i][j];
            }
        }
        return result;
    }

    friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2)
    {
        Matrix result(matrix1.Rows, matrix1.Cols);
        for (int i = 0; i < matrix1.Rows; i++)
        {
            for (int j = 0; j < matrix1.Cols; j++)
            {
                result.arr1[i][j] = matrix1.arr1[i][j] - matrix2.arr1[i][j];
            }
        }
        return result;
    }

    friend Matrix operator*(const Matrix& matrix1, const Matrix matrix2)
    {

        Matrix result(matrix1.Rows, matrix1.Cols);
        for (int i = 0; i < matrix1.Rows; i++)
        {
            for (int j = 0; j < matrix1.Cols; j++)
            {
                result.arr1[i][j] = matrix1.arr1[i][j] * matrix2.arr1[i][j];
            }
        }

        return result;


    }
};

int main()
{
    Matrix first(3, 3);
    first.auto_filling();
    Matrix second(first);

    cout << "First matrix:\n" << first << endl;
    cout << "Second matrix:\n" << second << endl;

    Matrix sum = first + second;
    Matrix sub = first - second;
    Matrix mul = first * second;

    cout << "Result of adding first and second matrix:\n" << sum << endl;
    cout << "Result of substriction first and second matrix:\n" << sub << endl;
    cout << "Result of myltiplying first and second matrix:\n" << mul << endl;

    return 0;
}

