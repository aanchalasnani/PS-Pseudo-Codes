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

int knapsack(int wt[] , int val[] , int cap , int n){

	int dp[cap+1][n+1];

	//initialization: 
	for(int i=0 ; i <= cap ; i++){
		for(int j=0 ; j<=n ; j++){

			if(i==0 || j==0){
				dp[i][j]=0;
			}
		}
	}
	for(int i=1; i <= cap ; i++){
		for(int j=1 ; j<=n ; j++){

			if(wt[j-1]<=i){
				dp[i][j] = max((val[j-1]+dp[i-wt[j-1]][j-1]),(dp[i][j-1]));
			}
			else{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	for(int i=0 ; i <= cap ; i ++){
		for(int j=0 ; j<=n ; j++){

			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}


	return dp[cap][n];
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

		int wt[] = { 1,3,4,7 };
		int val[] = { 2,4,6,9 };

		int cap = 8;

		cout<<knapsack(wt,val,cap,4)<<endl;


	return 0;
}
