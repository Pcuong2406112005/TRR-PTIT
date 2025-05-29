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
vector<vector<int>> matranke;
public:
Graph(int n):n(n){
	matranke.resize(n);
	for(int i=0;i<n;i++)
	{
		matranke[i].resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>matranke[i][j];
		}
	}
}
void display1(){
	for(int i=0;i<n;i++)
	{
		int res=0;
		for(int j=0;j<n;j++)
		{
			res+=matranke[i][j];
		}
		cout<<res<<" ";
	}
	cout<<"\n";
}
void display2(){
	vector<pair<int,int>> edges;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(matranke[i][j]) edges.push_back({i,j});
		}
	}
	vector<vector<int>> matranlienthuoc(n,vector<int> (edges.size(),0));
	for(int i=0;i<edges.size();i++)
	{
		matranlienthuoc[edges[i].first][i]=1;
		matranlienthuoc[edges[i].second][i]=1;
	}
	cout<<n<<" "<<edges.size()<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			cout<<matranlienthuoc[i][j]<<" ";
		}
		cout<<endl;
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
	int t;cin>>t; solve(t);
}
