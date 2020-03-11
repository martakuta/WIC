#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector <int> G[1000000];
int odl[1000000]; //odleglosc wierzcholkow
int n;
void bfs (int v) {
    for (int i=1; i<=n; i++) odl[i]=1000000000;
    odl[v]=0;
    queue <int> q;
    q.push(v);
    while (!q.empty()) { //czyli dopoki kolejka nie bedzie pusta
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
    int a, b; //w wierzcholki, k krawedzie, a b wierzcholki ktore laczy dana krawedz
    cin>> n;
    for (int i=0; i<n-1; i++) {
        cin>> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(1);
    int najw=0, punkt=0;
    for (int i=1; i<=n; i++) {
        if (odl[i]>najw){
            najw=odl[i];
            punkt=i;
        }
    }
    bfs(punkt);
    int najw2=0;
    for (int i=1; i<=n; i++) {
        if (odl[i]>najw2) najw2=odl[i];
    }
    cout<< najw2;
    return 0;
}
