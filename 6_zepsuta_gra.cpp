#include <iostream>
using namespace std;
long long T[1005][1005];
long long inf = -1000LL*1000LL*1000LL*1000LL*1000LL;

int main () {
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin>> n >> m;
    for (int i=0; i<=n; i++) T[0][i]=inf;
    for (int i=0; i<=m; i++) T[i][0]=inf;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin>> T[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i == 1 && j == 1) continue;
            long long maxi= max(T[i-1][j], T[i][j-1]);
            T[i][j] += maxi;
        }
    }
    if (T[n][m]<=0) cout << "0";
    else cout<< T[n][m];
    return 0;
}
