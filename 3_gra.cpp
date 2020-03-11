#include <iostream>
using namespace std;
int T[1000*1000+9];
int main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin>> n;
    for (int i=0; i<6; i++) T[i]=-1001;
    for (int i=6; i<n+6; i++){
        cin>> T[i];
    }
    for (int i=7; i<n+6; i++) {
        int najw=-1001;
        for (int j=1; j<=6; j++)
            if (T[i-j]>najw) najw=T[i-j];
        T[i] += najw;
    }
    cout<< T[n+5];
}
