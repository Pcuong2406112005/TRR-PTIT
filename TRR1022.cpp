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
		int dinh;int canh;
		vector<vector<int>> matrantrongso;
	public:
	Graph(int n,int k):dinh(n),canh(k){
		matrantrongso=vector<vector<int>> (dinh+1,vector<int> (dinh+1));
		for(int i=1;i<=dinh;i++)
		{
			for(int j=1;j<=dinh;j++)
			{
				if(i==j) matrantrongso[i][j]=0;
				else matrantrongso[i][j]=10000;
			}
		}
		for(int i=1;i<=canh;i++)
		{
			int u,v,g;
			cin>>u>>v>>g;
			matrantrongso[u][v]=g;
			
		}
	}
	void display1(){
		for(int i=1;i<=dinh;i++)
		{
			int indeg=0;int outdeg=0;
			for(int j=1;j<=dinh;j++)
			{
				if(matrantrongso[j][i]!=0&&matrantrongso[j][i]!=10000) indeg++;
				if(matrantrongso[i][j]!=0&&matrantrongso[i][j]!=10000) outdeg++;
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
				cout<<matrantrongso[i][j]<<" ";
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