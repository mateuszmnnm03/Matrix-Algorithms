//
// Created by Mateusz on 24.10.2025.
//

#include "ai_method.h"
#include "strassen.h"

int nextPower5(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    double n_double = log(n) / log(5);
    int m = static_cast<int>(ceil(n_double));
    return static_cast<long long>(pow(5.0, m));
}

Matrix ai_method(const Matrix &mat1, const Matrix &mat2)
{
    int n = mat1.rows();
    int m = nextPower5(n);

}
Matrix ai_rec(const Matrix &mat1, const Matrix &mat2)
{
    int n = mat1.rows();
    int cut = n / 5;

    if (n <= 16)
    {
        return mat1 * mat2;
    }

    Matrix A11 = mat1.block(0,0,cut,cut);
    Matrix A12 = mat1.block(0,cut,cut,cut);
    Matrix A13 = mat1.block(0,2 * cut,cut,cut);
    Matrix A14 = mat1.block(0, 3 * cut,cut,cut);
    Matrix A15 = mat1.block(0,4 * cut,cut,cut);
    Matrix A21 = mat1.block(cut, 0, cut, cut);
    Matrix A22 = mat1.block(cut, cut, cut, cut);
    Matrix A23 = mat1.block(cut, 2 *cut, cut, cut);
    Matrix A24 = mat1.block(cut, 3 * cut, cut, cut);
    Matrix A25 = mat1.block(cut, 4 * cut, cut, cut);
    Matrix A31 = mat1.block(2 * cut, 0, cut, cut);
    Matrix A32 = mat1.block(2 * cut, cut, cut, cut);
    Matrix A33 = mat1.block(2 * cut, 2 * cut, cut, cut);
    Matrix A34 = mat1.block(2 * cut, 3 * cut, cut, cut);
    Matrix A35 = mat1.block(2 * cut, 4 * cut, cut, cut);
    Matrix A41 = mat1.block(3 * cut, 0, cut, cut);
    Matrix A42 = mat1.block(3 * cut, cut, cut, cut);
    Matrix A43 = mat1.block(3 * cut, 2 * cut, cut, cut);
    Matrix A44 = mat1.block(3 * cut, 3 * cut, cut, cut);

}