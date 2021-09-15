#include<bits/stdc++.h>
using namespace std;



typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define loop(i, a, b) for(int i = (a); i < (b); ++i)
#define loop0(i, a) loop(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

// //int cnt=0;
// int LCS(string s1, string s2, int n ,int m) //recursive lcs
// {
// 	//base case
// 	if(m==0 || n==0){
// 		return 0;
// 	}
	
// 	if(s1[n-1]==s2[m-1]){
// 		return 1+LCS(s1,s2,n-1,m-1);
// 	}
// 	else{

// 		return max(LCS(s1,s2,n,m-1) , LCS(s1,s2,n-1,m));
// 	}
// }

// int a[10][10];

// int LCS(string s1, string s2, int n ,int m) //recursive lcs
// {

// 	//base case
// 	if(m==0 || n==0){
// 		return 0;
// 	}
	
// 	if(s1[n-1]==s2[m-1]){
// 		if(a[n][m]!=0){
// 			return a[n][m];
// 		}
// 		return a[n][m] = (1+LCS(s1,s2,n-1,m-1));
// 	}
// 	else{
// 		return max(LCS(s1,s2,n,m-1) , LCS(s1,s2,n-1,m));
// 	}
// }


int LCS(string s1,string s2 , int n , int m){

	int dp[n+1][m+1];

	for(int i = 0 ; i<=n ; i++){
		for(int j = 0 ; j<=m ; j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
		}
	}
	for(int i = 1;i<=n ; i++){
		for(int j = 1 ; j <=m ; j ++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else {
				dp[i][j] = max( dp[i][j-1] , dp[i-1][j] );
			}
		}
	}

	for(int i = 0 ; i<=n ; i++){
		for(int j = 0 ; j<=m ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}

	cout<<"\n\n";

	int i = n ; int  j =  m;

	while(i!=0 || j!=0){

		if(s1[i-1] == s2 [j-1]){

			if(dp[i-1][j] == dp[i][j-1])
			{
				cout<<s1[i-1]<<" ";
				i--;
				j--;
			}
			
		}
		else{

				if(dp[i][j-1]>dp[i-1][j]){
					j--;
				}
				else{
					i--;
				}
			}

	}


	return dp[n][m];

}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

		string s1,s2;
		cin>>s1>>s2;

		int n = s1.length();
		int m = s2.length();

		//int a[n][m];

		// for(int i = 0 ; i< n ; i++){
		// 	for(int j = 0; j< m ; j++){
		// 		a[i][j]=0;
		// 	}
		// }

		cout<<LCS(s1,s2,n,m)<<"\n";



	return 0;
}
