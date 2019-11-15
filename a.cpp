#include <bits/stdc++.h>
using namespace std;
long long mod=1e9+7;

int find(long long arr[], long long x){
	if(x!=arr[x]){
		arr[x]=find(arr,arr[x]);
	}
	return arr[x];
}

void prodcal(long long arr[],long long ranks[],long long a,long long b)
{
	int x=find(arr,a);
	int y=find(arr,b);
	if(x!=y)
  {
		if(ranks[x]<ranks[y]) swap(x,y);
		arr[y]=x;
		if(ranks[x]==ranks[y])
    {
			ranks[x]++;
		}
	}
}

int main()
{
	int v,e;
	cin>>v>>e;
	vector<pair<long long,pair < long long, long long >>>g;
	long long x,y,w;
	for(int i=0;i<e;i++)
  {
		cin>>x>>y>>w;
		g.push_back({w,{x,y}});
	}
	sort(g.begin(),g.end());
	long long arr[v+1],ranks[v+1];
	long long prod=1;
	for(int i=0;i<v+1;i++)
  {
		arr[i]=i;
		ranks[i]=0;
	}
	for(int i=g.size()-1;i>=0;i--)
  {
		int rx=find(arr,g[i].second.first),ry=find(arr,g[i].second.second);
		if(rx!=ry){
			prod=(prod*(g[i].first%mod)%mod);
			prod%=mod;
			prodcal(arr,ranks,g[i].second.first,g[i].second.second);
		}
	}
	prod%=mod;
	cout<<prod;
	return 0;
}
