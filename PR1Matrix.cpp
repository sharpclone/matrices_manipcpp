#include <bits/stdc++.h>
#include "header.hpp"
using namespace std;

int n, m, i, j, x, y, p, neg;
int A[20][20], B[100][100], C[20][20], D[20][20], P[20][20], S[20];
pair<int, int> R[20];

int main() {
  cout << "n=";
  cin >> n;
  cout << "m=";
  cin >> m;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << "A[" << i << "][" << j << "]=";
      cin >> A[i][j];
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << "B[" << i << "][" << j << "]=";
      cin >> B[i][j];
    }
  }
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      C[i][j] = A[i][j] + B[i][j];
      D[i][j] = A[i][j] - B[i][j];
      S[i] += C[i][j];
    }
  }
  
  cout << "Matricea A:\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << A[i][j] << setw(10);
    }
    cout << "\n";
  }
  
  cout << "Matricea B:\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << B[i][j] << setw(10);
    }
    cout << "\n";
  }
  
  cout << "Matricea C:\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << C[i][j] << setw(10);
    }
    cout << "\n";
  }
  
  cout << "Matricea D:\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << D[i][j] << setw(10);
    }
    cout << "\n";
  }
  
  cout << "x=";
  cin >> x;
  cout << "y=";
  cin >> y;
  
  for (i = 0; i < n; i++) {
    R[i].first = D[i][0];
    R[i].second = R[i].first;
    for (j = 0; j < m; j++) {
      P[i][j] = x * A[i][j] + y * B[i][j];
      if (P[i][j] > 0)
        p++;
      else if (P[i][j] < 0)
        neg++;
      R[i].first = max(R[i].first, D[i][j]);
      R[i].second = min(R[i].second, D[i][j]);
    }
  }
  
 

  cout << "Matricea P:\n";
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << P[i][j] << setw(10);
    }
    cout << "\n";
  }
  for (i = 0; i < n; i++) {
    cout << "Suma elementelor in linia " << i << " a matricii C este " << S[i]
         << "\n";
    cout << "Elementul maxim din linia " << i << " a matricii D este "
         << R[i].first << "\n";
    cout << "Elementul minim din linia " << i << " a matricii D este "
         << R[i].second << "\n";
  }
  cout << "In matricea P sunt " << p << " numere pozitive \n";
  cout << "In matricea P sunt " << neg << " numere negative\n";

  cout << "Matricea B la o forma esalon prin Guass: \n";
  gaussEs(B, n, m);

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cout << setw(10) << B[i][j] << setw(10);
    }
    cout << "\n";
  }
  return 0;
}
