#include <iostream>

using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int countArr[10000]={0,};
	int n, temp;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> temp;
        ++(countArr[temp-1]);
	}
	for(int i=0; i<10000; ++i){
		for(int j=0; j<countArr[i]; ++j){
		    cout << i+1 << "\n";
		}
	}
	
	return 0;
}
