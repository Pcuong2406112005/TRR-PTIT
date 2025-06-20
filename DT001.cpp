#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int t,n;
int ke[101][101];
int deg[101]={0};
vector<pair<int,int>> edge;

void fileIO() {
    freopen("DT.INP","r",stdin);
    freopen("DT.OUT","w",stdout);
}

int main() {
    //fileIO();
    cin>>t>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
            if (ke[i][j]) deg[i]++;
            if (j>i&&ke[i][j]) edge.push_back({i,j});
        }
    }
    if (t==1) {
        for (int i=1;i<=n;i++) {
            cout<<deg[i]<<' ';
        }
        cout<<'\n';
    }
    if (t==2) {
        cout<<n<<' '<<edge.size()<<'\n';
        for (auto x:edge) {
            cout<<x.first<<' '<<x.second<<'\n';
        }
    }
}
