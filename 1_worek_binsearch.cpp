#include <iostream>
#include <algorithm>
using namespace std;
long long T[1000001];
int main () {
    ios_base::sync_with_stdio(false);
    int n, zap, roznica; //n to ilosc kul, zap to ilosc zapytan, numer to numer o ktory zapytano
    long long numer;
    cin>> n;
    for (int i=0; i<n; i++) cin>> T[i];
    sort (T, T+n);
    cin>> zap;
    for (int i=0; i<zap; i++) {
        cin>> numer;
        //wyszukiwanie binarne
        //szukam pierwszego wystapienia numeru
        int p=-1, k=n;
        while (p+1<k) {
            int sr= (p+k)/2;
            if (T[sr]>=numer) k=sr;
            else p=sr;
        }
        //szukam ostatniego wystapienia numeru
        int p1=-1, k1=n;
        while (p1+1<k1) {
            int sr1= (p1+k1)/2;
            if (T[sr1]<=numer) p1=sr1;
            else k1=sr1;
        }
        roznica= p1-k+1;
        cout<< roznica << "\n";
    }
    return 0;
}
