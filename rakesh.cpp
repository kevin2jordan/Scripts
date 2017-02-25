#include<bits/stdc++.h>
using namespace std;

int fun(int W, int n, int val[])
{
	
	int T[W+1];
	memset(T, 0, sizeof T);

	int ans = 0;
	for (int i=0; i<=W; i++)
	for (int j=0; j<n; j++)
		if (val[j] <= i)
			T[i] = max(T[i], T[i-val[j]]+1);

	return T[W];
}
int main()
{
	int W,n;
	cin>>n;
	int val[n];
	for(int i=0;i<n;i++)
	cin>>val[i];
	cin>>W;
	cout << fun(W, n, val)<<endl;

	return 0;
}

