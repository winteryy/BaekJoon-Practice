#include <iostream>
#include <string>
using namespace std;

int main(){
	int x, y, diff=64, thisDiff;
	cin >> y >> x;
	string board[y];
	for(int i=0; i<y; ++i){
		cin >> board[i];
	}
	for(int k=0; k<y-7; ++k){
		for(int l=0; l<x-7; ++l){
			thisDiff=0;
			for(int i=k; i<k+8; ++i){
				for(int j=l; j<l+8; ++j){
					if((i+j)%2==0 && board[i][j]=='B'){
						thisDiff+=1;
					}else if((i+j)%2!=0 && board[i][j]=='W'){
						thisDiff+=1;
					}
				}
			}
			if (thisDiff<diff){
				diff=thisDiff;
			}
			if(64-thisDiff<diff){
				diff=64-thisDiff;				
			}
		}
	}
	cout << diff << endl;
	return 0;
}
