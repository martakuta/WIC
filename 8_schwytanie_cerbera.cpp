#include <iostream>
using namespace std;

const int M= 1024*1024;
int A[M];
int D[2*M];

void add (int poz, int war) {
    //cout<< "\nadd" << poz <<" ";
    D[poz] = war;
    while (poz > 1) {
        poz /= 2;
        D[poz] = D[2*poz] + D[2*poz+1];
        //cout<< poz <<" "<< D[poz]<<"   ";
    }
}

int szukaj (int a) {
    //cout<< "\n\n" << a << "\n";
    int x=1;
    while (a>=1) {
        //cout<<"-"<<D[2*x]<<"- ";
        if (D[2*x]>=a) {
                x = 2*x;
                //cout<< "+";
        }
        else {
            a -= D[2*x];
            x = 2*x+1;
            //cout<<"   "<< a << " "<< x <<"   ";
        }
        if (x >= M) {
            //cout<< "*"<< x <<"*";
            add (x, 0);
            return x-M+1;
        }
    }

}

int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>> n;
    for (int i=0; i<n; i++) {
        cin>> A[i];
    }
    for (int i=M; i<M+n; i++) {
        D[i]= 1;
    }
    for (int i=M-1; i>0; i--) {
        D[i] = D[2*i] + D[2*i+1];
    }
    for (int i=n-1; i>=0; i--) {
        int pom= A[i]+1;
        A[i] = szukaj(pom);
    }

    for (int i=0; i<n; i++)
        cout<< A[i] <<" ";
    return 0;
}
