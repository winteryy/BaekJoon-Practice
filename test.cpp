#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter numbers (0 to stop):" << endl; // 사용자에게 안내 메시지

    while (cin >> n) { // cin이 정상적으로 작동하는지 확인
        if (n == 0) break; // 0이 입력되면 루프 종료
        cout << "You entered: " << n << endl; // 입력된 값 출력
    }

    cout << "Program finished." << endl; // 프로그램 종료 메시지
    return 0;
}