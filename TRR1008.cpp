#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<set>

using namespace std;

void fileIO(){
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
		set<pair<int,int>> danhsachcanh;
		for(int i=1;i<=n;i++)
		{
			for(int v:danhsachke[i])
			{
				if(i<v) danhsachcanh.insert({i,v});
			}
		}
		cout<<n<<" "<<danhsachcanh.size()<<"\n";
		for(auto &x:danhsachcanh) cout<<x.first<<" "<<x.second<<"\n";
	}	
};

void solve(int t)
{
	int n;cin>>n;
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
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}