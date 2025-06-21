#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#include<algorithm>

using namespace std;

int n,s,t;
const int MAXN = 101;
const int INF = 1e9;

vector<pair<int,int>> adj[MAXN];
int dist[MAXN], trace[MAXN];
bool visited[MAXN];

void fileIO() {
    freopen("DN.INP","r",stdin);
    freopen("DN.OUT","w",stdout);
}

void init() {
    cin>>n>>s>>t;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int x;cin>>x;
            if (x!=10000&&x!=0) adj[i].push_back({j,x});
        }
    }
}

void dijkstra(int start) {
    for (int i=1;i<=n;i++) {
        dist[i]=INF;
        visited[i]=false;
        trace[i]=-1;
    }
    dist[start]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,start});
    while (!pq.empty()) {
        auto [x,u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u]=true;
        for (auto [v,w]:adj[u]) {
            if (dist[v]>dist[u]+w) {
                dist[v]=dist[u]+w;
                trace[v]=u;
                pq.push({dist[v],v});
            }
        }
    }
}

void solve() {
    dijkstra(s);
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
