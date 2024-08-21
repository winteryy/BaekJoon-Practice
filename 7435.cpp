#include <iostream>
#include <unordered_map>

using namespace std;

int a[4000];
int b[4000];
int c[4000];
int d[4000];

unordered_map<int, int> sumMap;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int sum = a[i]+b[j];
            sumMap[sum]++;
        }
    }

    long long result = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int sum = c[i]+d[j];
            if(sumMap.count(-sum)==1) {
                result += sumMap[-sum];
            }
        }
    }

    printf("%lld", result);
}

