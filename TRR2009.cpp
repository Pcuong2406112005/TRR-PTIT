#include <iostream>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

int n;
int TPLT;
bool visited[101];
int ke[101][101];
vector<vector<int>> result;

void fileIO() {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
}

void dfs(int u,vector<int> &temp) {
    visited[u]=true;
    temp.push_back(u);
    for (int i=1;i<=n;i++) {
        if (ke[u][i]==1&&visited[i]==false) {
            dfs(i,temp);
        }
    }
}

void timTPLT() {
    for (int i=1;i<=n;i++) visited[i]=false;
    TPLT=0;
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            vector<int> temp;
            dfs(i,temp);
            sort(temp.begin(), temp.end());
            result.push_back(temp);
            TPLT++;
        }
    }
    cout<<result.size()<<endl;
    for (auto x:result) {
        for (int v:x) {
            cout<<v<<" ";
        }
        cout<<'\n';
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
    timTPLT();
}
