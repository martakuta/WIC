#include <iostream>
using namespace std;
int main () {
    string napis;
    getline (cin, napis);
    int d=napis.size();
    for (int i=0; i<d; i++) {
        if ( int(napis[i]) >= 97 && int(napis[i])<=122 ) napis[i] = char( int(napis[i])-32 );
        if ( int(napis[i]) == 85 ) napis[i] = 'V';
    }
    string nowy="";
    for (int i=0; i<d; i++) {
        if ( int(napis[i]) >=65 && int(napis[i]) <=90 ) nowy += napis[i];
    }
    cout<< nowy;
}
