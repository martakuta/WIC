#include <iostream>
#include <vector>
using namespace std;
vector <int> G[1000000];
bool odw[1000000]; //odwiedzone wierzcholki
void dfs (int v) {
    odw[v]=1;
    for (int i=0; i<G[v].size(); i++) {
        if (odw[G[v][i]]==0)
            dfs(G[v][i]);
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    int w, k, a, b; //w wierzcholki, k krawedzie, a b wierzcholki ktore laczy dana krawedz
    cin>> w >> k;
    for (int i=0; i<k; i++) {
        cin>> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for (int i=1; i<=w; i++) {
        if (odw[i]==1) cout<< "TAK\n";
        else cout<< "NIE\n";
    }
    return 0;
}
