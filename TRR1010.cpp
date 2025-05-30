#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void fileIO(){
	freopen("DT.INP","r",stdin);
	freopen("DT.OUT","w",stdout);
}

class Graph{
	private:
		int n;
		vector<vector<int>> matrantrongso;
	public:
	Graph(int n):n(n) {
		matrantrongso=vector<vector<int>> (n+1,vector<int> (n+1));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>matrantrongso[i][j];
			}
		}
	}
	void display1(){
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				if(matrantrongso[i][j]!=0&&matrantrongso[i][j]!=10000) res++;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	void display2(){
		vector<pair<pair<int,int>,int>> danhsachcanh;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(matrantrongso[i][j]!=10000&&matrantrongso[i][j]!=0) danhsachcanh.push_back({{i,j},matrantrongso[i][j]});
			}
		}
		cout<<n<<" "<<danhsachcanh.size()<<"\n";
		for(auto &x:danhsachcanh)
		{
			cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
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