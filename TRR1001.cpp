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
	for(int i=0;i<n;i++)
	{
		vector<int> temp(n);
		for(int j=0;j<n;j++) 
		{
			cin>>temp[j];
		}
		matranke.push_back(temp);
	}
}
void display(){
	for(int i=0;i<n;i++)
	{
		int res=0;
		for(int j=0;j<n;j++) res+=matranke[i][j];
		cout<<res<<" ";
	}
	cout<<endl;
}
void displayEdge(){
	vector<pair<int,int>> edge;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(matranke[i][j]==1) edge.push_back({i+1,j+1});
		}
	}
	cout<<n<<" "<<edge.size()<<endl;
	for(auto &x:edge)
	{
		cout<<x.first<<" "<<x.second;
		cout<<endl;
	}
}	
};

void solve1()
{
	int n;
	cin>>n;
	Graph g(n);
	g.display();
}

void solve2()
{
	int n;
	cin>>n;
	Graph g(n);
	g.displayEdge();
}

int main()
{
	fileIO();
	int t;cin>>t;
	if(t==1) solve1();
	if(t==2) solve2();	
}
