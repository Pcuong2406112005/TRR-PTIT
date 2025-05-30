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
	Graph(int n):dinh(n),canh(0){
		matrantrongso=vector<vector<int>> (dinh+1,vector<int> (dinh+1));
		for(int i=1;i<=dinh;i++)
		{
			for(int j=1;j<=dinh;j++)
			{
				cin>>matrantrongso[i][j];
				if(matrantrongso[i][j]!=0&&matrantrongso[i][j]!=10000) canh++;
			}
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
		cout<<dinh<<" "<<canh<<"\n";
		for(int i=1;i<=dinh;i++)
		{
			for(int j=1;j<=dinh;j++)
			{
				if(matrantrongso[i][j]!=0&&matrantrongso[i][j]!=10000) cout<<i<<" "<<j<<" "<<matrantrongso[i][j]<<"\n";
			}
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
