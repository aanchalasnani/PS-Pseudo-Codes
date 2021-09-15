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


//first occurence in binary search
int binary_search_1st(int a[] , int n ,int key)
{
	int l = 0 ; 
	int h = n-1;
	int res=-1;
	int mid;
	while(l<=h){

		mid = l + (h-l)/2;

		if(a[mid]==key){

			res = mid;
			h = mid - 1;

		}
		else if(a[mid]>key){
			l = h-1;
		}
		else{
			h = mid+1;
		}
	}
	return res;
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

		int a[] = {1,3,6,13,16,16,16,16,18,22,27,30,34,56,76};
		int n = 15;
		int key = 16;
		int ans=0;
		int l = 0 ; int h = n-1;
		int mid ; 
		while(l<=h){

			//mid = (l+h)/2; 
			mid = l + (h-l)/2;

			if(a[mid]==key){
				ans = mid ;
				break;
			}
			else if(key>a[mid]){
				l = mid+1;
			}
			else{
				h = mid - 1;
			}
		}
		cout<<"position of key : "<<ans;
		//cout<<"first ocuurence : "<<binary_search_1st(a,n,key);

	return 0;
}
