#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

int n;
int ke[101][101];
bool visited[101];

void fileIO() {
    freopen("TK.INP","r",stdin);
    freopen("TK.OUT","w",stdout);
}

void resetvisited() {
    for (int i=1;i<=n;i++) {
        visited[i]=false;
    }
}

void bfs(int i,vector<int> &temp) {
    queue<int> q;
    temp.push_back(i);
    visited[i]=true;
    q.push(i);
    while (!q.empty()) {
        int cur=q.front();
        q.pop();
        for (int j=1;j<=n;j++) {
            if (!visited[j]&&ke[cur][j]) {
                q.push(j);
                visited[j]=true;
                temp.push_back(j);
            }
        }
    }
}


void lienthong()
{
    bool lienthongmanh=true;
    for (int i=1;i<=n;i++) {
        resetvisited();
        vector<int> temp;
        bfs(i,temp);
        if (temp.size()!=n) {
            lienthongmanh=false;
            break;
        }
    }
    if (lienthongmanh) {
        cout<<1<<'\n';
        return;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (ke[i][j]==1) ke[j][i]=1;
        }
    }
    resetvisited();
    vector<int> temp;
    bfs(1,temp);
    if (temp.size()==n) cout<<2<<'\n';
    else cout<<0<<'\n';
}

int main() {
    fileIO();
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
    lienthong();
}
