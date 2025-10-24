#include <tuple>
#include <random>
#include <Eigen/Dense>
//
// Created by Mateusz on 24.10.2025.
//
using namespace std;
using Matrix = Eigen::MatrixXd;

#ifndef UNTITLED_STRASSEN_H
#define UNTITLED_STRASSEN_H

tuple<Matrix, Matrix, Matrix, Matrix> split(const Matrix& M, int n);
int nextPower(int n);
Matrix strassenRec(const Matrix &mat1, const Matrix &mat2);
Matrix strassenMult(Matrix &mat1, Matrix &mat2, int n);

#endif //UNTITLED_STRASSEN_H