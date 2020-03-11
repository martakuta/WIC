#include <iostream>
#include <vector>
using namespace std;
vector <int> chem;
vector <int> inf;
vector <int> suma;
int main ()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    string a, b;
    cin>> n >> a >> m >> b;

    //chemicy

    int chemdz; //ilosc komorek ktore zajmie liczba chemikow
    if (n%9 == 0) chemdz= n/9;
    else chemdz= (n/9)+1;

    for (int j=0; j<chemdz; j++) {
        //cout<< j << ": ";
        string nowy=""; //fragment ktory bedzie w jednej komorce wektora w postaci stringa
        for (int i=j*9+1; i<=(j+1)*9 && i<=a.size(); i++) {
            nowy += a[n-i];
        }
        int komorka=0; //wartosc tora znajdzie sie w komorce
        //cout<< nowy << " ";
        for (int j=nowy.size()-1; j>=0; j--) {
            komorka *= 10;
            komorka += int(nowy[j])-48;
        }
        //cout<< komorka << "\n";
        chem.push_back(komorka); //przypisanie wartosci do wektora
    }
    //wypisywanie bignuma
    /*cout<< chem[chem.size()-1]; //wypisuje wartosc z pierwszej komorki
    for (int i=chem.size()-2; i>=0; i--) {
        int pom= chem[i], d;
        for (d=8; d>=0; d--) { //licze ile dodatkowych zer nalezy wypisac
            if (pom==0) break;
            else pom /= 10;
        }
        if (d == 8) d=7;
        for (int z=0; z<=d; z++) cout<< "0";
        cout<< chem[i];
    }
    cout<< "\n\n";*/


    //informatycy

    int infdz; //ilosc komorek ktore zajmie liczba informatykow
    if (m%9 == 0) infdz= m/9;
    else infdz= (m/9)+1;

    for (int j=0; j<infdz; j++) {
        //cout<< j << ": ";
        string nowy=""; //fragment ktory bedzie w jednej komorce wektora w postaci stringa
        for (int i=j*9+1; i<=(j+1)*9 && i<=b.size(); i++) {
            nowy += b[m-i];
        }
        int komorka=0; //wartosc tora znajdzie sie w komorce
        //cout<< nowy << " ";
        for (int j=nowy.size()-1; j>=0; j--) {
            komorka *= 10;
            komorka += int(nowy[j])-48;
        }
        //cout<< komorka << "\n";
        inf.push_back(komorka); //przypisanie wartosci do wektora
    }
    //wypisywanie bignuma
    /*cout<< inf[inf.size()-1]; //wypisuje wartosc z pierwszej komorki
    for (int i=inf.size()-2; i>=0; i--) {
        int pom= inf[i], d;
        for (d=8; d>=0; d--) { //licze ile dodatkowych zer nalezy wypisac
            if (pom==0) break;
            else pom /= 10;
        }
        cout<<"\n"<< i << ": " << d <<"\n";
        if (d == 8) d=7;
        for (int z=0; z<=d; z++) cout<< "0";
        cout<< inf[i];
    }
    cout<<"\n\n";*/

    int mini= min ( chem.size(), inf.size() );
    int maxi= max ( chem.size(), inf.size() );
    for (int i=0; i<mini; i++) {
        int dod= chem[i] + inf[i];
        //cout<<chem[i]<<"+"<<inf[i]<<"="<< dod << "\n";
        suma.push_back(dod);
    }
    for (int i=0; i<mini-1; i++) {
        if (suma[i]>=1000000000) {
            int pom= suma[i];
            suma[i] %= 1000000000;
            suma[i+1] += pom/1000000000;
            //cout<< suma[i] << " " << suma[i+1] << " " << pom/1000000000 << "\n";
        }
    }
    bool powiekszenie=0;
    if (suma[mini-1]>=1000000000) {
            int pom=suma[mini-1];
            suma[mini-1] %= 1000000000;
            //cout<<suma[mini-1]<< " "<< suma[mini] << "\n";
            suma.push_back(pom/1000000000);
            powiekszenie=1;
    }
    if (powiekszenie == 1 && maxi > suma.size()-1) {
        if (chem.size() == maxi) {
            suma[suma.size()-1] += chem[suma.size()-1];
            int zn=suma.size();
            while (suma.size() < maxi) {
                suma.push_back(chem[zn]);
                zn++;
            }
        }
        else if (inf.size() == maxi) {
            suma[suma.size()-1] += inf[suma.size()-1];
            int zn=suma.size();
            while (suma.size() < maxi) {
                suma.push_back(inf[zn]);
                zn++;
            }
        }
    }
    else if (powiekszenie == 0 && maxi > suma.size()) {
        if (chem.size() == maxi) {
            int zn=suma.size();
            while (suma.size() < maxi) {
                suma.push_back(chem[zn]);
                zn++;
            }
        }
        else if (inf.size() == maxi) {
            int zn=suma.size();
            while (suma.size() < maxi) {
                suma.push_back(inf[zn]);
                zn++;
            }
        }
    }
    //wypisywanie bignuma
    cout<< suma[suma.size()-1]; //wypisuje wartosc z pierwszej komorki
    for (int i=suma.size()-2; i>=0; i--) {
        int pom= suma[i], d;
        for (d=8; d>=0; d--) { //licze ile dodatkowych zer nalezy wypisac
            if (pom==0) break;
            else pom /= 10;
        }
        if (d == 8) d=7;
        for (int z=0; z<=d; z++) cout<< "0";
        cout<< suma[i];
    }

    return 0;
}
