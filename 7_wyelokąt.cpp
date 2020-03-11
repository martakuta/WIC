#include <iostream>
using namespace std;
pair <long long, long long> wierz[1000000];
int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    long long pole=0;
    cin>> n;
    for (int i=0; i<n; i++) {
        cin>> wierz[i].first >> wierz[i].second;
    }
    for (int i=n-1; i>0; i--) {
        //cout<< wierz[i].first << " " <<wierz[i].second << "\n";
        long long x1y2, x2y1;
        x1y2 = wierz[i].first * wierz[i-1].second;
        x2y1 = wierz[i-1].first * wierz[i].second;
        pole += (x1y2 - x2y1);
        //cout<< x1y2 << " " << x2y1 << " " << pole << "\n";
    }

    //cout<< wierz[0].first << " " <<wierz[0].second << "\n";
    long long x1y2, x2y1;
    x1y2 = wierz[0].first * wierz[n-1].second;
    x2y1 = wierz[n-1].first * wierz[0].second;
    pole += (x1y2 - x2y1);
    //cout<< x1y2 << " " << x2y1 << " " << pole << "\n";

    if (pole%2 == 0) {
        cout<< pole/2;
    }
    else cout<< pole/2 << ".5";
    return 0;
}
