#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

using namespace std;



int main()
{


	#ifndef ONLINE_JUDGEB
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--)	
	{
				int n;
				cin>>n;
				
				priority_queue<pair<int,int>> q;
				int a[n];
				

				for (int i = 0; i < n; ++i)
				{
					cin>>a[i];
					q.push(make_pair(a[i],i));
				}

				while(!q.empty()){
					pair<int , int > paiir = q.top();
					cout<<paiir.second+1<<" ";
					q.pop();
				}
				cout<<endl;
				
	}	
	return 0;
}
