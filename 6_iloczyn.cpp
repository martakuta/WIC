#include <iostream>
using namespace std;
long long T[50];
void fib () {
        T[0]=1;
        T[1]=1;
        for (int i=2; i<46; i++) {
            T[i]= T[i-1] + T[i-2];
        }
}
int main () {
    ios_base::sync_with_stdio(false);
    int t, n;
    cin>> t;
    fib();
    int k=0;
    while (k<t) {
        cin>> n;
        if (n==0) {
            cout<< "TAK\n";
            k++;
            continue;
        }
        for (int i=1; i<46; i++) {
            for (int j=1; j<46; j++) {
                if (T[i]*T[j]==n) {
                    cout<< "TAK\n";
                    i=46;
                    j=46;
                }
            }
            if (i==45) cout<< "NIE\n";
        }
        k++;
    }

    return 0;
}
