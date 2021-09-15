#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

void Avg_Height() {

	int n,a;
	cin>>n;

	std::vector<int > v1;
	std::vector<int > v2;
	std::vector<int > v3;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v1.push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		if(v1[i]%2==1){
			v2.push_back(v1[i]);
		}
		else {
			v3.push_back(v1[i]);
		}
	}
	v2.insert( v2.end(), v3.begin(), v3.end() );

	for (int i = 0; i < n; ++i)
	{
		cout<<v1[i]<<" ";
	}
	cout<<endl;
	
	
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

		


	int t;cin>>t;
	while(t--)
	Avg_Height();


	  	return 0;
}
