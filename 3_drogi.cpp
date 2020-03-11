#include <iostream>
using namespace std;
int T[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    int n, a;
    cin>> n;
    for (int i=0; i<n+1; i++) {
        T[0][i]=0;
        T[i][0]=0;
    }
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            cin>> a;
            if (a==1) T[i][j]=0;
            else T[i][j]=-1;
        }
    }
    T[1][1]=1;
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<n+1; j++) {
            if (T[i][j]==-1) T[i][j]= (T[i-1][j] + T[i][j-1])%1000000;
        }
    }
    cout<< T[n][n];
}
