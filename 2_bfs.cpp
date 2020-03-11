#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[1000000];
int odl[1000000]; //odleglosc wierzcholkow
int w;
void bfs (int v) {
    for (int i=0; i<=w; i++) odl[i]=1000000000;
    odl[v]=0;
    queue <int> q;
    q.push(v);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for (int j=0; j<G[u].size(); j++) {
            int x=G[u][j];
            if (odl[x]>odl[u]+1) {
                odl[x]=odl[u]+1;
                q.push(x);
            }
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    int k, a, b; //w wierzcholki, k krawedzie, a b wierzcholki ktore laczy dana krawedz
    cin>> w >> k;
    for (int i=0; i<k; i++) {
        cin>> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(1);
    for (int i=1; i<=w; i++) {
        if (odl[i]==1000000000) cout<< "-1\n";
        else cout<< odl[i] << "\n";
    }
    /*for (int i=1; i<=w; i++) {
        cout<< odl[i] << "\n";
    }*/
    return 0;
}
