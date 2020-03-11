#include<iostream>
#include<algorithm>
using namespace std;
int T[1000000];
int main()
{
    int n;
    cin>> n;
    for (int i=0; i<n; i++) {
        cin>> T[i];
    }
    sort(T, T+n);
    for (int i=0; i<n; i++) cout<< T[i] <<" ";
    return 0;
}
