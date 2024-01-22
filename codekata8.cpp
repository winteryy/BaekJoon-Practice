#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    return angle==90||angle==180?(angle==90?2:4):(angle<90?1:3);
}