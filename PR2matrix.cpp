#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cout << "Dati n, m, k: ";
    cin >> n >> m >> k;
    cout << "Dati Matricea A si B: ";
    vector<vector<int>> A(n, vector<int>(m));
    vector<vector<int>> B(m, vector<int>(k));

    // citire matrici
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    // afisare matrici
    cout << "Matricea A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Matricea B:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    // inmultire matrici
    vector<vector<int>> C(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < m; l++) {
                C[i][j] += A[i][l] * B[l][j];
            }
        }
    }

    // afisare produs matricial
    cout << "Produsul matricial A*B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    // inmultire B cu A (daca este posibil)
    if (m == n) {
        vector<vector<int>> D(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < k; l++) {
                    D[i][j] += B[i][l] * A[l][j];
                }
            }
        }

        // afisare produs matricial
        cout << "Produsul matricial B*A:\n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << D[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Nu se poate efectua inmultirea B*A\n";
    }

    return 0;
}
