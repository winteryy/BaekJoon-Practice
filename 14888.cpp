#include <iostream>
#include <vector>

using namespace std;

int n;
int minN = 1000000001;
int maxN = -1000000001;
vector<int> nums;
vector<int> op(4);

void BT(int value, int depth){
    if(depth==n){
        if(value<minN){
            minN = value;
        }
        if(value>maxN){
            maxN = value;
        }
    }else{
        for(int i=0; i<4; i++){
            if(op[i]>0){
                op[i]--;

                int newValue;
                switch(i){
                    case 0:
                        newValue = value + nums[depth];
                        break;
                    case 1:
                        newValue = value - nums[depth];
                        break;
                    case 2:
                        newValue = value * nums[depth];
                        break;
                    case 3:
                        newValue = value / nums[depth];
                }

                BT(newValue, depth+1);
                op[i]++;
            }
        }
    }
}

int main(){

    cin >> n;

    nums.resize(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    BT(nums[0], 1);

    cout << maxN << "\n" << minN;
}