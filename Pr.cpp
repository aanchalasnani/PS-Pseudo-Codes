#include<bits/stdc++.h>
using namespace std;

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

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)


void solve() 
{
	int k;
	cin>>k;
	int flag = 0;

		for(int i = 0 ; i < k ; i ++){

			string s;
			cin>>s;
			int small=0 ; 
			int big = 0;
			int other = 0;
			
			for(int j = 0 ; j < s.size() ; j++){
				if(s[j] >= 'a' && s[j] <= 'm'){
					small++;

				}
				else if(s[j] >= 'N' && s[j] <= 'Z'){
					big++;
				}
				else {
					other++;
				}
			}
			
			//cout<<"Small : "<<small << "BIG : "<<big<<endl;
			if((small>0 && big>0) || (other>0) )
			{
				//cout<<"NO"<<endl;
				flag = 1;
				//break;
			}	
		}
		if(flag == 0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
}
int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--) {

		solve();
		
	}

	return 0;
}
