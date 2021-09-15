#include<bits/stdc++.h>
using namespace std;

using namespace std;


typedef long long ll;

#define MOD 1000000007


ll power(ll N , ll M){

	ll out = 1;
	while(M){
		if(M%2) //if M is odd
		{
			out = (out*N)%MOD;
		}
		
		N = (N*N)%MOD;
		M = M>>1;
	}
	return out;
}


void CODECHEF() {
	ll N,M;
	cin>>N>>M;
	ll temp = power(2,N) - 1;
	ll ans = power(temp,M);
	cout<<ans<<endl;

}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
		int t;
		cin>>t;
		while(t--){
			CODECHEF();
		}

	return 0;
}
