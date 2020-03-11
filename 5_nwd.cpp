#include <iostream>
using namespace std;
int T[100005];

int nwd (int a, int b) {
    if (a<b) swap (a, b);
    if (b==0) return a;
    return nwd (b, a%b);
}

int main () {
    ios_base::sync_with_stdio(false);
    int n, i=0;
    while (cin>> n) {
        T[i]= n;
        i++;
    }
    for (int j=0; j<i; j++) {
        T[j+1]= nwd (T[j], T[j+1]);
    }
    if (T[i-1]==0) cout<< "BRAK";
    else cout<< T[i-1];
}
