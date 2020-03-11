#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int T[2010][2010];
bool odw[2010][2010];
bool A[4][]= { {1,0} , {0,1} , {-1,0} , {0,-1} };
int n, m;
queue<pair<int,int> >q;

void bfs (int x, int y, int sr) {

    odw[x][y]=1;
    pair<int,int> a,b;
    int xx,yy;
    a.first=x;
    a.second=y;
    q.push(a);

    while( !q.empty() ){
        a=q.front();
        q.pop();
        x=a.first;
        y=a.second;

        for (int a=0; a<4; a++) {
            if (x>0 && y>0 && x<n-1 && y<m-1) {
                xx=A[a][0]; yy=A[0][a];
                b.first=xx;
                b.second=yy;
                if (T[xx][yy]==-1 && odw[xx][yy] == 0 && xx < sr) {
                    odw[xx][yy]=1;
                    q.push(b);
                }
            }
        }
        /*if (x>0) {
            xx= x-1 ; yy= y ;
            b.first=xx;
            b.second=yy;
            if (T[xx][yy]==-1 && odw[xx][yy] == 0 && xx < sr) {
                odw[xx][yy]=1;
                q.push(b);
            }
        }
        if (y>0) {
            xx= x ; yy= y-1 ;
            b.first=xx;
            b.second=yy;
            if (T[xx][yy]==-1 && odw[xx][yy] == 0 && xx < sr) {
                odw[xx][yy]=1;
                q.push(b);
            }
        }
        if (x<n-1) {
            xx= x+1 ; yy= y ;
            b.first=xx;
            b.second=yy;
            if (T[xx][yy]==-1 && odw[xx][yy] == 0 && xx < sr) {
                odw[xx][yy]=1;
                q.push(b);
            }
        }
        if (y<m-1) {
            xx= x ; yy= y+1 ;
            b.first=xx;
            b.second=yy;
            if (T[xx][yy]==-1 && odw[xx][yy] == 0 && xx < sr) {
                odw[xx][yy]=1;
                q.push(b);
            }
        }*/
    }
}

int binsearch(int p, int k) {

    while (p+1<k) {
        int sr= (p+k)/2;
        for (int i=0; i<n; i++) {
            if (T[i][0]==-1) {
                bfs (i, 0, sr);
            }
        }

        bool jest=0;
        for (int i=0; i<sr; i++) {
            if (odw[i][m-1]==1) jest=1;
        }
        if (jest==1) k=sr;
        else p=sr;
        for (int i=0; i<sr; i++) {
            for (int j=0; j<m; j++) {
                odw[i][j]=0;
            }
        }
    }
    return k; //numer ostatniej linii ktora moze byc zalana zeby robak przeszedl
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

    //binsearch po wyniku
    int x = binsearch (0, n);
    int kolejki= n-x;
    if (kolejki == 0) cout<< "NIE";
    else cout<< kolejki;
    return 0;
}
