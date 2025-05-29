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
		int n;int k;
		vector<vector<int>> danhsachke;
		vector<vector<int>> matranlienthuoc;
	public:
	Graph(int n,int k):n(n),k(k){
		danhsachke.resize(n+1);
		matranlienthuoc=vector<vector<int>> (n,vector<int> (k,0));		
	}
	void addEdge(int u,int v){
		danhsachke[u].push_back(v);
		danhsachke[v].push_back(u);
	}
	void addlienthuoc(int u,int v,int i){
		matranlienthuoc[u-1][i]=1;
		matranlienthuoc[v-1][i]=1;
	}
	void display1(){
		for(int i=1;i<=n;i++) cout<<danhsachke[i].size()<<" ";
		cout<<"\n";
	}
	void display2(){
		cout<<n<<" "<<k<<"\n";
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k;j++)
			{
				cout<<matranlienthuoc[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};

void solve(int t){
	int n,k;
	cin>>n>>k;
	Graph g(n,k);
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
			if(1<=u&&u<=n&&1<=v&&v<=n) g.addlienthuoc(u,v,i);
		}
		if(t==2) g.display2();
	}
}

int main()
{
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}
