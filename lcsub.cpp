//Frustration is the key to Success
// %0|%0 never mess with 5 character.

#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	string str1,str2;
	
	cout<<"enter the first string\n";
	cin>>str1;
	cout<<"enter the second string\n";
	cin>>str2;	
	int m=str1.length();
	int n=str2.length();
	int T[m+1][n+1];              //Temporary array to store result
	for(int i=0;i<=m;i++)
		{
		for(int j=0;j<=n;j++)
			{
			if(i==0|| j==0)
				T[i][j]=0;  //initiailising first row and column with 0
			else  if(str1[i-1]==str2[j])
				{
				T[i][j]=T[i-1][j-1]+1;
				}
			else T[i][j]=max(T[i-1][j],T[i][j-1]);
			}
	}
	//for(int i=0;i<n;i++)
	//cout<<T[i]<<" ";
	cout<<"The length of the longest inceasing subsequence is :"<<T[m][n]+1<<endl;
}
