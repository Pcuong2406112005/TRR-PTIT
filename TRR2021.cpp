#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int ke[101][101];
bool visited[101]={false};
vector<int> result;
int TPLT=0;

void fileIO() {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
}

void dfs(int u,int emit) {
    visited[u]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[u][i]&&i!=emit) {
            dfs(i,emit);
        }
    }
}

int main() {
    fileIO();
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            dfs(i,-1);
            TPLT++;
        }
    }
    for (int i=1;i<=n;i++) {
        memset(visited,0,sizeof(visited));
        int tplt=0;
        for (int j=1;j<=n;j++) {
            if (!visited[j]&&j!=i) {
                dfs(j,i);
                tplt++;
            }
        }
        if (tplt>TPLT) result.push_back(i);
    }
    cout<<result.size()<<'\n';
    for (int u:result) cout<<u<<' ';
    cout<<'\n';
}
