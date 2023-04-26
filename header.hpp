#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

// CONSTANTE
#define N 100

/*Template se foloseste ca o functie sa poate lua orice tip de date*/

/*Add matrices*/
template <class T>
void addMatrices(T A[][N], T B[][N], T C[][N], int n, int m) {
  for (int h = 0; h < n; h++) {
    for (int w = 0; w < m; w++) {
      C[h][w] = A[h][w] + B[h][w];
    }
  }
}

/*Substract matrices*/
template <class T>
void substractMatrices(T A[][N], T B[][N], T C[][N], int n, int m) {
  for (int h = 0; h < n; h++) {
    for (int w = 0; w < m; w++) {
      C[h][w] = A[h][w] - B[h][w];
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
template <class T>
void mprint(T A[][N], int rows, int cols, string matrixName = "none", int setPrec = 0, bool NeedApprx = 0,
               const double TOLERANCE = 1e-6) {
  if (matrixName != "none") {
    cout << "Matricea " << matrixName << ": \n";
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if(abs(A[i][j])<TOLERANCE){
        A[i][j] = 0;
      }
      if(setPrec){
      cout << setprecision(setPrec) <<A[i][j] << " ";
      } else{
        cout << A[i][j] << " ";
      }
    }
    cout << "\n";
  }
}

/*Multiply Matrices*/
template <class T>
void multiplyMatrices(T A[][N], T B[][N], T C[][N], int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
          C[i][j] = 0;
            for (int l = 0; l < m; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }
}

/*LEGACY inseamna ca leam folosit la tema pe acasa si daca le modific va trebui
 * sami fac tema din nou*/

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

/*[LEGACY] FOLOSESTE esalonare2() aceasta nu merge daca toata prima coloana e
 * zero*/
/*Functie de esalonare prin mai multe metode, default pivot + no
 * aproximation to 0 for doubles*/
template <class T>
int esalonare(T mat[][N], int n, int m, string metoda = "pivot",
              bool NeedApprx = 0, const double TOLERANCE = 1e-6) {
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

/*Functie folosita de alte functii, verifica daca toate elementele de sub un
 * element sunt 0*/
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
               const double TOLERANCE = 1e-6) {
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
          mat[i][j] = 0;                // set to exactly zero
        }
      }
    }
  }
}


/*Metoda de calcul determinant iterativa Gauss, reliable ? , takes only
 * number of rows*/
template <class T> double myDet(T a[][N], int n,bool NeedApprx = 0,
               const double TOLERANCE = 1e-6) {
  double det = 1;
  int count = 0;
  if (a[0][0] == 0) {             // daca primul element e zero
    for (int i = 0; i < n; i++) { // verifica daca toata coloana e zero
      if (a[0][i] != 0) {
        break;
      }
      count++;
    }
    if (count == n) { /*daca for-ul a trecut inseamna ca toata coloana zero si
                         determinantul e zero*/
      return 0;
    } else {
      for (int i = 0; i < n;
           i++) { // daca nu schimba liniile, semnul det se inverseaza
        if (a[i][0] != 0) {
          swap(a[0], a[i]);
          det = -det;
        }
      }
    }
  }
  esalonare2(a, n, n, "gauss", 0,1,1e-6); // esalonare prin gauss
  for (int i = 0; i < n; i++) {
    det *= a[i][i]; // determinantul e produsul liniei
  }
  if(abs(det)<TOLERANCE){
    return 0;
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
    if (abs(a[k][i]) < 1e-9 ) { // Daca toate is aprooape de zero return 0
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


/*Rezolvarea unui sistem liniar prin metoda CRAMER*/
template <class T> double solveLinearSystem(T A[][N], T B[N], T X[N], int n) {
  double tempArray[N][N];
  arrayCopy(A, tempArray, n, n);
  double detA = myDet(tempArray, n);
  int save[N];
  if (abs(detA) < 1e-6 || abs(detA) == 0) {
    cout << "Nu e posibil de rezolvat prin Kramer, detA = 0";
    return (-1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      save[j] = A[j][i];
      A[j][i] = B[j];
    }
    arrayCopy(A, tempArray, n, n);
    X[i] = myDet(tempArray, n) / detA;

    for (int j = 0; j < n; j++) {
      A[j][i] = save[j];
    }
  }
  return 0;
}

/*Rezolvarea unui sistem liniar prin chestii complicat de explicat(Gauss)*/
template <class T> bool solveLinearSystem2(T A[][N], T B[N], T X[N], int n) {
  // Gaussian elimination with partial pivoting
  for (int k = 0; k < n - 1; k++) {
    // Find pivot row
    int max_row = k;
    for (int i = k + 1; i < n; i++) {
      if (abs(A[i][k]) > abs(A[max_row][k])) {
        max_row = i;
      }
    }
    if (max_row != k) {
      // Swap rows
      for (int j = k; j < n; j++) {
        swap(A[k][j], A[max_row][j]);
      }
      swap(B[k], B[max_row]);
    }
    // Eliminate
    for (int i = k + 1; i < n; i++) {
      T factor = A[i][k] / A[k][k];
      for (int j = k + 1; j < n; j++) {
        A[i][j] -= factor * A[k][j];
      }
      B[i] -= factor * B[k];
    }
  }
  // Back substitution
  for (int i = n - 1; i >= 0; i--) {
    T sum = 0;
    for (int j = i + 1; j < n; j++) {
      sum += A[i][j] * X[j];
    }
    X[i] = (B[i] - sum) / A[i][i];
  }
  // Check for inconsistent system
  for (int i = 0; i < n; i++) {
    T sum = 0;
    for (int j = 0; j < n; j++) {
      sum += A[i][j] * X[j];
    }
    if (abs(sum - B[i]) > 1e-6) {
      return false; // inconsistent system
    }
  }
  return true; // consistent system
}

/*Functie ce da remove la o linie si coloana*/
template <class T> void removeRowCol(T A[][N], T finalArr[][N], int n, int m, int rRow, int rCol){
  int rowOffset = 0;
  int colOffset = 0;
  
  // Iterate over each element in A, except the removed row and column
  for(int i = 0; i < n; i++){
    if(i == rRow){  // Skip the removed row
      rowOffset = 1;
      continue;
    }
    
    colOffset = 0;
    for(int j = 0; j < m; j++){
      if(j == rCol){  // Skip the removed column
        colOffset = 1;
        continue;
      }
      
      // Copy the element to the new array
      finalArr[i-rowOffset][j-colOffset] = A[i][j];
    }
  }
}