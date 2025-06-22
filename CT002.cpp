#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

int t,n,start;
int ke[101][101];
bool visited[101];

void dfs(int u) {
    visited[u]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[u][i]) {
            dfs(i);
        }
    }
}

void checklienthong() {
    memset(visited,0,sizeof(visited));
    int tplt=0;
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            dfs(i);tplt++;
        }
    }
    if (tplt>1) {
        cout<<0<<endl;
        return;
    }
    int deg_odd=0;
    for (int i=0;i<=n;i++) {
        int sum=0;
        for (int j=1;j<=n;j++) sum=(sum+ke[i][j])%2;
        deg_odd+=sum;
    }
    if (deg_odd==0) {
        cout<<1<<endl;
        return;
    }
    if (deg_odd==2) {
        cout<<2<<endl;
        return;
    }
    cout<<0<<endl;
}

void findEulerCycle(int start) {
    stack<int> st;
    st.push(start);
    vector<int> ce;
    while (!st.empty()) {
        bool check=true;
        int cur=st.top();
        for (int i=1;i<=n;i++) {
            if (ke[cur][i]) {
                st.push(i);
                ke[cur][i]=ke[i][cur]=0;
                check=false;
                break;
            }
        }
        if (check) {
            ce.push_back(cur);
            st.pop();
        }
    }
    reverse(ce.begin(),ce.end());
    for (int u:ce) cout<<u<<' ';
    cout<<'\n';
}

void init() {
    cin>>t>>n;if (t==2) cin>>start;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
}

int main() {
    init();
    if (t==1) checklienthong();
    if (t==2) findEulerCycle(start);
    return 0;
}
