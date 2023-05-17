#include "header.hpp"
#include <fstream>
#include <iostream>
using namespace std;
#define N 100

int main() {
  ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/PR5.in");
  double A[N][N];
  double B[N];
  int n;
  /*Citire matrici*/
  //   cout << "n: ";
  fin >> n;
  //   cout << "Matricea A: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }
  //   cout << "Vectorul B: \n";
  for (int i = 0; i < n; i++) {
    fin >> B[i];
  }

  /*Afisare matrici*/
  mprint(A, n, n, "A");
  cout << "Matricea B: \n";
  for (int i = 0; i < n; i++) {
    cout << B[i] << " ";
  }
  cout << endl;

  double A_B[N][N];
  arrayCopy(A, A_B, n, n);
  for (int i = 0; i < n; i++) {
    A_B[i][n] = B[i];
  }
  mprint(A_B, n, n + 1, "(A|B)");
  esalonare2(A_B, n, n + 1, "pivot");
  mprint(A_B, n, n + 1, "(A|B) zerografiata");

  double X[N];
  solveLinearSystem2(A, B, X, n);

  cout << "Solutiile ecuatiei: \n";
  for (int i = 0; i < n; i++) {
    cout << X[i] << " ";
  }
  cout << endl;
}