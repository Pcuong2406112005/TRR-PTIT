#include<iostream>
#include<vector>

using namespace std;

struct canh {
    int u,v,w;
};

const int MAXN = 101;

int n,start;
int totalLen=0;
vector<canh> edges;
vector<canh> mst;
bool visited[101]={false};

void fileIO() {
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
}

void Prim() {
    visited[start]=true;
    int cnt=n-1;
    while (cnt--) {
        canh chon={-1,-1,10001};
        for (canh c:edges) {
            if ((!visited[c.u]&&visited[c.v])||(visited[c.u]&&!visited[c.v])) {
                if (c.w<chon.w) {
                    chon=c;
                }
            }
        }
        if (chon.w==-10001) break;
        visited[chon.u]=visited[chon.v]=true;
        mst.push_back(chon);
        totalLen+=chon.w;
    }
}

void init() {
    cin>>n>>start;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int x;cin>>x;
            if (j>i&&x<10000) {
                edges.push_back({i,j,x});
            }
        }
    }
}

void solve() {
    Prim();
    if (mst.size()!=n-1) {
        cout<<0<<'\n';
    }
    cout<<totalLen<<'\n';
    for (canh x:mst) {
        cout<<x.u<<' '<<x.v<<' '<<x.w<<'\n';
    }
}

int main() {
    fileIO();
    init();
    solve();
    return 0;
}
