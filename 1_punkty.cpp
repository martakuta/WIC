#include <iostream>
#include <algorithm>
using namespace std;
#define F first
#define S second
pair <int, pair<int,int> > T[100000];
int main () {
    int n;
    cin>> n;
    for (int i=0; i<n; i++) {
        cin>> T[i].F >> T[i].S.F >> T[i].S.S;
    }
    sort(T, T+n);
    for (int i=0; i<n; i++) {
        cout<< T[i].F << " " << T[i].S.F << " " << T[i].S.S << "\n";
    }
    return 0;
}
