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
		cout<<endl;
	}
	void display2(){
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
		{
			cout<<danhsachke[i].size()<<" ";
			for(int u:danhsachke[i]) cout<<u<<" ";
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
		for(int j=1;j<=n;j++)
		{
			int x;cin>>x;
			if(j>i&&x==1) g.addEdge(i,j);
		}
	}
	if(t==1) g.display1();
	if(t==2) g.display2();
}

int main()
{
	fileIO();
	int t;cin>>t;
	solve(t);
}
