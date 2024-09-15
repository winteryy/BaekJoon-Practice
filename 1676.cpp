#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num125, num25, num5;

    num125 = n/125;
    num25 = n/25 - num125;
    num5 = n/5 - num125 - num25;

    cout << num125*3 + num25*2 + num5;
}