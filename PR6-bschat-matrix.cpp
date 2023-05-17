#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<double>> read_matrix(string filename) {
    ifstream fin(filename);
    int n, m;
    fin >> n >> m;
    vector<vector<double>> matrix(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> matrix[i][j];
        }
    }
    return matrix;
}

vector<vector<double>> matrix_inverse(vector<vector<double>>& matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        inverse[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        double factor = matrix[i][i];
        if (factor == 0) {
            return vector<vector<double>>();
        }
        for (int j = i; j < n; j++) {
            matrix[i][j] /= factor;
            inverse[i][j] /= factor;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                double factor2 = matrix[j][i];
                for (int k = 0; k < n; k++) {
                    matrix[j][k] -= matrix[i][k] * factor2;
                    inverse[j][k] -= inverse[i][k] * factor2;
                }
            }
        }
    }
    return inverse;
}


vector<vector<double>> matrix_multiply(vector<vector<double>>& matrix1, vector<vector<double>>& matrix2) {
    int n = matrix1.size();
    int m = matrix2[0].size();
    int p = matrix2.size();
    vector<vector<double>> result(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double sum = 0;
            for (int k = 0; k < p; k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int main() {
    string filename = "/home/mihu/Documents/Workspace/Hw/matrice/PR5.in";
    vector<vector<double>> matrix = read_matrix(filename);
    vector<vector<double>> inverse = matrix_inverse(matrix);
    cout << "Inverse:" << endl;
    for (int i = 0; i < inverse.size(); i++) {
        for (int j = 0; j < inverse[0].size(); j++) {
            cout << inverse[i][j] << " ";
        }
        cout << endl;
    }
    vector<vector<double>> product = matrix_multiply(matrix, inverse);
    cout << "Product:" << endl;
    for (int i = 0; i < product.size(); i++) {
        for (int j = 0; j < product[0].size(); j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
