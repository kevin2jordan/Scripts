#include<bits/stdc++.h>
using namespace std;
int arr[1000];
void init()
{
for(int i=0;i<100;i++)
arr[i]=i;
}
int root(int x)
{
	while(arr[x]!=x)
	{
		arr[x]=arr[arr[x]];
		x=arr[x];
	}
return x;
}
bool find(int a,int b)
{
	if(root(a)!=root(b))
	return false;
	return true;
}
void unity(int a,int b)
{
	int p=root(a);
	int q=root(b);
	arr[p]=arr[q];
}
int main()
{
vector<pair<int,int> > pi;
int n,x,y;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x>>y;
pi.push_back(make_pair(x,y));
}
init();
for(int i=0;i<pi.size();i++)
{
if(find(pi[i].first,pi[i].second))
{
   cout<<"cycle is found\n";
return 0;
}
unity(pi[i].first,pi[i].second);
}
cout<<"there is no cycle\n";
}


