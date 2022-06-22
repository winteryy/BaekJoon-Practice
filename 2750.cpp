#include <iostream>
#include <list>

using namespace std;

int main(){
	int n, num;
	cin >> n;
	
	list<int> sList;
	list<int>::iterator iter = sList.begin();
	
	for(int i=0; i<n; ++i){
		cin >> num;
		if(i==0){
			sList.push_back(num);
		}
		else{
			for(iter=sList.begin(); iter!=sList.end(); ++iter){
				if(num < *iter){
					sList.insert(iter, num);
					break;
				}
			}
			if(sList.size()==i){
				sList.push_back(num);
			}
		}
	}
	for(iter=sList.begin(); iter!=sList.end(); ++iter){
		cout << *iter << '\n';
	}	
	return 0;
}
