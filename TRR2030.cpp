#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
int ke[101][101];
bool visited[101];
vector<pair<int,int>> result;
vector<pair<int,int>> edges;

void fileIO() {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
}

void init() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
            if (ke[i][j]==1) edges.push_back({i,j});
        }
    }
}

void dfs(int u) {
    visited[u]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[u][i]) {
            dfs(i);
        }
    }
}

void timCanhCau() {
    int tplt=0;
    memset(visited,0,sizeof(visited));
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            dfs(i);tplt++;
        }
    }
    for (auto [x,y]:edges) {
        memset(visited,0,sizeof(visited));
        ke[x][y]=0;
        int tplt_temp=0;
        for (int i=1;i<=n;i++) {
            if (!visited[i]) {
                dfs(i);tplt_temp++;
            }
        }
        if (tplt_temp>tplt) result.push_back({x,y});
        ke[x][y]=1;
    }
}

void solve() {
    timCanhCau();
    int len=result.size();
    if (len==0) {
        cout<<0<<'\n';
        return;
    }
    cout<<len<<'\n';
    for (int i=0;i<len;i++) {
        cout<<result[i].first<<' '<<result[i].second<<'\n';
    }
}

int main() {
    fileIO();
    init();
    solve();
    return 0;
}
