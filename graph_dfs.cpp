#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000];
bool visited[1000];
void initialise()
{
for(int i=0;i<1000;i++)
visited[i]=false;
}
void bfs(int s)
{
queue<int> q;
q.push(s);
visited[s]=true;

while(!q.empty())
{
int p=q.front();
cout<<p<<endl;
q.pop();
for(int i=0;i<vec[p].size();i++)
{
if(!visited[vec[p][i]])
{
q.push(vec[p][i]);
visited[vec[p][i]]=true;
}
}
}
}
void dfs(int s)
{
visited[s]=true;
cout<<s<<endl;
for(int i=0;i<vec[s].size();i++)
if(!visited[vec[s][i]])
dfs(vec[s][i]);
}
int main()
{
int x,y,nodes,edges,cnt=0;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
cin>>x>>y;
vec[x].push_back(y);
//vec[y].push_back(x);
}
initialise();
/*for(int i=1;i<=nodes;i++)
if(!visited[i])
{bfs(i);
//cnt++;
}*/
bfs(2);
//cout<<"connected components "<<cnt<<endl;
}

