#include <tuple>
#include <random>
#include <cmath>
#include <algorithm>
#include <Eigen/Dense>
//
// Created by Mateusz on 24.10.2025.
//
using namespace std;
using Matrix = Eigen::MatrixXd;
#ifndef UNTITLED_AI_METHOD_H
#define UNTITLED_AI_METHOD_H

Matrix ai_method(const Matrix &mat1, const Matrix &mat2);
Matrix ai_rec(const Matrix &mat1, const Matrix &mat2);
int nextPower5(int n);
#endif //UNTITLED_AI_METHOD_H