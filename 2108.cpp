#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int arr[8001]={0,}; //arr[0]:-4000 arr[4000]:0 arr[8000]:4000
	int n, sum=0, temp, ind=-1, indStack=0;
	cin >> n;
		
	for(int i=0; i<n; ++i){
		cin >> temp;
		sum += temp;
		++(arr[temp+4000]);
	}
	
	cout << floor((sum/(float)n)+0.5) << "\n";
	
	temp = 0;
	for(int i=0; i<8001; ++i){
		temp+=arr[i];
		if (temp > n/2){
			cout << i-4000 << "\n";
			break;
		}
	}
	
	temp = 0;
	for(int i=0; i<8001; ++i){
		if (arr[i]>temp){
			temp = arr[i];
			ind = i;
			indStack = 1;
		}else if(arr[i]==temp && indStack == 1){
			temp = arr[i];
			ind = i;
			indStack = 2;			
		}
	}
	cout << ind-4000 << "\n";
	
	for(int i=0; i<8001; ++i){
		if(arr[i]!=0){
			temp = i;
			break;
		}
	}
	for(int i=8000; i>=0; --i){
		if(arr[i]!=0){
			cout << i-temp << "\n";
			break;
		}		
	}
	return 0;
}
