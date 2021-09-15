

#include <bits/stdc++.h>
using namespace std;

void countFreq(long long int  arr[], long long int  n , long long int  w , long long int  wr)
{
    unordered_map<long long int , long long int > mp;
  
   
    for (long long int  i = 0; i < n; i++)
        mp[arr[i]]++;
  	long long int  y = 0;
    
    for (auto x : mp){

            //cout << x.first << " " << x.second << endl;
            y = x.second/2;

            wr += 2*y*x.first ;
        }
        if(wr>=w){
        	cout<<"YES"<<endl;
        }
        else {
        	cout<<"NO"<<endl;
        }
}

int  main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output1.txt", "w", stdout);
	#endif

	long long int  T;
	cin>>T;
	while(T--)
	{
	    long long int  n , w , wr ;
	   cin>>n>>w>>wr;
	   long long int  a[n];

	   for (long long int  i = 0; i < n; ++i)
	   {
	   	cin>>a[i];
	   }
	   countFreq(a,n,w,wr);

	}
	return 0;
}