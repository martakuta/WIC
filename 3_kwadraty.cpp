#include <iostream>
using namespace std;
int T[1005][1005];
int main () {
    ios_base::sync_with_stdio(false);
    int n, a, najw=0;
    cin>> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>> a;
            if (a==0) T[i][j]=-1;
            else T[i][j]=0;
        }
    }
    for (int i=0; i<=n; i++) {
        T[0][i]=0;
        T[i][0]=0;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (T[i][j]==-1) {
                int mini = min(T[i][j-1], T[i-1][j]);
                if (T[i-1][j-1]>=mini) T[i][j]=mini+1;
                else T[i][j]=mini;
                if (T[i][j]>najw) najw=T[i][j];
            }
        }
    }
    cout<< najw;
    return 0;
}
