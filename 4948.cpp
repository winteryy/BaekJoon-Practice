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
	int num, primeNum;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	while(1){
		cin >> num;
		if (num==0){
			break;
		}
		primeNum = 0;
		for(int i=num+1; i<=num*2; i++){
			if(isPrime(i)){
				primeNum++;
			}
		}
		cout << primeNum << "\n";
	}
	return 0;
}
