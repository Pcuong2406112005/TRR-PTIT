#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>

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
	void display1(){//in ra so bac cua dinh
		for(int i=1;i<=n;i++) cout<<danhsachke[i].size()<<" ";
		cout<<"\n";
	}
	void display2(){//in ra ma tran ke cua dinh
		vector<vector<int>> matranke(n+1,vector<int> (n+1,0));
		for(int i=1;i<=n;i++)
		{
			for(int v:danhsachke[i]) matranke[i][v]=1;
		}
		cout<<n<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) cout<<matranke[i][j]<<" ";
			cout<<"\n";
		}
	}
};

void solve(int t)
{
	int n;
	cin>>n;
	Graph g(n);
	for(int i=0;i<n;i++)
	{
		int cnt;cin>>cnt;
		while(cnt--)
		{
			int x;cin>>x;
			g.addEdge(i+1,x);
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