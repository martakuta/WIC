#include <iostream>
using namespace std;
int T[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    int n, m, q;
    cin>> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>> T[i][j];
        }
    }
    for (int i=2; i<=m; i++) T[1][i] += T[1][i-1];
    for (int i=2; i<=n; i++) T[i][1] += T[i-1][1];
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=m; j++) {
            T[i][j] = T[i][j] + T[i-1][j] + T[i][j-1] - T[i-1][j-1];
        }
    }
    cin>> q;
    int a1, b1, a2, b2;
    for (int i=0; i<q; i++) {
        cin>> a1 >> b1 >> a2 >> b2;
        int suma= T[a2][b2] - T[a2][b1-1] - T[a1-1][b2] + T[a1-1][b1-1];
        cout<<suma<<"\n";
    }
}
