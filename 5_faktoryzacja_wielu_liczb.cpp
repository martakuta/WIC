#include <iostream>
using namespace std;
int T[1000005];

void sito() {
    for (int i=2; i<1000005; i++) {
        if(T[i] == 0) {
            T[i]=i;
            for (int j = i+i ; j<1000005; j+=i) {
                if (T[j]==0) T[j] = i;
            }
        }
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    sito ();
    int t, a;
    cin>> t;
    for (int i=0; i<t; i++) {
        cin>> a;
        while (a > 1) {
            cout << T[a] << " ";
            a /= T[a];
        }
        cout<< "\n";
    }

}
