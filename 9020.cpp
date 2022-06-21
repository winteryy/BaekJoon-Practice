#include <iostream>

using namespace std;

bool isPrime(int num){
	if (num==1){
		return false;
	}else if(num==2||num==3||num==5){
		return true;
	}else if(num%2==0||num%3==0||num%5==0){
		return false;
	}else{
		int i = 7;
		while(i*i<=num){
			if(num%i==0){
				return false;
			}else if(i%6==1){
				i+=4;
			}else{
				i+=2;
			}
		}
		return true;
	}
}

int main(){
	int T, num, primeNum, sub;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> T;
	for (int i=0; i<T; ++i){
		cin >> num;
		sub=10000;
		for(int j=2; j<=num/2; j++){
			if(isPrime(j) && isPrime(num-j) && (sub>num-j*2) ){
				sub = num-j*2;
				primeNum = j;
			}
		}
		cout << primeNum << " " << num-primeNum << "\n";
	}
	return 0;
}
