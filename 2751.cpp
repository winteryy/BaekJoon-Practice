#include <iostream>

using namespace std;

int sortedList[1000000];

void merge(int numList[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	while(i<=mid&&j<=right){
		if(numList[i]<=numList[j]){
			sortedList[k++] = numList[i++];
		}else{
			sortedList[k++] = numList[j++];
		}
	}
	if (i>mid){
		for(l=j; l<=right; l++){
			sortedList[k++] = numList[l];
		}
	}else{		
		for(l=i; l<=mid; l++){
			sortedList[k++] = numList[l];
		}	
	}
	for(l=left; l<=right; l++){
		numList[l] = sortedList[l];
	}
	
}
void mergeSort(int numList[], int l, int r){
	int mid;
	
	if(l<r){
		mid=(l+r)/2;
		mergeSort(numList, l, mid);
		mergeSort(numList, mid+1, r);
		merge(numList, l, mid, r);
	}
}

int main(){
	int n;
	cin >> n;
	
	int numList[n], sortedList[n];
	for(int i=0; i<n; ++i){
		cin >> numList[i];
	}	
	mergeSort(numList, 0, n-1);
	for(int i=0; i<n; ++i){
		cout << numList[i] << "\n";
	}	
	return 0;
}
