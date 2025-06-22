#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int n,m,u;
int ke[101][101]={0};
vector<vector<int>> result;
vector<int> temp;
bool visited[101]={false};

void fileIO() {
    freopen("CT.in","r",stdin);
    freopen("CT.out","w",stdout);
}

void hamilton(int i) {
    if (temp.size()==n) {
        if (ke[temp.back()][temp[0]]==1) {
            temp.push_back(temp[0]);
            result.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    for (int j=1;j<=n;j++) {
        if (ke[i][j]==1&&!visited[j]) {
            visited[j]=true;
            temp.push_back(j);
            hamilton(j);
            temp.pop_back();
            visited[j]=false;
        }
    }
}

int main() {
    //fileIO();
    cin>>n>>m>>u;
    for (int i=1;i<=m;i++) {
        int x,y;cin>>x>>y;
        ke[x][y]=1;
        ke[y][x]=1;
    }
    temp.push_back(u);
    visited[u]=true;
    hamilton(u);
    if (result.empty()) {
        cout<<0<<'\n';
    }else {
        cout<<result.size()<<'\n';
        for (auto path : result) {
            for (int x: path) cout<< x<< ' ';
            cout<<'\n';
        }
    }
    return 0;
}
