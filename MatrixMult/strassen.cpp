//
// Created by Mateusz on 24.10.2025.
//

#include "strassen.h"

tuple<Matrix, Matrix, Matrix, Matrix> split(const Matrix& M, int n) { // Matrix split, complexity O(n^2)
    int half = n / 2;

    Matrix A11 = M.block(0, 0, half, half);
    Matrix A12 = M.block(0, half, half, half);
    Matrix A21 = M.block(half, 0, half, half);
    Matrix A22 = M.block(half, half, half, half);


    return {A11, A12, A21, A22};
}

int nextPower(int n) {
    if (n == 0) return 1;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}


Matrix strassenRec(const Matrix &mat1, const Matrix &mat2) {
    int n = mat1.rows();
    int half = n / 2;

    if (n <= 16)
    {
        return mat1 * mat2;
    }
    auto [A, B, C, D] = split(mat1, n);
    auto [E, F, G, H] = split(mat2, n);

    Matrix P1 = strassenRec(A + D, E + H);
    Matrix P2 = strassenRec(D, G - E);
    Matrix P3 = strassenRec(A + B, H);
    Matrix P4 = strassenRec(B - D, G + H);
    Matrix P5 = strassenRec(A, F - H);
    Matrix P6 = strassenRec(C + D, E);
    Matrix P7 = strassenRec(A - C, E + F);

    Matrix M11 = P1 + P2 - P3 + P4;
    Matrix M12 = P5 + P3;
    Matrix M21 = P6 + P2;
    Matrix M22 = P5 + P1 - P6 - P7;

    Matrix M(n, n);
    M.block(0, 0, half, half) = M11;
    M.block(0, half, half, half) = M12;
    M.block(half, 0, half, half) = M21;
    M.block(half, half, half, half) = M22;

    return M;
}

Matrix strassenMult(Matrix &mat1, Matrix &mat2, int n) {
    int m = nextPower(n);
    Matrix newMat1 = Matrix::Zero(m, m);
    Matrix newMat2 = Matrix::Zero(m, m);

    newMat1.block(0, 0, n, n) = mat1;
    newMat2.block(0, 0, n, n) = mat2;

    Matrix resMatrix = strassenRec(newMat1, newMat2);
    return resMatrix.block(0, 0, n, n);
}