#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 101;
int t,n,start;
vector<int> adj[MAXN];
bool visited[MAXN]={false};
int ke[MAXN][MAXN];

void dfs(int u) {
    visited[u]=true;
    for (int i=1;i<=n;i++) {
        if (!visited[i]&&(ke[u][i]||ke[i][u])) {
            dfs(i);
        }
    }
}

void findEulerType(){
    //1 là đồ thị Euler,2 là đồ thị nửa Euler,0 là không thuộc 2 TH trên
    vector<int> in_deg(MAXN,0),out_deg(MAXN,0);
    vector<int> non_equal;
    for (int i=1;i<=n;i++){
        for (auto a:adj[i]) in_deg[a]++;
        out_deg[i]=adj[i].size();
    }
    for (int i=1;i<=n;i++){
        if (in_deg[i]!=out_deg[i]) non_equal.push_back(i);
    }
    int temp = non_equal.size();
    if (temp==0){
        cout<<1<<'\n';
        return;
    }
    if (temp==2){
        int in_deg1 = in_deg[non_equal[0]];
        int out_deg1 = out_deg[non_equal[0]];
        int in_deg2 = in_deg[non_equal[1]];
        int out_deg2 = out_deg[non_equal[1]];
        if (in_deg1-out_deg1==out_deg2-in_deg2 && abs(in_deg1-out_deg1)==1) {
            cout<<2<<'\n';
            return;
        }
    }
    cout<<0;
}
void solve2(){
    stack<int> st;
    st.push(start);
    vector<int> ce;
    while (st.size()){
        int a = st.top();
        if (!adj[a].size()){
            ce.push_back(a);
            st.pop();
        }else{
            st.push(adj[a][0]);
            adj[a].erase(adj[a].begin());
        }
    }
    for (int i=ce.size()-1;i>=0;i--) cout<<ce[i]<<" ";
}
int main(){
    cin>>t>>n;
    if (t==2) cin>>start;
    memset(ke,0,sizeof(ke));
    for (int i=1;i<=n;i++){
        int m,b;
        cin>>m;
        for (int j=1;j<=m;j++){
            cin>>b;
            ke[i][b]=1;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (ke[i][j]) adj[i].push_back(j);
    if (t==1) {
        //check liên thông yếu
        int tplt=0;
        for (int i=1;i<=n;i++) {
            if (!visited[i]) {
                dfs(i);tplt++;
            }
        }
        if (tplt>1) cout<<0<<'\n';
        else findEulerType();
    }
    if (t==2) solve2();
    return 0;
}
