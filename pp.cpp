#include<bits/stdc++.h>
using namespace std;

int priveSeive(int n) //suppose i am passing 24
{
	vector<bool> seive(n+1,true);

	for(int i=2;i*i<=n;i++){
		for(int j = i*i ; j<=n ; j=j+i)
		{
			if(seive[j]){
				seive[j]=false;
			}
		}
	}
	//O(nloglogn)

	if(seive[n]){
		cout<<"Prime";
		return 1;
	}
	else{
		cout<<"Not prime";
		return 0;
	}
	return 0;

}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	priveSeive(n);
}