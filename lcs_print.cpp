#include<bits/stdc++.h>
using namespace std;

void lcs( string str1, string str2)
{
int m = str1.length();
int n = str2.length();
int T[m+1][n+1];
// This part is to caluculate the length of the longest common subsequence
for (int i=0; i<=m; i++)
{
	for (int j=0; j<=n; j++)
	{
	if (i == 0 || j == 0)
		T[i][j] = 0;
	else if (str1[i-1] == str2[j-1])
		T[i][j] = T[i-1][j-1] + 1;
	else
		T[i][j] = max(T[i-1][j], T[i][j-1]);
	}
}
//this part is to print the LCS.
int index = T[m][n]; //store the length of LCS.

char lcs[index+1];
lcs[index] = '\0'; //mark the end of string

int i = m, j = n;
while (i > 0 && j > 0)
{
	
	if (str1[i-1] == str2[j-1])
	{
		lcs[index-1] = str1[i-1]; 
		i--; j--; index--;	 
	}

	else if (T[i-1][j] > T[i][j-1])
		i--;
	else
		j--;
}

cout  << lcs << endl;
}
int main()
{
string X,Y;
cin>>X>>Y;

lcs(X, Y);
return 0;
}

