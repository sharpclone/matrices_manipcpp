#include "header.hpp"
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <type_traits>
#include <valarray>
#include <vector>
using namespace std;
#define N 100

int main() {
  double A[N][N];
  double B[N][N];
  double Res[N][N];
  double Res2[N][N];
  ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/P4-input.txt");

  /*Reading matrices A and B*/
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }
  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> B[i][j];
    }
  }

  /*Printez matricile*/
  mprint(A, n, n, "A");
  mprint(B, n, n, "B");

  /*Operatii cu matrici*/
  addMatrices(A, B, Res, n, n);
  mprint(Res, n, n, "rezultanta a adunarii");

  substractMatrices(A, B, Res, n, n);
  mprint(Res, n, n, "rezultanta a scaderii (A - B)");

  multiplyMatrices(A, B, Res2, n, n, n);
  mprint(Res2, n, n, "rezultanta a inmultirii");

  double tempArray[N][N];
  arrayCopy(A, tempArray, n, n);
  cout << "Determinantul A prin metoda iterativa cu Gauss: "
       << myDet(tempArray, n) << endl;
  arrayCopy(A, tempArray, n, n);
  cout << "Determinantul A prin metoda recursiva: " << det(tempArray, n)
       << endl;

  /*REZOLVAREA CU KRAMER*/
  int n1;
  fin >> n1;
  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n1; j++) {
      fin >> A[i][j];
    }
  }
  double C[N];
  for (int i = 0; i < n1; i++) {
    fin >> C[i];
  }

  double A1[N][N];
  double B1[N];
  arrayCopy(A, A1, n1, n1);
  for (int i = 0; i < n1; i++) {
    B1[i] = C[i];
  }
  /*Printarea matricilor*/
  cout << "Rezolvarea Ecuatii lineare cu Kramer: \n";
  mprint(A, n1, n1, "A");
  cout << "Coloana B: \n";
  for (int i = 0; i < n1; i++) {
    cout << C[i] << " ";
  }
  cout << endl;
  double X[N];
  solveLinearSystem(A, C, X, n1);
  cout << "Solutiile ecuatiei cu KRAMER : \n";
  for (int i = 0; i < n1; i++) {
    cout << "X" << i + 1 << " = " << X[i] << "; ";
  }
  cout << endl;
  double X1[N];
  mprint(A1, n1, n1, "A1");
  cout << "Coloana B1: \n";
  for (int i = 0; i < n1; i++) {
    cout << B1[i] << " ";
  }
  cout << "\nRezolvarea systemului prin metoda Gauss: \n";
  solveLinearSystem2(A1, B1, X1, n1);
  for (int i = 0; i < n1; i++) {
    cout << "X" << i + 1 << " = " << X1[i] << "; ";
  }
}
