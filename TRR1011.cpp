#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void fileIO()
{
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

class Graph{
	private:
		int n,k;
		vector<vector<int>> matrantrongso;
	public:
	Graph(int n,int k):n(n),k(k){
		matrantrongso=vector<vector<int>> (n+1,vector<int> (n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) matrantrongso[i][j]=0;
				else matrantrongso[i][j]=10000;
			}
		}	
	}
	void addEdge(int u,int v,int g){
		matrantrongso[u][v]=g;
		matrantrongso[v][u]=g;
	}
	void display1(){
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				if(matrantrongso[i][j]!=0&&matrantrongso[i][j]!=10000) res++;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	void display2(){
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<matrantrongso[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
};

void solve(int t)
{
	int n,k;
	cin>>n>>k;
	Graph g(n,k);
	for(int i=0;i<k;i++)
	{
		int u,v,trs;cin>>u>>v>>trs;
		g.addEdge(u,v,trs);
	}
	if(t==1) g.display1();
	if(t==2) g.display2();
}

int main()
{
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}