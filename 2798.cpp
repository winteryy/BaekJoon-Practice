#include <iostream>

using namespace std;

int main(){
	int n, m, sum=0;
	cin >> n >> m;
	int card[n], select[3]={0,0,0};
	for(int i=0; i<n; ++i){
		cin >> card[i]; 
	}
	for(int i=0; i<n-2; ++i){
		for(int j=i+1; j<n-1; ++j){
			for(int k=j+1; k<n; ++k){
				if (card[i]+card[j]+card[k]<=m && card[i]+card[j]+card[k]>sum){
					select[0] = card[i];
					select[1] = card[j];
					select[2] = card[k];
					sum = card[i]+card[j]+card[k];
				}
			}
		}
	}

	cout << select[0]+select[1]+select[2] << endl;
	return 0;
}
