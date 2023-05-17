#include "header.hpp"
#include <fstream>
using namespace std;

int main() {
  double A[N][N];
  ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/PR8.in");
  int n;
  fin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> A[i][j];
    }
  }
  mprint(A, n, n,"A");
  double test[N][N];
  double determinant = det(A, n);
  double inv[N][N];
  if (determinant) {
    cout << "detA = " << determinant << endl;
    inverseMatrix(A, inv, n);
    mprint(inv, n, n, "inversa");
    multiplyMatrices(A, inv, test, n, n, n);
    // mprint(test, n, n, "A * A*-1 [profilaxie]");
    double C[N][N];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        fin >> C[i][j];
      }
    }
    mprint(C, n, n,"C");
    double X[N][N];
    double rez[N][N];
    
    cout << "\nRezolv A * X = C, X = A-1 * C\n";
    multiplyMatrices(inv, C, rez,n,n,n);
    mprint(rez, n, n,"X = A-1 * C");
    
    cout << "\nRezolv X * A = C, X = C * A-1\n";
    multiplyMatrices(C, inv, rez,n,n,n);
    mprint(rez, n, n,"X = C * A-1");


  } else {
    cout << "detA = 0, nu exista A-1,CITIM VECTORUL B.... \n";

    double B[N];
    for (int i = 0; i < n; i++) {
      fin >> B[i];
    }

    double A_B[N][N];
    arrayCopy(A, A_B, n, n);
    for (int i = 0; i < n; i++) {
      A_B[i][n] = B[i];
    }

    mprint(A_B, n, n + 1, "(A|B)");
    esalonare2(A_B, n, n + 1, "pivot");
    mprint(A_B, n, n + 1, "(A|B) zerografiata");
    bool isSystemIncompatible = false;
    int leadingOnes = 0;

    for (int i = 0; i < n; i++) {
      bool allZeros = true;
      for (int j = 0; j < n; j++) {
        if (A_B[i][j] != 0) {
          allZeros = false;
          break;
        }
      }

      if (allZeros && A_B[i][n] != 0) {
        isSystemIncompatible = true;
        break;
      }

      if (!allZeros) {
        leadingOnes++;
      }
    }

    if (isSystemIncompatible) {
      cout << "Sistemul este  compatibil nedeterminat" << endl;
    } else if (leadingOnes < n) {
      cout << "Sistemul estte incompatibil" << endl;
    } else {
      cout << "System compatibil cu o singura solutie" << endl;
    }
  }
}