#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,start;
int ke[101][101];
bool visited[101]={false};
vector<pair<int,vector<int>>> result;
vector<int> temp;

void init() {
    cin>>n>>start;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
    temp.push_back(start);
}

void hamilton(int u) {
    if (temp.size()==n) {
        if (ke[u][start]!=0&&ke[u][start]!=10000) {
            temp.push_back(start);
            int sum=0;for (int i=1;i<=n;i++) sum+=ke[temp[i-1]][temp[i]];
            result.push_back({sum,temp});
            temp.pop_back();
        }
        return;
    }
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[u][i]!=0&&ke[u][i]!=10000) {
            visited[i]=true;
            temp.push_back(i);
            hamilton(i);
            visited[i]=false;
            temp.pop_back();
        }
    }
}

void solve() {
    hamilton(temp.back());
    int len=result.size();
    if (len==0) {
        cout<<0<<'\n';
        return;
    }
    sort(result.begin(),result.end());
    cout<<result[0].first<<'\n';
    for (int u:result[0].second) {
        cout<<u<<' ';
    }
    cout<<'\n';
}

int main() {
    init();
    solve();
    return 0;
}
