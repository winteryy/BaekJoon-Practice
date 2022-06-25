#include <iostream>

using namespace std;

class Point{
public:
	int x;
	int y;
	
	bool operator < (Point& p){
		if (y < p.y){
			return true;
		}else if(y==p.y && x<p.x){
			return true;
		}
		return false;
	}
	
	Point& operator = (Point& p){
		x = p.x;
		y = p.y;
		return *this;
	}
};

Point sortedList[100001];

void merge(Point pList[], int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;
	
	while(i<=mid&&j<=right){
		if(pList[i]<pList[j]){
			sortedList[k++] = pList[i++];
		}else{
			sortedList[k++] = pList[j++];
		}
	}
	if (i>mid){
		for(l=j; l<=right; l++){
			sortedList[k++] = pList[l];
		}
	}else{		
		for(l=i; l<=mid; l++){
			sortedList[k++] = pList[l];
		}	
	}
	for(l=left; l<=right; l++){
		pList[l] = sortedList[l];
	}
	
}
void mergeSort(Point pList[], int l, int r){
	int mid;
	
	if(l<r){
		mid=(l+r)/2;
		mergeSort(pList, l, mid);
		mergeSort(pList, mid+1, r);
		merge(pList, l, mid, r);
	}
}

int main(){
	int n, ind;
	cin>>n;
	Point pointArr[n];
	
	for(int i=0; i<n; ++i){
		cin >> pointArr[i].x >> pointArr[i].y;
	}
	
	mergeSort(pointArr, 0, n-1);
	for(int i=0; i<n; ++i){
		cout << pointArr[i].x << " " << pointArr[i].y << "\n";
	}		
		
	return 0;
}
