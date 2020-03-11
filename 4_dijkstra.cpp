#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector <pair <int, int> > G[100005];
long long odl[100005];
bool odw[100005];
int n;
void dijkstra (int v) {
    for (int i=1; i<=n; i++) {
        odl[i] = 1000000000;
        odw[i] = 0;
    }
    odl[v] = 0;
    priority_queue <pair <int, int> > q;
    int u, w, cost;
    q.push (make_pair(0, v));
    while (!q.empty()) {
        u=q.top().second;
        cost= - q.top().first;
        q.pop();
        if (odw[u] == 1) continue;
        odw[u] = 1;
        for (int i=0; i<G[u].size(); i++) {
            w= G[u][i].second;
            if (cost + G[u][i].first < odl[w]) {
                odl[w] = cost + G[u][i].first;
                q.push(make_pair (-odl[w], w));
            }
        }
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    int m, a, b, d;
    cin>> n >> m;
    for (int i=1; i<=m; i++) {
        cin>> a >> b >> d;
        G[a].push_back(make_pair (d, b));
        G[b].push_back(make_pair (d, a));
    }
    dijkstra(1);
    for (int i=1; i<=n; i++) {
        if (odl[i] == 1000000000 ) cout<< "-1\n";
        else cout<< odl[i] <<"\n";
    }
    return 0;
}
