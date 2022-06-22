#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int origin, int target, int n){
	if (n==1){
		cout << origin << " " << target << "\n";
	}else{
		hanoi(origin, 6-origin-target, n-1);
		cout << origin << " " << target << "\n";
		hanoi(6-origin-target, target, n-1);
	}
}

int main(){
	int num;
	cin >> num;
	cout <<	(int)pow(2, num)-1 << "\n";
	hanoi(1, 3, num);
	return 0;
}
