#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void fileIO(){
	freopen("TK.INP","r",stdin);
	freopen("TK.OUT","w",stdout);
}

class Graph{
	private:
		int n;
		vector<vector<int>> matranke;
		vector<vector<int>> paths;
		vector<int> parent;
		vector<bool> visited; 
		bool found;
	public:
	Graph(int n):n(n){
		visited.resize(n+1);
		parent.resize(n+1);
		matranke=vector<vector<int>> (n+1,vector<int> (n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>matranke[i][j];
			}
		}
	}	
	void display1(int u,int v)
	{
		int result=0;
		for(int i=1;i<=n;i++)
		{
			if(matranke[u][i]==1&&matranke[i][v]==1) result++;
		}
		cout<< result <<"\n";
	}
	void dfs(int u,int v)
	{
		visited[u]=true;
		if(u==v){
			found=true;
			return;
		}
		for (int i=1;i<=n;i++) {
        	if (!visited[i]&&matranke[u][i]==1) {
            parent[i] = u;
            dfs(i, v);
            if (found) return;
        }
    }
	}
	void display2(int u,int v)
	{
		fill(visited.begin(),visited.end(),false);
		fill(parent.begin(),parent.end(),-1);
		found=false;
		dfs(u,v);
		vector<int> path;
		for(int x=v;x!=-1;x=parent[x]) path.push_back(x);
		reverse(path.begin(),path.end());
		for(int y:path) cout<<y<<" ";
		cout<<"\n";
	}
};

void solve(int t)
{
	int n,u,v;
	cin>>n>>u>>v;
	Graph g(n);
	if(t==1) g.display1(u,v);
	if(t==2) g.display2(u,v);
}

int main()
{
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}