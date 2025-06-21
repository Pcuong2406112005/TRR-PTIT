#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<algorithm>
#include<tuple>

using namespace std;

int n,s,t;
const int MAXN = 101;
const int INF = 1e9;

vector<tuple<int,int,int>> edges;
int dist[MAXN], trace[MAXN];

void fileIO() {
    freopen("BN.INP","r",stdin);
    freopen("BN.OUT","w",stdout);
}

void init() {
    cin>>n>>s>>t;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int x;cin>>x;
            if (x!=10000&&x!=0) edges.push_back({i,j,x});
        }
    }
}

void bellmanford(int start) {
    for (int i=1;i<=n;i++) {
        dist[i]=INF;
        trace[i]=-1;
    }
    dist[start]=0;
    for (int i=1;i<=n-1;i++) {
        for (auto [u,v,w]:edges) {
            if (dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                trace[v]=u;
            }
        }
    }
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[v] > dist[u] + w) {
            cout << -1 << endl;
            exit(0);
        }
    }
}

void solve() {
    bellmanford(s);
    if (dist[t]==INF) {
        cout<<0<<endl;
        return;
    }
    cout<<dist[t]<<endl;
    vector<int> path;
    for (int v=t;v!=-1;v=trace[v]) {
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    for (int v:path) cout<<v <<' ';
    cout<<endl;
}

int main() {
    fileIO();
    init();
    solve();
    return 0;
}
