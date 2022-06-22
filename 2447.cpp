#include <iostream>
#include <string>

using namespace std;

void printStar(string* y, int n){
	if (n==3){
		*y += "***";
		*(y+1) += "* *";
		*(y+2) += "***";
	}else{
		for(int i=0; i<3; ++i){
			printStar(y, n/3);
		}		
		printStar(y+(n/3), n/3);
		for(int i=0; i<n/3; ++i){
			for(int j=0; j<n/3; ++j){				
				*(y+(n/3)+j) += " ";
			}
		}
		printStar(y+(n/3), n/3);
		for(int i=0; i<3; ++i){
			printStar(y+(2*n/3), n/3);
		}
	}
}

int main(){
	int n;
	cin >> n;
	string arr[n]={""};
	
	printStar(&arr[0], n);
	
	for(int i=0; i<n; ++i){
		cout << arr[i] << endl;
	}
	return 0;
}
