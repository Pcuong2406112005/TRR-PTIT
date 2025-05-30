#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

void fileIO(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

class Graph{
	private:
		int dinh;
		int canh;
		vector<pair<int,int>> danhsachcanh;
		vector<pair<int,int>> deg;
	public:
	Graph(int n,int k):dinh(n),canh(k){
		deg.resize(n+1,{0,0});
		for(int i=1;i<=k;i++)
		{
			int u,v;cin>>u>>v;
			add(u,v);
			deg[u].second++;
			deg[v].first++;
		}
	}
	void add(int u,int v){
		danhsachcanh.push_back({u,v});
	}
	void display1(){
		for(int i=1;i<=dinh;i++)
		{
			cout<<deg[i].first<<" "<<deg[i].second<<"\n";
		}
	}
	void display2(){
		cout<<dinh<<" "<<canh<<"\n";
		vector<vector<int>> matranlienthuoc(dinh+1,vector<int>(canh+1,0));
		for(int i=0;i<canh;i++)
		{
			matranlienthuoc[danhsachcanh[i].first][i+1]=1;
			matranlienthuoc[danhsachcanh[i].second][i+1]=-1;
		}
		for(int i=1;i<=dinh;i++)
		{
			for(int j=1;j<=canh;j++)
			{
				cout<<matranlienthuoc[i][j]<<" ";
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
	if(t==1) g.display1();
	if(t==2) g.display2();
}

int main()
{
	fileIO();
	int t;cin>>t;solve(t);
	return 0;
}