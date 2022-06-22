#include <iostream>

using namespace std;

int main(){
	int n;
	cin>>n;	
	int people[n][3];
	for(int i=0; i<n; ++i){
		cin >> people[i][0] >> people[i][1];
		people[i][2]=1;
	}
	for(int i=0; i<n-1; ++i){
		for(int j=i+1; j<n; ++j){
			if(people[i][0]>people[j][0] && people[i][1]>people[j][1]){
				people[j][2]++;
			}else if(people[i][0]<people[j][0] && people[i][1]<people[j][1]){
				people[i][2]++;
			}
		}
	}
	for(int i=0; i<n; ++i){
		cout << people[i][2] << " ";
	}
	return 0;
}
