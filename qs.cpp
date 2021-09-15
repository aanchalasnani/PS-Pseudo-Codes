#include<bits/stdc++.h>
using namespace std;

void swap(int *x,int *y)
{
	 int temp=*x;
	 *x=*y;
	 *y=temp;
}

int partition(int a[], int l , int h){

	int i=l;
	int j=h;

	int pivot = a[l];

	do{
		do{i++;}while(a[i]<=pivot);
		do{j--;}while(a[j]>pivot);
		
		if(i<j)
			swap(&a[i],&a[j]);
	}
	while(i<j);
	swap(&a[l],&a[j]);
	return j;
}

void quicksort(int a[] , int l , int h){

	int mid;

	if(l<h){
		mid = partition(a,l,h);
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

	quicksort(a,0,8);

	cout<<"Sorted Array : ";
	for(int i=0;i<8;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";

	return 0;
}
