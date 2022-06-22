#include <iostream>

using namespace std;

bool isFNum(int n){
	int six=0;
	while(n>0){
		if(n%10==6){
			six+=1;
		}
		if(six>=3){
			return true;
		}
		if(n%10!=6){
			six=0;
		}
		n/=10;
	}
	return false;
}

int main(){
	int n, num=665, stack=0;
	cin >> n;

	while(stack!=n){
		num++;
		if(isFNum(num)){
			stack++;
		}
	}
	cout << num << endl;
	return 0;
}
