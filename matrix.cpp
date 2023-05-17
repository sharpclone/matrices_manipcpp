
#include <fstream>
#include <iostream>
/* math.h header file is included for abs() function */
#include "header.hpp"
#include <iomanip>
#include <math.h>
using namespace std;
#define N 100
int main() {
  int n;
  ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/input.txt");
  fin >> n;

  double A[N][N];
  double B[N][N];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }
  cout << myDet(A, n);
  return 0;
}