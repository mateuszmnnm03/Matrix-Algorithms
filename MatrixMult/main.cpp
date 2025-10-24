#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <Eigen/Dense>
#include <chrono>

#include "strassen.h"

using namespace std;

using Matrix = Eigen::MatrixXd;

Matrix generateMatrix(int n) {
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister generator

    uniform_real_distribution<double> dist(1e-8, 1.0);
    Matrix mat(n,n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat(i, j) = dist(gen);
        }
    }

    return mat;
}

Matrix bruteForceMult(Matrix &mat1, Matrix &mat2, int n) {
    Matrix mat(n,n);
    for (int i = 0; i < n; i++) {
        for  (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                mat(i, j) += mat1(i, k) * mat2(k, j);
            }
        }
    }
    return mat;
}


int main() {
    vector<int> Nsizes;
    vector<double> strassen_times;
    vector<double> bruteforce_times;
    const int REPEATS = 5;

    for (int N = 64; N <= 1024; N *= 2)
    {
        Nsizes.push_back(N);
        long long total_strassen = 0;
        long long total_brute_force = 0;

        for (int i = 0; i < REPEATS; i++)
        {

            Matrix A = generateMatrix(N);
            Matrix B = generateMatrix(N);

            auto start = chrono::high_resolution_clock::now();
            strassenMult(A, B, N);
            auto end = chrono::high_resolution_clock::now();
            total_strassen += chrono::duration_cast<chrono::microseconds>(end - start).count();

            auto start_brute_force = chrono::high_resolution_clock::now();
            bruteForceMult(A, B, N);
            auto end_brute_force = chrono::high_resolution_clock::now();
            total_brute_force += chrono::duration_cast<chrono::microseconds>(end_brute_force-start_brute_force).count();
        }

        strassen_times.push_back(total_strassen / REPEATS);
        bruteforce_times.push_back(total_brute_force / REPEATS);
    }

    // --- WYŚWIETLANIE WYNIKÓW W FORMIE TABELI ---

    // Ustawienie formatowania wyjścia
    cout << fixed << setprecision(2); // Stały format z 2 miejscami po przecinku

    cout << "\n------------------------------------------------\n";
    cout << "| N   | Strassen (us) | Brute Force (us) |\n";
    cout << "------------------------------------------------\n";

    for (size_t i = 0; i < Nsizes.size(); ++i) {
        cout << "| " << setw(3) << Nsizes[i]
             << " | " << setw(13) << strassen_times[i]
             << " | " << setw(16) << bruteforce_times[i] << " |\n";
    }

    cout << "------------------------------------------------\n";

    return 0;
}