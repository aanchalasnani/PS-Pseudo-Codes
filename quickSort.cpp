#include<bits/stdc++.h>
using namespace std;

void swap(int &a1, int &a2){
	int temp = a1;
	a1 = a2;
	a2 = temp;
}

int partition(int a[], int l , int h){

	if(l>h){
		return -1;
	}
	int i=l;
	int j=h;

	int pivot = a[l];

	do{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		
		if(i<j)
			swap(a[i],a[j]);
	}
	while(i<j);
	swap(pivot,a[j]);
	return j;
}

void quicksort(int a[] , int l , int h){

	if(l<h){
		int mid = partition(a,l,h);
		quicksort(a,l,mid);
		quicksort(a,mid+1,h);
	}
}


int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

	int a[] = {4,2,15,6,13,57,1,9};

	quicksort(a,0,7);

	cout<<"Sorted Array : ";
	for(int i=0;i<7;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	return 0;
}
