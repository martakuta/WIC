#include <iostream>
using namespace std;
bool T[16000000];
int ilosc=0;
void sito(int n)
{
    long long i=2;
    while (ilosc<n) {
        if(T[i] == 0)
            ilosc++;
            for (int j = i+i ; j<16000000; j+=i) T[j] = 1;
            i++;
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>> n;
    //sito Eratostenesa
    sito (n);
    int licznik=0, i=2;
    while (licznik<n) {
        if (T[i] == 0) {
            cout<< i << "\n";
            licznik++;
        }
        i++;
    }
}
