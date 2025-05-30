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
		vector<vector<int>> matranke;
		vector<pair<int,int>> danhsachcanh;
	public:
	Graph(int n):dinh(n){
		matranke=vector<vector<int>> (dinh+1,vector<int>(dinh+1,0));
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			while(x--)
			{
				int u;cin>>u;
				matranke[i][u]=1;
				danhsachcanh.push_back({i,u});
			}
		}
	}
	void display1(){
		for(int i=1;i<=dinh;i++)
		{
			int indeg=0;int outdeg=0;
			for(int j=1;j<=dinh;j++)
			{
				indeg+=matranke[j][i];
				outdeg+=matranke[i][j];
			}
			cout<<indeg<<" "<<outdeg<<"\n";
		}
	}
	void display2(){
		int canh=danhsachcanh.size();
		cout<<dinh<<" "<<canh<<"\n";
		vector<vector<int>> matranlienthuoc(dinh+1,vector<int> (canh+1,0));
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