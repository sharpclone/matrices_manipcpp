#include "header.hpp"
#include <math.h>
#include <string>
#include <fstream>
using namespace std;
#define N 100

int main() {
  ifstream fin("PR5.in");
  double A[N][N];
  double inv[N][N];
  double tempArray[N][N];
  double detTempArray[N][N];
  int n;

  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }
  mprint(A, n, n, "A");
  arrayCopy(A, detTempArray, n, n);
  double detA = det(detTempArray, n);
  cout << "detA = " << detA << endl;
  if (detA) {
    cout << "A^-1 exista \n";
    double detMinor;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        removeRowCol(A, tempArray, n, n, i, j);
        cout << "A" << i+1 << j+1 <<" ";
//        mprint(tempArray, n-1, n-1,"Complement: ",2,1);
        detMinor = det(tempArray, n - 1);

        cout << "complement = (-1)^(" <<i+1<<"+"<<j+1<<") * " <<setw(10)<< detMinor <<  "\t = " << setw(10) <<  pow(-1, i + j) * detMinor << endl;
        inv[j][i] = pow(-1, i + j) * detMinor / detA;
        // cout<<setw(10)<<inv[j][i]<<endl;
      }
    }
    mprint(inv, n, n, "A^-1", 2, 1);
    double result[N][N];
  arrayCopy(A, tempArray, n, n);
  arrayCopy(inv, detTempArray, n, n);

  multiplyMatrices(tempArray, detTempArray, result, n, n, n);
  mprint(result, n, n, "A * A-1 (pentru verificare)",2,1,1e-5);

  } else {
    cout << "detA = 0, nu exista matrice inversa";
  }
}
