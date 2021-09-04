

#include <bits/stdc++.h>
using namespace std;

void countFreq(long long int  arr[], long long int  n , long long int  w , long long int  wr)
{
    unordered_map<long long int , long long int > mp;
  
    // Traverse through array elements and
    // count frequencies
    for (long long int  i = 0; i < n; i++)
        mp[arr[i]]++;
  	long long int  y = 0;
    // Traverse through map and prlong long int  frequencies
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

	int n = 8;
	int a[] = {3,2,5,9,4,2,8,1};

	sort(a,a+n/2);
	sort(a+n/2+1 , a+n , greater<int>());

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}