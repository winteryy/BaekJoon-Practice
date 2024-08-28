#include <iostream>
#include <vector>

using namespace std;

vector<int> primeNum;

bool isPrime(int n) {
    if(n==2 || n==3) {
        return true;
    } else if(n%2==0 || n%3==0) {
        return false;
    }

    for(int i=5; i*i<=n; i+=6) {
        if(n%i==0 || n%(i+2)==0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    for(int i=2; i<=n; i++) {
        if(isPrime(i)) {
            primeNum.push_back(i);
        }
    }

    int left = 0, right = 0;
    int sum = 0, result = 0;
    while(left<primeNum.size() && right<=primeNum.size()) {
        if(sum==n) {
            result++;
            sum += primeNum[right];
            right++;
        } else if(sum<n) {
            sum += primeNum[right];
            right++;
        } else {
            sum -= primeNum[left];
            left++;
        }
    }

    cout << result;
}