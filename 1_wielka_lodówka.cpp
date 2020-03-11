#include <iostream>
#include <algorithm>
using namespace std;
#define F first
#define S second
pair <int, bool > T[1000000];
int main () {
    ios_base::sync_with_stdio(false);
    int n;
    cin>> n;
    for (int i=0; i<2*n; i+=2) {
        cin>> T[i].F >> T[i+1].F;
        T[i].S= 0; // 0 to poczatki przedzialow, 1 to konce przedzialow
        T[i+1].S= 1;
    }
    sort (T, T+(2*n));
    int maxilosc=0, ilosc=0;
    for (int i=0; i<2*n; i++) {
        if (T[i].S == 0) ilosc++;
        else ilosc--;
        if (ilosc> maxilosc) maxilosc = ilosc;
    }
    cout<< maxilosc;
    return 0;
}
