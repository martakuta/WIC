#include <iostream>
using namespace std;

const int M= 1024*512;
int D[1024*1024];

void add (int poz, int war) {
    //cout<< poz <<" "<<war <<"\n";
    poz += M-1;
    D[poz] = war;
    while (poz > 1) {
        poz /= 2;
        D[poz] = D[2*poz] ^ D[2*poz+1];
    }
}

int ksor ( int p, int k) {
    p += M-1;
    k += M-1;
    int  wynik= D[p];
    if (p != k) wynik ^= D[k];
    while (p/2 != k/2) {
        if (p%2 == 0) wynik ^= D[p+1];
        if (k%2 != 0) wynik ^= D[k-1];
        p /= 2;
        k /= 2;
    }
    return wynik;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    int n, q, a, b;
    string pyt;
    cin>> n >> q;
    for (int i=M; i<M+n; i++) {
        cin>> D[i];
    }
    //buduje drzewo nad danym ciagiem
    for (int i=M-1; i>0; i--) {
        D[i] = D[2*i] ^ D[2*i+1];
    }
    /*for (int i=0; i<2*M; i++) {
        if (D[i] != 0) cout<< i << "=" << D[i] << " ";
    }*/
    for (int i=0; i<q; i++) {
        cin>> pyt >> a >> b;
        if (pyt == "czytaj") {
            cout<< ksor (a, b) << "\n";
        }
        else if (pyt == "zamien") {
            int pom= D[a+M-1];
            add (a, D[b+M-1]);
            /*for (int j=1; j<2*n; j++) cout<< D[j] << " ";
            cout<< "\n";*/
            add (b, pom);
            /*for (int j=1; j<2*n; j++) cout<< D[j] << " ";
            cout<< "\n";*/
        }
    }
    //for (int i=1; i<2*n; i++) cout<< D[i] << " ";
    return 0;
}
