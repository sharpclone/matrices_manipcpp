#include "header.hpp"
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  double A[N][N], B[N][N];
  int n;
  ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/PR_9V2.in");
  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> B[i][j];
    }
  }

  mprint(A, n, n, "A");
  mprint(B, n, n, "B");

  double detA = det(A, n);
  cout << "\n\ndetA = " << detA << "\n\n";
  if (detA) {
    double inv[N][N];
    inverseMatrix(A, inv, n);
    mprint(inv, n, n, "inversa a A");
    cout << endl << endl;
    double X[N][N];
    cout << "Rezolvarea ecuatiei AX = B: \n";
    multiplyMatrices(inv, B, X, n, n, n);

    mprint(X, n, n, "Solutie X = A-1 * B");

    cout << "\n\nRezolvarea ecuatiei XA = B: \n";
    multiplyMatrices(B, inv, X, n, n, n);

    mprint(X, n, n, "Solutie X = B * A-1");
  } else {
    vector<double> sums;
    sums.push_back(0);
    double currSum = 0;
    for (int i = 0; i < n; i++) {
      currSum = 0;
      for (int j = 0; j < n; j++) {
        currSum += B[i][j];
      }
        if (currSum > sums[0]) {
          sums.clear();
          sums[0] = currSum;
        }
        if (currSum == sums[0]) {
          sums.push_back(i);
        }
    }
    cout << "suma maxima pe linii este " << sums[0] << " si liniile cu aceasta suma sunt: \n";
    for(int i = 1; i < sums.size();i++){
        cout << sums[i] << " ";
    }
  }

  return 0;
}