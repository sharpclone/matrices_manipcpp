#include <bits/stdc++.h>
using namespace std;

// CONSTANTE
#define N 100

/*Template se foloseste ca o functie sa poate lua orice tip de date*/


/*Add matrices*/
template <class T> void addMatrices(T A[][N], int B[][N], int C[][N], int len) {
  for (int h = 0; h < len; h++) {
    for (int w = 0; w < len; w++) {
      C[h][w] = A[h][w] + B[h][w];
    }
  }
}


/*copy array to another one*/
template <class T> void arrayCopy(T A[][N], T B[][N], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      B[i][j] = A[i][j];
    }
  }
}


/*print matrix*/
template <class T> void mprint(T A[][N], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << A[i][j] << " ";
    }
    cout << "\n";
  }
}


/*Multiply Matrices*/
template <class T>
void matmultiply(T A[][N], T B[][N], T C[][N], int R1, int C1, int R2) {
  for (int i = 0; i < R1; i++) {
    for (int j = 0; j < C1; j++) {
      C[i][j] = 0;
      for (int k = 0; k < R2; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}


/*LEGACY inseamna ca leam folosit la tema pe acasa si daca le modific va trebui sami fac tema din nou*/


/*[LEGACY] SUPPORT FUNCTION FOR PIVOT ONLY */
template <class T> void gaussEs(T A[][N], int n, int m) {
  // metoda Pivot
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = m; k >= i; k--) {
        A[j][k] = A[i][i] * A[j][k] - A[i][k] * A[j][i];
      }
    }
  }
}


/*[LEGACY]Functie de facut schimbat matricea daca primul element e 0,sau toata
 * coloana sau cu totul*/
template <class T> int modifyMatrixForEchelon(T mat[][N], int n, int m) {
  int count = 0;
  for (int i = 0; i < n; i++) { // verifica daca toata coloana e zero
    if (mat[i][0] != 0) {
      break;
    }
    count++;
  }
  // USELESS CODE DEOARECE NU PUTEM SCHIMBA SI COLOANA :(
  /*if (count == n) { // inseamna ca toata prima coloana e zero,
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (mat[i][j] != 0) {
          for (int l = 0; l < n; l++) {
            swap(mat[l][j], mat[l][0]);
          }
          i = n + 1; // TO break the outer loop
          break;
        }
      }
    }
    if (mat[0][0] == 0) {
      modifyMatrixForEchelon(mat, n, m);
    }
    // cout << "test\n";
  }*/
  if (count == n) {
    // Nu stiu ce sa fac daca toata coloana e zero
    cout << "Nu am putut schimba matricea \n";
    return -1;
  } else {
    for (int i = 0; i < n; i++) { // schimba liniile cu locul
      if (mat[i][0] != 0) {
        swap(mat[0], mat[i]);
        break;
      }
    }
  }
  return 0;
}


/*[LEGACY] FOLOSESTE esalonare2() aceasta nu merge daca toata prima coloana e zero*/
/*Functie de esalonare prin mai multe metode, default pivot + no
 * aproximation to 0 for doubles*/
template <class T>
int esalonare(T mat[][N], int n, int m, string metoda = "pivot",
              bool NeedApprx = 0, const float TOLERANCE = 1e-6) {
  if (mat[0][0] == 0) { // daca primul element e zero
    int result = modifyMatrixForEchelon(mat, n, m);
    if (result) {
      return result;
    }
  }

  if (metoda == "gauss") {
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        float factorul = mat[j][i] / mat[i][i];
        for (int k = 0; k < m; k++) {
          mat[j][k] = mat[j][k] - factorul * mat[i][k];
        }
      }
    }
  } else if (metoda == "pivot") {
    // metoda Pivot
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = m; k >= i; k--) {
          mat[j][k] = mat[i][i] * mat[j][k] - mat[i][k] * mat[j][i];
        }
      }
    }
  } else {
    cout << "Metoda ne-implementata de esalonare! Nu fac nimic";
    return -1;
  }

  if (NeedApprx) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (abs(mat[i][j]) < TOLERANCE) { // check if entry is very small
          mat[i][j] = 0.0;                // set to exactly zero
        }
      }
    }
  }
}


/*Metoda de calcul determinant iterativa Gauss, reliable ? , takes only
 * number of rows*/
