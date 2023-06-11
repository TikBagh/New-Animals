

#include <iostream>


class Matrix
{
private:
    int row;
    int col;
    int** mat;

public: 

    Matrix(int row, int col) : row(row), col(col)
    {
        mat = new int* [row];
        for (int i = 0; i < row; ++i)
        {
            mat[i] = new int[col];

            
            for (int j = 0; j < col; ++j)
                {
                    mat[i][j] = (rand() % 100);
                }
            
          
        }
        std::cout << "First Adress " << &mat << std::endl;
    }

    Matrix(const Matrix& obj) : row(obj.row), col(obj.col)
    {
        mat = new int* [row];
        for (int i = 0; i < row; ++i)
        {
            mat[i] = new int[col];

            for (int j = 0; j < col; ++j)
            {
                mat[i][j] = obj.mat[i][j];
            }
        }
        std::cout << "Adress after copy " <<  & mat << std::endl;
    }

    Matrix operator =(const Matrix& assign)
    {
        if (this != &assign)
        {
            for (int i = 0; i < row; ++i)
            {
                delete[] mat[i];
            }
            delete[] mat;

            row = assign.row;
            col = assign.col;

            mat = new int* [row];
            for (int i = 0; i < row; ++i)
            {
                mat[i] = new int[col];
                {
                    for (int j = 0; j < col; ++j)
                    {
                        mat[i][j] = assign.mat[i][j];
                    }
                }
            }
            std::cout << "Adress after oper. assignement " << &mat << std::endl;
        }
        return *this;
    }


    ~Matrix()
    {
        for (int i = 0; i < row; ++i)
        {
            delete[] mat[i];
        }
        delete[] mat;

    }

    void print()
    {
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                std::cout << " " << mat[i][j];
            }
            std::cout << std::endl;
        }
    }




};

int main()
{
    int rows = 3;
    int cols = 4;

    if (rows > 0 && cols > 0)
    {
        Matrix  matrix(rows, cols);
        matrix.print();
        Matrix matrix1 = matrix;
        Matrix matrix2(rows, cols);
        matrix2 = matrix;

        
    }
    else
    {
        std::cout << "Not a valid row or col" << std::endl;
        
    }


    
    return 0;

    
}

