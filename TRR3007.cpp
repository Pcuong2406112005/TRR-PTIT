#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

int n,start;
const int MAXN = 105;
vector<int> adj[MAXN];
vector<bool> visited;
vector<vector<int>> result;
vector<int> trace;

void fileIO() {
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
}

void init() {
    cin>>n>>start;
    visited.resize(n+1);
    visited.resize(n+1,0);
    trace.resize(n+2);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int x;cin>>x;
            if (x==1) adj[i].push_back(j);
        }
    }
}

void Hamilton(int i,int s) {
    for (int j=0;j<adj[s].size();j++) {
        int res=adj[s][j];
        if (i==n+1&&res==start) {
            trace[i]=res;
            result.push_back(trace);
        }
        else if (!visited[res]) {
            trace[i]=res;
            visited[res]=true;
            Hamilton(i+1,res);
            visited[res]=false;
        }
    }
}

int main() {
    fileIO();
    init();
    trace[1]=start;
    visited[start]=true;
    Hamilton(2,start);
    if (result.size() != 0) {
        for (int i = 0; i < result.size(); i++) {
            for (int j = 1; j < result[i].size(); j++)
                cout << result[i][j] << ' '; // in từ trace[1] đến trace[n+1]
            cout << endl;
        }
    }
    cout << result.size(); // dòng cuối là số chu trình tìm được
}
