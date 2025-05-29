#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

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
		danhsachke[v].push_back(u);
	}
	void display1(){
		for(int i=1;i<=n;i++) cout<<danhsachke[i].size()<<" ";
		cout<<"\n";
	}
	void display2(){
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
		{
			cout<<danhsachke[i].size()<<" ";
			for(auto v:danhsachke[i]) cout<<v<<" ";
			cout<<"\n";
		}
	}	
};

void solve(int t){
	int n,k;
	cin>>n>>k;
	Graph g(n);
	for(int i=0;i<k;i++)
	{
		int u,v;cin>>u>>v;
		if(1<=u&&u<=n&&1<=v&&v<=n) g.addEdge(u,v);
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
