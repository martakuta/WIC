#include <iostream>
#include <vector>
using namespace std;
bool T[1000111];
long long pierwsze;
vector <long long> rozklad;
void sito(long long n) {
    T[0]=1;
    T[1]=1;
    for (long long i=2; i*i<=n; i++) {
        if(T[i] == 0) {
            for (long long j = i+i ; j*j<=n; j+=i) {
                if (T[j]==0) T[j] = 1;
            }
        }
    }
}
int faktoryzacja (long long n) {
    sito (n);
    for (long long i=1; i*i<=n; i++) {
        if (T[i]==0) {
            pierwsze=i;
            while (n%pierwsze == 0) {
                rozklad.push_back(pierwsze);
                n /= pierwsze;
            }
        }
    }

    if (n!=1) rozklad.push_back(n);

}
int main () {
    ios_base::sync_with_stdio(false);
    long long n, wynik=1;
    cin>> n;
    faktoryzacja(n);
    for (int i=0; i<rozklad.size(); i++) {
        int x = rozklad[i];
        if (x==rozklad[i+1]) i++;
        wynik = wynik * x * x;
    }
    cout<< wynik;
    return 0;
}
