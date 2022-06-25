#include <iostream>
#include <string>

using namespace std;

string sortedList[20000];

void merge(string strList[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	while(i<=mid&&j<=right){
		if(strList[i].size() < strList[j].size()){
			sortedList[k++] = strList[i++];
		}
		else if(strList[i].size()==strList[j].size() && strList[i] < strList[j]){
			sortedList[k++] = strList[i++];
		}
		else{
			sortedList[k++] = strList[j++];
		}
	}
	if (i>mid){
		for(l=j; l<=right; l++){
			sortedList[k++] = strList[l];
		}
	}else{		
		for(l=i; l<=mid; l++){
			sortedList[k++] = strList[l];
		}	
	}
	for(l=left; l<=right; l++){
		strList[l] = sortedList[l];
	}
	
}
void mergeSort(string strList[], int l, int r){
	int mid;
	
	if(l<r){
		mid=(l+r)/2;
		mergeSort(strList, l, mid);
		mergeSort(strList, mid+1, r);
		merge(strList, l, mid, r);
	}
}

int main(){
	int n, ind;
	cin>>n;
	string strArr[n];
	
	for(int i=0; i<n; ++i){
		cin >> strArr[i];
	}
	
	mergeSort(strArr, 0, n-1);
	for(int i=0; i<n; ++i){
		if(i!=0 && strArr[i].compare(strArr[i-1])==0)
			continue;
			
		cout << strArr[i] << "\n";
	}		
		
	return 0;
}
