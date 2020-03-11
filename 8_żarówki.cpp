#include <iostream>
using namespace std;

const int M= 1024*1024;
bool D[2*1024*1024];

int sum (int poz) {
    poz += M-1;
    int wynik = D[poz];
    while (poz > 1) {
        poz /= 2;
        wynik ^= D[poz];
    }
    return wynik;
}

void add ( int p, int k) {
    p += M-1;
    k += M-1;
    D[p] ^= 1;
    if (p != k) D[k] ^= 1;
    while (p/2 != k/2) {
        if (p%2 == 0) {
            D[p+1] ^= 1;
        }
        if (k%2 != 0) {
            D[k-1] ^= 1;
        }
        p /= 2;
        k /= 2;
    }
}

void zeruj (int poz) {
    while (poz > 1) {
        poz /= 2;
        D[poz] = 0;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    string pyt, lampa;
    cin>> n >> m >> lampa;
    for (int i=0; i<=n; i++) {
        int pole=M+i;
        if (lampa[i] == 'x') {
            D[pole] = 0;
        }
        else if (lampa[i] == 'o') {
            D[pole] = 1;
        }
    }
    for (int i=0; i<m; i++) {
        cin>> pyt;
        if (pyt == "Q") {
            cin>> a;
            int x= sum(a);
            if (x == 0) cout<< "OFF\n";
            else if (x != 0) cout<< "ON\n";
        }
        else if (pyt == "S") {
            cin>> b >> c;
            add(b, c);
        }
    }
    return 0;
}
