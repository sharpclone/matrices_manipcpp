#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
#define N 100

double det(double a[][N], int n) {
  double det = 1;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (abs(a[j][i]) > abs(a[k][i])) {
        k = j;
      }
    }
    if (abs(a[k][i]) < 1e-9) {
      return 0;
    }
    if (i != k) {
      swap(a[i], a[k]);
      det = -det;
    }
    det *= a[i][i];
    for (int j = i + 1; j < n; j++) {
      a[i][j] /= a[i][i];
    }
    for (int j = 0; j < n; j++) {
      if (j != i && abs(a[j][i]) > 1e-9) {
        for (int k = i + 1; k < n; k++) {
          a[j][k] -= a[i][k] * a[j][i];
        }
      }
    }
  }
  return det;
}

int main() {
  int n;
  cout << "n=";
  cin >> n;
  double A[N][N];
  for (int i = 0; i < n; i++) {
    for (int ii = 0; ii < n; ii++) {
      printf("A[%d][%d]=", i + 1, ii + 1);
      cin >> A[i][ii];
    }
  }
  printf("Matricea A: \n");
  for (int i = 0; i < n; i++) {
    for (int ii = 0; ii < n; ii++) {
      printf("%f ", A[i][ii]);
    }
    cout << "\n";
  }

  // max coloana inainte de modificarea lui A cu determinant
  map<double, vector<int>> max_cols;
  double sum = -2;
  double curr_max = -1;
  int j = 0;

  for (int i = 0; i < n; i++) {
    sum = 0;

    // calculez suma
    for (j = 0; j < n; j++) {
      sum += A[j][i];
    }

    if (sum > curr_max) {
      max_cols.clear();
      curr_max = sum;
      max_cols[curr_max].push_back(i);
    }
    if (sum == curr_max) {
      max_cols[curr_max].push_back(i);
    }
  }

  double deter = det(A, n);
  cout << "determinant A prin recursiva: " << deter << '\n';
  cout << "determinant A prin iterativa: " << deter << '\n';

  cout << "Exista inversa \n";

  cout << "\n Suma maxima pe coloane : " << curr_max
       << " | Coloanele cu aceasta suma: ";

  int size = max_cols[curr_max].size();
  for (int i = 1; i < size; i++) {
    cout << max_cols[curr_max][i] << " ";
  }

  return 0;
}