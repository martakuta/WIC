#include <iostream>
using namespace std;
bool T[1000][1000];
int main () {
    ios_base::sync_with_stdio(false);
    int w, k, a, b, q; //w wierzcholki, k krawedzie, a b wierzcholki ktore laczy dana krawedz, q ilosc zapytan
    cin>> w >> k;
    for (int i=0; i<k; i++) {
        cin>> a >> b;
        T[a][b]=1;
        //T[b][a]=1;
    }
    cin>> q;
    for (int i=0; i<q; i++) {
        cin>> a >> b;
        if (T[a][b]==1 || T[b][a]==1) cout<< "TAK\n";
        else cout<< "NIE\n";
    }
    return 0;
}
