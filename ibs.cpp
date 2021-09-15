#include<bits/stdc++.h>
using namespace std;


int getMaxDiff(int arr[], int n)
{
    int diff = 0;
    if (n == 0) {
        return diff;
    }
 
    int max_so_far = arr[n-1];
    int msfn = n-1;
 
    
    for (int i = n - 2; i >= 0; i--)
    {
        
        if (arr[i] <= max_so_far && msfn > i) {
            max_so_far = arr[i];
            msfn = i;
        }
        
        else {
            diff = max (diff, msfn - i);
        }
    }
 
    // return difference
    return diff;
}
 
int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputtt.txt","w",stdout);
	#endif

		int n;
		cin>>n;

		int y[n];

		for(int i=0;i<n;i++){
			cin>>y[i];
		}

		int mx = getMaxDiff(y, n);

		cout<<mx<<endl;

	return 0;
}
