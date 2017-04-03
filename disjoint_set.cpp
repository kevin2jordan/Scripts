#include<bits/stdc++.h>
using namespace std;
int arr[10];
void init()
{
for(int i=0;i<10;i++)
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
int m,a,b;
cin>>m;
init();
for(int i=0;i<m;i++)
{
cin>>a>>b;
unity(a,b);
}
for(int i=0;i<10;i++)
cout<<arr[i]<<" ";
}

