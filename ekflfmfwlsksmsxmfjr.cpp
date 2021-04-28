#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int _weight, vector<int> truck_weights) {
	int answer = 0;
	queue<pair<int, int>> q;
	int weight = _weight;

	while (true) {

		if (!q.empty() && q.front().second == answer)
		{
			weight += q.front().first;
			q.pop();
		}

		if (!truck_weights.empty() && weight >= truck_weights[0]) {
			weight -= truck_weights[0];
			q.push({ truck_weights[0], answer + bridge_length });
			truck_weights.erase(truck_weights.begin());
		}

		answer++;

		if (truck_weights.size() == 0 && q.empty())
			break;
	}
	return answer;
}