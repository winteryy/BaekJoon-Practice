#include <iostream>
#include <string>

using namespace std;
class Member{
public:	
	int age;
	string name;
	
	bool operator <=(Member& m){
		return age<=m.age;
	}
	Member& operator =(Member& m){
		age = m.age;
		name = m.name;
		return *this;
	}
};
Member sortedList[100001];

void merge(Member mList[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	while(i<=mid&&j<=right){
		if(mList[i]<=mList[j]){
			sortedList[k++] = mList[i++];
		}else{
			sortedList[k++] = mList[j++];
		}
	}
	if (i>mid){
		for(l=j; l<=right; l++){
			sortedList[k++] = mList[l];
		}
	}else{		
		for(l=i; l<=mid; l++){
			sortedList[k++] = mList[l];
		}	
	}
	for(l=left; l<=right; l++){
		mList[l] = sortedList[l];
	}
	
}
void mergeSort(Member mList[], int l, int r){
	int mid;
	
	if(l<r){
		mid=(l+r)/2;
		mergeSort(mList, l, mid);
		mergeSort(mList, mid+1, r);
		merge(mList, l, mid, r);
	}
}

int main(){
	int n;
	cin >> n;
	Member mList[n];

	for(int i=0; i<n; ++i){
		cin >> mList[i].age >> mList[i].name;
	}

	mergeSort(mList, 0, n-1);
	for(int i=0; i<n; ++i){
		cout << mList[i].age << " " << mList[i].name << '\n';
	}
		
	return 0;
}
