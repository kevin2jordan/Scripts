#include<bits/stdc++.h>
using namespace std;
int minCoins(int val[], int n, int W)
{
	int T[W+1];
	
	
	T[0]=0;
	for(int i=1;i<=W;i++)
	T[i]=INT_MAX;
	for (int i=1; i<=W; i++)
	for (int j=0; j<n; j++)
		if (val[j] <= i)
		{
		
              if (T[i-val[j]] != INT_MAX && T[i-val[j]] + 1 < T[i])
                  T[i] = T[i-val[j]] + 1;

	}
//for(int i=1;i<=W;i++)
//cout<<T[i]<<" ";
	return T[W];

}

int main()
{
	int n;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++)
	cin>>coins[i];
	
	int V ;
	cin>>V;
	cout << "Minimum coins required is "
		<< minCoins(coins, n, V)<<endl;
	return 0;
}

