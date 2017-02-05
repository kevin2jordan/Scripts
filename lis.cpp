//Frustration is the key to Success
// %0|%0 never mess with 5 character.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	cout<<"enter the number of elements\n";
	cin>>n;
	int arr[n];
	cout<<"enter the elements of the array\n";
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int T[n];
	for(int i=0;i<n;i++)
	T[i]=1;

	for(int i=1;i<n;i++)
		{
		for(int j=0;j<i;j++)
			{
			  if(arr[i] > arr[j])
				{
				T[i]=max(T[i],T[j]+1);
				ans=max(ans,T[i]);
				}
			}
	}
	//for(int i=0;i<n;i++)
	//cout<<T[i]<<" ";
	cout<<"The length of the longest inceasing subsequence is :"<< ans<<endl;
}
