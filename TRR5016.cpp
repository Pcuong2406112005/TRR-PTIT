#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
int n;
int ke[101][101];
int dist[101][101];
int nxt[101][101];

void fileIO() {
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
}

void init() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> ke[i][j];
        }
    }
}

void floyd() {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (ke[i][j]<10000) dist[i][j] = ke[i][j];
            else dist[i][j] = INF;

            if (ke[i][j]<10000) nxt[i][j]=j;
            else nxt[i][j]=-1;
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (dist[i][k]<INF&&dist[k][j]<INF&&dist[i][k]+dist[k][j]<dist[i][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    nxt[i][j]=nxt[i][k];
                }
            }
        }
    }
}

vector<int> reconstructPath(int u,int v) {
    vector<int> Path;
    if (u==v) return Path;
    Path.push_back(u);
    while (u!=v) {
        u=nxt[u][v];
        Path.push_back(u);
    }
    return Path;
}

void solve() {
    floyd();
    int maxDist=-1,bestU=-1,bestV=-1;

    for (int u=1;u<=n;u++) {
        for (int v=1;v<=n;v++) {
            if (u!=v&&dist[u][v]<INF) {
                if (dist[u][v]>maxDist||(dist[u][v]==maxDist&&make_pair(u,v)<make_pair(bestU,bestV))){
                    maxDist=dist[u][v];
                    bestU=u;
                    bestV=v;
                }
            }
        }
    }
    if (maxDist==-1) {
        cout<<0<<'\n';
        return;
    }else {
        cout<<bestU<<' '<<bestV<<' '<<maxDist<<'\n';
        vector<int> path=reconstructPath(bestU,bestV);
        for(int u:path) cout<<u<<' ';
    }
}

int main() {
    fileIO();
    init();
    solve();
    return 0;
}
