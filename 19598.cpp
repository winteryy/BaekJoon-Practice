#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Meeting {
public:
    int start, end;

    Meeting(int start, int end) {
        this->start = start;
        this->end = end;
    }

    bool operator < (const Meeting& other) const{
        return this->end > other.end;
    }
};

bool cmp (Meeting l, Meeting r) {
    return l.start < r.start;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Meeting> mList;
    priority_queue<Meeting> pq;

    for(int i=0; i<n; i++) {
        int s, e;
        cin >> s >> e;
        mList.push_back(Meeting(s, e));
    }

    sort(mList.begin(), mList.end(), cmp);

    size_t room = 1;
    for(auto m: mList) {
        while(!pq.empty()) {
            if(pq.top().end<=m.start) {
                pq.pop();
            }else {
                break;
            }
        }
        pq.push(m);

        if(room<pq.size()) {
            room = pq.size();
        }
    }

    cout << room;
}