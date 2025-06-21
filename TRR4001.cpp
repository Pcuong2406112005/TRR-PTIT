#include<iostream>
#include<vector>
#include<queue>
#include<fstream>

using namespace std;

int t,n,start;
vector<pair<int,int>> result;
int ke[101][101];
bool visited[101];

void fileIO() {
    freopen("CK.INP","r",stdin);
    freopen("CK.OUT","w",stdout);
}

void Tree_DFS(int root) {
    visited[root]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[root][i]) {
            result.push_back({min(root,i),max(root,i)});
            Tree_DFS(i);
        }
    }
}

void Tree_BFS(int root) {
    queue<int> q;
    q.push(root);
    visited[root]=true;
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int i=1;i<=n;i++) {
            if (!visited[i]&&ke[cur][i]) {
                visited[i]=true;
                result.push_back({min(cur,i),max(cur,i)});
                q.push(i);
            }
        }
    }
}

int main() {
    fileIO();
    cin>>t>>n>>start;
    for (int i=1;i<=n;i++) {
        visited[i]=false;
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
    if (t==1) Tree_DFS(start);
    if (t==2) Tree_BFS(start);
    if (result.size()!=n-1) {
        cout<<0<<'\n';
    }
    else {
        cout<<result.size()<<'\n';
        for (auto [x,y]:result) {
            cout<<x<<' '<<y<<'\n';
        }
    }
}
