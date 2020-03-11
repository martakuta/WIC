#include <iostream>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    int n, k, ilosc=0;
    pair <int, int> ratownik;
    pair <int, int> dziecko;
    cin>> n >> k >>  ratownik.first >> ratownik.second;
    k = k*k;
     for (int i=0; i<n; i++) {
        cin>> dziecko.first >> dziecko.second;
        int odleglosc, x, y;
        x = ratownik.first - dziecko.first;
        x = x*x;
        y= ratownik.second - dziecko.second;
        y = y*y;
        odleglosc = x + y;
        if (odleglosc > k) ilosc++;
     }
    cout<< ilosc;
    return 0;
}
