#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool Cyclic(int s,bool visited[] , int parent)
{
 	visited[s]=true;
	vector<int>::iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!visited[*it])
			{
				if( Cyclic(*it,visited,s) )
					return true;
			}
			else if(*it != parent)
				return true;
		}
return false;
}

bool check(int nodes)
{
bool *visited = new bool[nodes];
memset(visited,false,sizeof(visited));
for(int i=0;i<nodes;i++)
	if(!visited[i])
	      if( Cyclic(i,visited,-1) )
			return true;
return false;
}
int main()
{
int nodes,edges,x,y;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
if(check(nodes))
cout<<"Yes found a cycle\n";
else cout<<"No such a cycle doesn'y exist\n";

return 0;
}
