#include<bits/stdc++.h>
using namespace std;


// int findPivot(int a[] , int low , int high){

// 	if(high<low){
// 		return -1;
// 	}
// 	if(low==high){
// 		return low;
// 	}
// 	int mid = (high + low)/2 ;

// 	if(mid < high && a[mid] > a[mid + 1]){
// 		return mid;
// 	}
// 	if(mid > low && a[mid] < a[mid - 1]){
// 		return (mid-1);
// 	}
// 	if(a[low]>=a[mid]){
// 		return findPivot(a,low,mid-1);
// 	}
// 	return findPivot(a,mid+1,high);

// }

int findPivot(int a[], int low , int high){

	for(int i=low+1 ; i < high-1 ; i++){
		if((a[i-1]<a[i] && a[i]>a[i+1])  || (a[i-1]>a[i] && a[i]<a[i+1])){
			return i;
		}
	}
	return 0;
	
}

int main()
{


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int a[] = {4,5,6,7,0,1,2,3};
		int key = 5;

		int pivot = findPivot(a,0,7);
		cout<<pivot<<endl;

}