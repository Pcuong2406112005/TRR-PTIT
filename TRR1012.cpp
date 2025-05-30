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
		vector<vector<int>> matranke;
		vector<pair<int,int>> danhsachcanh;
	public:
	Graph(int n):n(n){
		matranke=vector<vector<int>> (n+1,vector<int>(n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>matranke[i][j];
				if(matranke[i][j]==1) addEdge(i,j);
			}
		}
	}
	void addEdge(int u,int v){
		danhsachcanh.push_back({u,v});
	}
	void display1(){
		for(int i=1;i<=n;i++)
		{	
			int indeg=0;int outdeg=0;
			for(int j=1;j<=n;j++)
			{
				indeg+=matranke[j][i];
				outdeg+=matranke[i][j];
			}
			cout<<indeg<<" "<<outdeg<<"\n";
		}
	}
	void display2(){
		cout<<n<<" "<<danhsachcanh.size()<<"\n";
		for(auto &x:danhsachcanh) cout<<x.first<<" "<<x.second<<"\n";
	}
};

void solve(int t)
{
	int n;
	cin>>n;
	Graph g(n);
	if(t==1) g.display1();
	if(t==2) g.display2();
}

int main()
{
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}