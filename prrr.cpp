#include<bits/stdc++.h>
using namespace std;


int LCS(string s1 , string s2 , int n){

	if(n<0){
		return 0;
	}
	int dp[n+1][n+1];

	//initialization 

	for(int i=0; i <=n ; i++){
		for (int j=0; j <=n ; j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
		}
	}

	//actual task
	
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j <=n ; j++){

			if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			}

		}
	}

	for(int i=0; i <=n ; i++){
		for (int j=0; j <=n ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n\n";

	return dp[n][n];

}

int main() {


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

	int i=0,n=5;
	while(i^n){
		cout<<(i&n)<<" ";
		i++;
	}

}