#include <iostream>
#include <vector>
using namespace std;

vector <int> G[4000111];
int T[2010][2010];
bool odw[4000111]; //odwiedzone wierzcholki
int n, m;

void dfs (int v, int sr) { //sr to wartosc najwiekszego wierzcholka do ktorego moge wejsc, z v wyruszam
    odw[v]=1;
    for (int i=0; i<G[v].size(); i++) {
        if (odw[G[v][i]] == 0) {
            if (G[v][i] <= sr || G[v][i]==m*n+1) {
                dfs(G[v][i], sr);
            }
        }
    }
}

int binsearch(int p, int k) {
    while (p+1<k) {
        int sr= (p+k)/2;
        dfs(0, sr*m);
        if (odw[n*m+1]==1) {
            for (int i=0; i<=sr*m; i++)
                odw[i]=0;
            odw[n*m+1]=0;
            k=sr;
        }
        else {
            for (int i=0; i<=sr*m; i++)
                odw[i]=0;
            p=sr;
        }
    }
    return k; //numer linii ktora maksymalnie moze zalac woda aby robak przeszedl
}

int main () {
    ios_base::sync_with_stdio(false);
    string a;
    cin>> n >> m;
    for (int i=0; i<n; i++) {
        cin>> a;
        for (int j=0; j<m; j++) {
            if (a[j] =='.') T[i][j]=-1;
            else if (a[j] == '#') T[i][j]= 0;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (T[i][j] == -1) {
                if (i>0 && T[i-1][j] == -1) G[i*m+j+1].push_back((i-1)*m+j+1);
                if (j>0 && T[i][j-1] == -1) G[i*m+j+1].push_back(i*m+j);
                if (T[i][j+1] == -1) G[i*m+j+1].push_back(i*m+j+2);
                if (T[i+1][j] == -1) G[i*m+j+1].push_back((i+1)*m+j+1);
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (T[i][0]==-1) {
            G[i*m+1].push_back(0);
            G[0].push_back(i*m+1);
        }
        if (T[i][m-1]==-1) {
            G[(i+1)*m].push_back(m*n+1);
            G[m*n+1].push_back((i+1)*m);
        }
    }
    //binsearch po wyniku
    int x = binsearch (-1, n);
    int kolejki= n-x;
    if (kolejki == 0) cout<< "NIE";
    else cout<< kolejki;
    return 0;
}
