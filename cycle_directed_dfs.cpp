#include<bits/stdc++.h>
using namespace std;
vector<int> vec[100];
bool visited[100];
bool recr[100];
void init()
{
for(int i=0;i<100;i++)
{
visited[i]=false;
recr[i]=false;
}
}
bool cycle(int s)
{
	if(!visited[s])
	{
		visited[s]=true;
		recr[s]=true;
	}
	for(int i=0;i<vec[s].size();i++)
	{
		if(!visited[vec[s][i]] && cycle(vec[s][i]) )
		      return true;
		else if(recr[vec[s][i]])
			return true;
	}
recr[s]=false;
return false;

}

int main()
{
int x,y,nodes,edges;
cin>>nodes>>edges;
for(int i=0;i<edges;i++)
{
	cin>>x>>y;
	vec[x].push_back(y);
}
init();
for(int i=1;i<=nodes;i++)
	if(cycle(i))
	{  
	 cout<<"yes found";
	 return 0;
	}
cout<<"not found\n";

 
}


