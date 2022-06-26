#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> numV(n);
	
	for(int i=0; i<n; ++i){
		cin >> numV[i];
	}
	vector<int> sortV(numV);
	sort(sortV.begin(), sortV.end());
	sortV.erase(unique(sortV.begin(), sortV.end()), sortV.end());
	
	for(int i=0; i<n; ++i){
		cout << lower_bound(sortV.begin(), sortV.end(), numV[i]) - sortV.begin() << ' ';
	}
	
	return 0;
}
