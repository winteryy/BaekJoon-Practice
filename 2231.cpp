#include <iostream>

using namespace std;

int main(){
	int n, temp, sum, constructor=0;
	cin >> n;
	
	for(int i=1; i<n; ++i){
		temp=i;
		sum=0;
		while(temp>0){
			sum+=temp%10;
			temp/=10;
		}
		if(sum+i == n){
			constructor = i;
			break;
		}
	}
	cout << constructor << endl;
	return 0;
}
