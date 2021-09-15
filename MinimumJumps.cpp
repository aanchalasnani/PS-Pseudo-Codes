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


class Solution 
{
	public :
		int minJumps(int a[] , int n){
			

			int steps = a[0];
			int Reach = a[0];
			int jumps = 1; 

			int j=0;

			if(arr[0]==0){
            	return -1;
        	}
        	if(n<=1){
            	return 0;
       		}
			for (int i = 1; i < n; ++i)
			{
				if(i==n-1) //last element
				{
					return jumps;
				}
				Reach = max(Reach , a[i]+i); //maximum index that we can reach

				steps--;

				if(steps==0){
					jumps++;
					if(i>Reach){return -1;}
					steps = Reach-i;
				}


			}
			return -1;
		}
};

/* 
	DRY RUN :

	initially : 
	steps : 1 , Reach : 1 ,Jump = 1;

	Inside LOOP :
	i!= n-1 , Reach = max(1,3+1) = 4 , steps--; steps= 0 , Jumps=2 , steps = 4 - 1 =3 ;
	i!=n-1 , Reach = max(4,5+2) = 7 , steps--; steps = 2 ,
	i!=n-1 , Reach = max(7,8+3) = 11, steps--; steps = 1;
	i!=n-1 , Reach = max(11,13) = 13 , steps--; steps = 0; Jumps=3 , i=4 , steps = 13-4 = 9;


*/



int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
	
	int t;
	cin>>t;

	while(t--){
		int n,i,j;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		Solution obj;
		cout<<obj.minJumps(arr,n)<<endl;
	}

	return 0;
}

/*

Given an array of integers where each element represents the max
number of steps that can be made forward from that element.
Write a function to return the minimum number of jumps to
reach the end of the array (starting from the first element). 
If an element is 0, then we cannot move through that element.
If we can't reach the end, return -1.



Input:  arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}

Output: 3 (1-> 3 -> 8 -> 9)

Explanation: Jump from 1st element to 

2nd element as there is only 1 step, 

now there are three options 5, 8 or 9. 

If 8 or 9 is chosen then the end node 9 

can be reached. So 3 jumps are made.
*/