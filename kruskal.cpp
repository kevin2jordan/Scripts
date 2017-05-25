#include<bits/stdc++.h>
using namespace std;
pair<long long , pair<int,int> > adj[1000000];
int id[1000000],nodes,edges;
void init()
{
for(int i=0;i<1000000;i++)
id[i]=i;
}
int root(int x)
{
while(id[x]!=x)
{
id[x]= id[id[x]];
x=id[x];
}
return x;
}
void unity(int a,int b)
{
int x= root(a);
int y= root(b);
id[x]=id[y];
}
int mst(pair<long long, pair<int,int> >p[])
{
int x,y;
long long cost,mincost=0;
for(int i=0;i<edges;i++)
{
x=p[i].second.first;
y=p[i].second.second;
cost=p[i].first;
if(root(x) != root(y))
{
mincost +=cost;
unity(x,y);
}
}
return mincost;
}

int main()
{
int t;
cin>>t;
while(t--)
{
int x,y,cost;
cin>>cost>>nodes>>edges;
long long weight  , mincost;
init();
for(int i=0;i<edges;i++)
{
cin>>x>>y>>weight;
adj[i] = make_pair(weight, make_pair(x,y));
}
sort(adj , adj + edges);
mincost = mst(adj);
cout<< mincost * cost<<endl;
}
return 0;
}
