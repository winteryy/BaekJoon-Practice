#include <iostream>

using namespace std;
	int primeArray[1000001];//0 ¼Ò¼ö 
int main(){

	int M, N;
	cin >> M >> N;
	primeArray[1] = 1;
	for(int i=2; i<=N; ++i){ 
		if(primeArray[i]==0){
			for(int j=2; j*i<=N; ++j){
					primeArray[j*i] = 1;
			}
		}	
	}
	for(int i=M; i<=N; ++i){
		if(primeArray[i]==0){
			cout << i << "\n";
		}
	}
	
	return 0;
}
