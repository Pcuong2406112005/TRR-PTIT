#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int t,n,start;
int ke[101][101];
vector<int> result;
bool visited[101];

void fileIO() {
    freopen("CT.INP","r",stdin);
    freopen("CT.OUT","w",stdout);
}

void dfs(int u) {
    visited[u]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&ke[u][i]) dfs(i);
    }
}

void check() {
    int LT=0;
    for (int i=1;i<=n;i++) visited[i]=false;
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            dfs(i);LT++;
        }
    }
    if (LT>1) {
        cout<<0<<'\n';
        return;
    }
    int deg_odd=0;
    for (int i=1;i<=n;i++) {
        int sum=0;
        for (int j=1;j<=n;j++) sum=(sum+ke[i][j])%2;
        deg_odd+=sum;
    }
    if (deg_odd==0) {
        cout<<1<<'\n';
        return;
    }
    if (deg_odd==2) {
        cout<<2<<'\n';
        return;
    }
    cout<<0<<'\n';
}

void find_Euler_Cycle(int start) {
    stack<int> st;
    st.push(start);
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
            st.pop();
            result.push_back(cur);
        }
    }
    reverse(result.begin(),result.end());
    for (int v:result) cout<<v<<' ';
    cout<<endl;
}

int main() {
    fileIO();
    cin>>t>>n;if (t==2) cin>>start;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>ke[i][j];
        }
    }
    if (t==1) check();
    if (t==2) find_Euler_Cycle(start);
    return 0;
}
