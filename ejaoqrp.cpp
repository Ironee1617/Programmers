#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int less1 = 0, less2 = 0;
    priority_queue <int, vector<int>, greater<int> > pq;

    for (int i = 0; i < scoville.size(); ++i) {
        pq.push(scoville[i]);
    }

    while (true) {
        less1 = pq.top();
        pq.pop();
        if (less1 < K) {
            if (pq.empty())
                return -1;
            less2 = pq.top();
            pq.pop();
            pq.push(less1 + (less2 * 2));
            answer++;
        }
        else {
            break;
        }
    }

    return answer;
}