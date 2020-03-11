#include <iostream>
using namespace std;
int T[1000111];

int main () {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin>> n >> k;
    for (int i=0; i<n; i++) {
        cin>> T[i];
    }
    int mini= n+1, suma=0, p=0;
    bool czyok=0;
    for (int r=0; r<n; r++) {
        suma += T[r];
        if (suma==k) {
            czyok=1;
            while (suma >= k) {
                if (r-p+1 < mini) mini = r-p+1;
                suma -= T[p];
                p++;
            }
        }
    }
    int zjedz= mini- k;
    if (!czyok)
        cout<< "NIE";
    else
        cout<< zjedz;
    return 0;
}
