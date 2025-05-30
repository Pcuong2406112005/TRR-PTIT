#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

using namespace std;

void fileIO()
{
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

class Graph{
	private:
		int n;
		vector<vector<int>> danhsachke;
	public:
	Graph(int n):n(n){
		danhsachke.resize(n+1);
	}
	void addEdge(int u,int v){
		danhsachke[u].push_back(v);	
	}
	void display1(){
		for(int i=1;i<=n;i++) cout<<danhsachke[i].size()<<" ";
		cout<<"\n";
	}
	void display2(){
		vector<pair<int,int>> danhsachcanh;
		for(int i=1;i<=n;i++)
		{
			for(int v:danhsachke[i])
			{
				if(i<v) danhsachcanh.push_back({i,v});
			}
		}
		vector<vector<int>> matranlienthuoc(n,vector<int> (danhsachcanh.size(),0));
		for(int i=0;i<danhsachcanh.size();i++)
		{
			matranlienthuoc[danhsachcanh[i].first-1][i]=1;
			matranlienthuoc[danhsachcanh[i].second-1][i]=1;
		}
		cout<<n<<" "<<danhsachcanh.size()<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j:matranlienthuoc[i]) cout<<j<<" ";
			cout<<"\n";
		}
	}
};

void solve(int t)
{
	int n;
	cin>>n;
	Graph g(n);
	for(int i=1;i<=n;i++)
	{
		int cnt;cin>>cnt;
		while(cnt--)
		{
			int u;cin>>u;
			g.addEdge(i,u);
		}
	}
	if(t==1) g.display1();
	if(t==2) g.display2();
}

int main()
{
	//fileIO();
	int t;cin>>t;solve(t);
	return 0;
}