template <class T> double myDet(T a[][N], int n) {
  double det = 1;
  int count = 0;
  if (a[0][0] == 0) {             // daca primul element e zero
    for (int i = 0; i < n; i++) { // verifica daca toata coloana e zero
      if (a[0][i] != 0) {
        break;
      }
      count++;
    }
    if (count == n ) { /*daca for-ul a trecut inseamna ca toata coloana zero si determinantul e zero*/
      return 0;
    } 
    else {
      for (int i = 0; i < n;i++) { // daca nu schimba liniile, semnul det se inverseaza
        if (a[i][0] != 0) {
          swap(a[0], a[i]);
          det = -det;
        }
      }
    }
  }
  esalonare2(a, n, n, "gauss", 1); // esalonare prin gauss
  for (int i = 0; i < n; i++) {
    det *= a[i][i]; // determinantul e produsul liniei
  }
  return det;
}


/*Metoda de calcul determinant de pe internet, reliable */
template <class T> double det(T a[][N], int n) {
  double det = 1;
  for (int i = 0; i < n; i++) { // Itereaza printre linii
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (abs(a[j][i]) > abs(a[k][i])) { // Cauta lniia cu cea mai mare valoarea
        k = j;
      }
    }
    if (abs(a[k][i]) < 1e-9) { // Daca toate is aprooape de zero return 0
      return 0;
    }

    if (i != k) { // Da swap la rows daca cea mai mare valoare nu e in prima
                  // linie adica i
      swap(a[i], a[k]);
      det = -det;
    }

    det *= a[i][i]; // Scoate nr din a[i][i] in fata
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


/*Functie folosita de alte functii, verifica daca toate elementele de sub un element sunt 0*/
template <class T>
bool ifBelowZero(T mat[][N], int row, int col, int n, int m) {
  for (int i = row; i < n; i++) {
    if (mat[i][col] != 0) {
      return false;
    }
  }
  return true;
}


/*Functie de esalonare print mai multe metode
Argumente: (in ordine) 
- Matricea [orice tip de date]
- Numarul de linii [int]
- Numarul de Coloane [int]
- Metoda de esalonare [string] [defaul="gauss"]
- Daca sa arate ce metoda de esalonare sa foloseasca [bool] [default=1]
- Daca trebuie sa aproximeze numerele foarte mici la 0 [bool] [default=0]
- Toleranta mentru numerele foarte mici [double] [default=1e-6]
*/
template <class T>
int esalonare2(T mat[][N], int n, int m, string metoda = "gauss",
               bool enableMessage = 1, bool NeedApprx = 0,
               const float TOLERANCE = 1e-6) {
  if (enableMessage) {
    cout << "/*Esalonare cu metoda: " << metoda << " */\n ";
  }
  int o = 0;
  int col = 0;
check:
  if (mat[o][col] == 0) {
    if (ifBelowZero(mat, 0, 0, n, m)) {
      o++;
      col++;
      goto check;
    } else {
      for (int i = o; i < n; i++) { // schimba liniile cu locul
        if (mat[i][col] != 0) {
          swap(mat[o], mat[i]);
          break;
        }
      }
    }
  }
  /*METODA GAUSS */
  if (metoda == "gauss") {
    for (; o < n - 1; o++) {
      for (int j = o + 1; j < n; j++) {
        float factorul = mat[j][o] / mat[o][o];
        for (int k = 0; k < m; k++) {
          mat[j][k] = mat[j][k] - factorul * mat[o][k];
        }
      }
    }
  } else
    /*METODA PIVOT*/
    if (metoda == "pivot") {
      for (; o < n; o++) {
        for (int j = o + 1; j < n; j++) {
          for (int k = m; k >= o; k--) {
            mat[j][k] = mat[o][o] * mat[j][k] - mat[o][k] * mat[j][o];
          }
        }
      }
    }
    /*DACA NU E SPECIFICATA O METODA PREZENTA*/
    else {
      cout << "Metoda invalabila!Verifica ce ai scris, metode posibile (case "
              "sensitive) \n: \"gauss\" \"pivot\" ";
      return -1;
    }

  if (NeedApprx) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n + 1; j++) {
        if (abs(mat[i][j]) < TOLERANCE) { // check if entry is very small
          mat[i][j] = 0.0;                // set to exactly zero
        }
      }
    }
  }
}

