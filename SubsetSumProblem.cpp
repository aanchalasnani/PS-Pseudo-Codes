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



int CountSubsetSum(int arr[] , int sum , int n){

	int dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=sum;i++){
		dp[0][i]=0;
	}

	for(int i = 1; i <=n ; i++){
		for(int j=1; j<=sum ;j++){
			if(arr[i-1]<=j){
				dp[i][j]= ((dp[i-1][j-arr[i-1]]) + (dp[i-1][j])) ;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(int i = 0 ; i <=n ; i++){
		for(int j=0;j<=sum ; j++){

			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"n : "<<n<<" sum : "<<sum<<endl;
	return dp[n][sum];

}




bool MinimumSubsetSum(int arr[] , int sum , int n){

	int dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=sum;i++){
		dp[0][i]=0;
	}

	for(int i = 1; i <=n ; i++){
		for(int j=1; j<=sum ;j++){
			if(arr[i-1]<=j){
				dp[i][j]= ((dp[i-1][j-arr[i-1]]) || (dp[i-1][j])) ;
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	for(int i = 0 ; i <=n ; i++){
		for(int j=0;j<=sum ; j++){

			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}

	vector<int> temp;
	//int a;
	for(int j=0;j<=(sum/2) ; j++){

			 if(dp[n][j]){
			 	temp.push_back(j);
			 }
			//temp.push_back(a);

	}
	cout<<"\n\n";
	for(int i = 0 ; i < temp.size() ; i++){
		cout<<temp[i]<<" ";
	}

	int mn=INT_MAX;
	int ans=INT_MAX;
	for(int i = 0 ; i < temp.size() ; i++){

		ans = min(ans,(sum-2*temp[i]));

	}
	cout<<"\nAnswer ==> "<<ans;
	cout<<"\n";
	//cout<<"n : "<<n<<" sum : "<<sum<<endl;
	return dp[n][sum];

}


bool EqualSumPartition(int arr[] , int n){

	int sm=0;
	for(int i = 0 ; i < n ; i ++){
		sm+=arr[i];
	}

	if(sm%2!=0){
		return false;
	}
	else{
		return SubsetSum(arr,sm/2,n);
	}
}



int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int arr[] = {2,3,5,6,8,10}; //we are excepting a o/p of 3
		int a[] = {1,2,7};
		int m=3;
		//int val=11;
		int sum = 10;
		
		int n=6;
		//SubsetSum(a,sum,m);
		MinimumSubsetSum(a,sum,m);
		//cout<<CountSubsetSum(arr,sum,n); //this return count of subset sum with a given sum

		// if(EqualSumPartition(arr,n))
		// {
		// 	cout<<"Yes Equal Sum Partion is Possible\n";
		// }
		// else
		// {
		// 	cout<<"Equal sum Partion is not Possible\n";
		// }

	return 0;
}
