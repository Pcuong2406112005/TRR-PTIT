#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

const int MAXN = 101;

int n,m;
vector<tuple<int,int,int>> edges;
int parent[MAXN];
int mst_weigh,edges_used;
vector<tuple<int,int,int>> result;
bool found;

void fileIO() {
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
}

void init() {
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
}

int find(int x) {
    if (parent[x]!=x) {
        return find(parent[x]);
    }
    return x;
}

bool unite(int u,int v) {
    int pu=find(u);
    int pv=find(v);
    if (pu==pv) return false;
    parent[pu]=pv;
    return true;
}

void kruskal() {
    for (auto [w,u,v]:edges) {
        if (unite(u,v)) {
            mst_weigh+=w;
            edges_used++;
            result.push_back({min(u,v),max(u,v),w});
            if (edges_used==n-1) {
                found=true;
                break;
            }
        }
    }
}

void solve() {
    for (int i=1;i<=n;i++) parent[i]=i;
    sort(edges.begin(),edges.end());
    mst_weigh=0,edges_used=0;
    found=false;
    kruskal();
    if (found==false) {
        cout<<0<<'\n';
        return;
    }
    cout<<mst_weigh<<'\n';
    for (auto [u,v,w]:result) {
        cout<<u<<' '<<v<<' '<<w<<'\n';
    }
}

int main() {
    fileIO();
    init();
    solve();
}
