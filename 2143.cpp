#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int a[1000];
int b[1000];

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t, n, m;

    cin >> t >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for(int i=0; i<m; i++) {
        cin >> b[i];
    }

    unordered_map<int, int> bMap;

    for(int i=0; i<m; i++) {
        int sum = 0;
        for(int j=i; j<m; j++) {
            sum+=b[j];
            bMap[sum]++;
        }
    }

    long long result = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum+=a[j];

            auto bElement = bMap.find(t-sum);
            if(bElement!=bMap.end()) {
                result += (*bElement).second;
            }
        }
    }

    cout << result;
}