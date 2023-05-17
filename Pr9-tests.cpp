#include <iostream>
#include <fstream>
#include "header.hpp"
#include <stdio.h>
#include<iomanip>
using namespace std;

int main() {
    int n, m;
    ifstream fin("PR9.in");
    fin >> m >> n;
    int A[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> A[i][j];
        }
    }

    if (n == m) {
        cout << "Matricea este patratica\n";
        cout << "detA = " << det(A, n) << endl;
        return 0;
    }

    int rang = min(n, m);
    int max_rang = max(n, m);
    int tempArr[N][N];
    double determinant;
    while (rang > 0) {
bool allZeroDeterminants = true;

for (int i = 0; i <= max_rang - rang; i++) {
    for (int j = 0; j <= max_rang - rang; j++) {
        // Check if submatrix dimensions are within bounds
        if ((i + rang) <= n && (j + rang) <= m) {
            // Copy submatrix into tempArr
            intervalCopy(A, tempArr, i, i + rang, j, j + rang);
            // Calculate determinant
            printf("Submatricea de la i = %d pana la i = %d, si j = %d pana la j = %d, rangul current = %d:\n", i, i + rang - 1, j, j + rang - 1, rang);
            determinant = det(tempArr, rang);
            mprint(tempArr, rang, rang);
            cout << "determinantul = " << fixed << setprecision(2) << determinant << endl;
            if (determinant != 0) {
                allZeroDeterminants = false;
                break;
            }
        }
    }

    if (!allZeroDeterminants) {
        break;
    }
}

rang--;
    }
    cout << "Ordinul matricei : " << rang;

    return 0;
}
