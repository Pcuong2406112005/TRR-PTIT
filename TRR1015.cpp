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
		vector<vector<int>> matranke;
	public:
	Graph(int n,int k):dinh(n),canh(k){
		matranke=vector<vector<int>> (n+1,vector<int>(n+1,0));
		for(int i=1;i<=k;i++)
		{
			int u,v;cin>>u>>v;
			if(1<=u&&u<=dinh&&1<=v&&v<=dinh) add(u,v);
		}
	}
	void add(int u,int v){
		matranke[u][v]=1;
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
		cout<<dinh<<"\n";
		for(int i=1;i<=dinh;i++)
		{
			for(int j=1;j<=dinh;j++) 
			{
				cout<<matranke[i][j]<<" ";
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