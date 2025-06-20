#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int t,n,m,u;
int ke[101][101]={0};
bool visited[101]={false};

void dfs(int i,vector<int> &temp) {
    visited[i]=true;
    temp.push_back(i);
    for (int j=1;j<=n;j++) {
        if (!visited[j]&&ke[i][j]) {
            dfs(j,temp);
        }
    }
}

void solve1() {
    memset(visited, 0, sizeof(visited));
    vector<int> temp;
    dfs(1,temp);
    if (temp.size()!=n) {
        cout<<0<<'\n';
        return;
    }
    int le=0;
    for (int i=1;i<=n;i++) {
        int tong=0;
        for (int j=1;j<=n;j++) tong=(tong+ke[i][j])%2;
        le+=tong;
    }
    if (le==0) {
        cout<<1<<'\n';
        return;
    }
    if (le==2) {
        cout<<2<<'\n';
        return;
    }
    cout<<0<<'\n';
}

void solve2() {
    stack<int> st;
    vector<int> ce;
    st.push(u);
    while (!st.empty()) {
        int cur=st.top();
        bool check=true;
        for (int i=1;i<=n;i++) {
            if (ke[cur][i]) {
                st.push(i);
                ke[cur][i]=ke[i][cur]=0;
                check=false;
                break;
            }
        }
        if (check) {
            int s=st.top();st.pop();
            ce.push_back(s);
        }
    }
    reverse(ce.begin(),ce.end());
    for (int u:ce) cout<<u<<' ';
    cout<<'\n';
}

int main() {
    cin>>t>>n>>m;
    if (t==2) cin>>u;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        ke[u][v]=ke[v][u]=1;
    }
    if (t==1) solve1();
    if (t==2) solve2();
    return 0;
}
