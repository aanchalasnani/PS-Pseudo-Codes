#include<bits/stdc++.h>
using namespace std;

using namespace std;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

ll isPrime(ll n){
	int flag=0; //the number is prime
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			flag = 1; //the number is composite
		}
	}
	return ((flag==1)?0:1);
}

void SeiveOfErosthenes(){
	int n = 50;
	vector<bool> seive(n+5,true);

	for(int i = 2 ; i*i <= n ; i++){

		if(seive[i]){
			for(int j = i*i ; j <= n ; j=j+i){
				seive[j] = false;
			}
		}
	}
	// T.C ==> n(log(logn))

	//print all primes available in seive

	for(int i = 2 ; i<=n ; i++){
		if(seive[i]){
			cout<<i<<endl;
		}
	}
	// int temp = 25;
	// if(seive[temp]){
	// 	cout<<temp<<" is Prime"<<endl;
	// }
	// else{
	// 	cout<<temp<<" is composite"<<endl;
	// }

}

void primeFact(ll n ){
	int cnt=0;
	int root = int(sqrt(n));
	//cout<<"root : "<<root<<endl;
	//cout<<" ==> "<<sqrt(n)<<" ";
	for(int i = 2 ; i<=root; i++){

		if(n%i==0){
			cnt=0;
			while(n%i==0){
				n/=i; //n=n/i;
				cnt++;
			}
			cout<<i<<'^'<<cnt<<" ";
		}
		
	}
	if(n>1){
		cout<<n<<"^"<<1;
	}
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
		// for finding prime..........................
		// int t;
		// cin>>t;

		// while(t--){
		// 	int n;
		// 	cin>>n;

		// 	cout<<n<<" is " <<(isPrime(n)?"PRIME":"COMPOSITE")<<endl;
		// }

		// for prime factorization.....................
		// int n; cin>>n;
		// primeFact(n);

		//for  SeiveOfErosthenes().....................
		SeiveOfErosthenes();

	return 0;
}
