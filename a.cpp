#include <bits/stdc++.h>
using namespace std;

map<pair<long long,long long>,long long> mp;
int BFS(int x, int y, int arr[])
{
	int ans=1;
	if(mp.find({x-1,y})!=mp.end()&&!arr[mp[{x-1,y}]])
  {
		arr[mp[{x-1,y}]]=1;
		ans+=BFS(x-1,y,arr);
	}
	if(mp.find({x+1,y})!=mp.end()&&!arr[mp[{x+1,y}]])
  {
		arr[mp[{x+1,y}]]=1;
		ans+=BFS(x+1,y,arr);
	}
	if(mp.find({x,y-1})!=mp.end()&&!arr[mp[{x,y-1}]])
  {
		arr[mp[{x,y-1}]]=1;
		ans+=BFS(x,y-1,arr);
	}
	if(mp.find({x,y+1})!=mp.end()&&!arr[mp[{x,y+1}]])
  {
		arr[mp[{x,y+1}]]=1;
		ans+=BFS(x,y+1,arr);
	}
	return ans;
}

int main()
{
	long long int n,m;
	cin>>m>>n;
	long long int k;
	cin>>k;
	for(long long int i=0;i<k;i++)
  {
		int x,y;
		cin>>x>>y;
		mp[{x,y}]=i;
	}
	int arr[k]={0},j=0,out=0;
	for(auto i:mp){
		arr[j]=1;
		if(!arr[j]) out=max(out,BFS(i.first.first,i.first.second,arr));
		j++;
	}
	cout<<out;
	return 0;
}
