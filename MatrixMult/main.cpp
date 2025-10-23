#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

using Matrix = MatrixXd;

Matrix generateMatrix(int n) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister generator

    uniform_real_distribution<double> dist(1e-8, 1.0);
    Matrix mat(n,n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = dist(gen);
        }
    }

    return mat;
}

Matrix bruteForceMult(Matrix &mat1, Matrix &mat2, int n) {
    Matrix mat(n,n);
    for (int i = 0; i < n; i++) {
        for  (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mat;
}

tuple<Matrix, Matrix, Matrix, Matrix> split(const Matrix& M, int n) { // Matrix split, complexity O(n^2)
    int half = n / 2;

    Matrix A11 = M.top;
    Matrix A12(half, vector<double>(half));
    Matrix A21(half, vector<double>(half));
    Matrix A22(half, vector<double>(half));


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


Matrix strassenRec(Matrix &mat1, Matrix &mat2, int n) {
    auto [A11st, A12st, A21st, A22st] = split(mat1, n);
    auto [A11nd, A12nd, A21nd, A22nd] = split(mat1, n);


}

Matrix strassenMult(Matrix &mat1, Matrix &mat2, int n) {
    if (n <= 2) {
        return bruteForceMult(mat1, mat2, n);
    }
    int m = nextPower(n);
    Matrix newMat1(m, vector<double>(m));
    Matrix newMat2(m, vector<double>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            newMat1[i][j] = mat1[i][j];
            newMat2[i][j] = mat2[i][j];
        }
    }



}


int main() {
    int n = 17;
    auto matrix = generateMatrix(n);


}