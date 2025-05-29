#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void fileIO(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

class Graph{
private:
	int n;
	vector<vector<int>> danhsachke;
	vector<vector<int>> matranke;
public:
	Graph(int n):n(n){
		danhsachke.resize(n+1);
		matranke = vector<vector<int>>(n+1, vector<int>(n+1, 0));
	}
	void addEdge(int u,int v){
		danhsachke[u].push_back(v);
		danhsachke[v].push_back(u);
	}
	void addmatranke(int u,int v){
		matranke[u][v]=1;
		matranke[v][u]=1;
	}
	void display1()
	{
		for(int i=1;i<=n;i++) cout<<danhsachke[i].size()<<" ";
		cout<<endl;		
	}
	void display2()
	{
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<matranke[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
};

void solve(int t){
	int n,k;
	cin>>n>>k;
	Graph g(n);
	if(t==1)
	{
		for(int i=0;i<k;i++)
		{
			int u,v;cin>>u>>v;
			if(1<=u&&u<=n&&1<=v&&v<=n) g.addEdge(u,v);
		}
		g.display1();
	}
	if(t==2)
	{
		for(int i=0;i<k;i++)
		{
			int u,v;cin>>u>>v;
			if(1<=u&&u<=n&&1<=v&&v<=n) g.addmatranke(u,v);
		}
		g.display2();
	}
}

int main()
{
	fileIO();
	int t;cin>>t; solve(t);
	return 0;
}
