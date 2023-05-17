#include<bits/stdc++.h>
#include"header.hpp"

int main(){
    int n, m;
    ifstream fin("/home/mihu/Documents/Workspace/Hw/matrice/PR9.in");
    fin >> m >> n;
    int A[N][N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fin >> A[i][j];
        }
    }
    cout << myDet(A, n);
    esalonare2(A, n, m,"pivot");
    mprint(A,n,m,"A");

}
