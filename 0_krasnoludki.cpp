#include <iostream>
using namespace std;
int main () {
    int n, a, maxi=0, mini=1000001;
    cin>> n;
    for (int i=0; i<n; i++) {
        cin>> a;
        if (a>maxi) maxi=a;
        if (a<mini) mini=a;
    }
    int roznica=maxi-mini;
    cout<< roznica;
}
