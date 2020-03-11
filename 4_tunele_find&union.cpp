#include <iostream>
using namespace std;
pair <int, int> T[200005];
int rep [1000000]; //reprezentanci miast
int fin (int v) {
    if (rep[v]==v) return v;
    else return rep[v]=fin(rep[v]);
}
int onion (int a, int b) {
    rep[fin(b)]=fin(a);
}
int main () {
    ios_base::sync_with_stdio(false);
    int n, m, k, dni=-1;
    cin>> n >> m >> k;
    int ilosc=n;
    for (int i=1; i<=m; i++) {
        cin>> T[i].first >> T[i].second;
    }
    for (int i=1; i<=n; i++) rep[i]=i;
    for (int i=m; i>0; i--) {
        if (fin(T[i].first)!=fin(T[i].second)) {
            onion(T[i].first, T[i].second);
            ilosc--;
            if (ilosc==k-1) {
                cout<< i+1;
                return 0;
            }
        }
    }
    return 0;
}
