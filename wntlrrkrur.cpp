#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;

	queue<int> q;

	for (int i = 0; i < prices.size(); ++i) {
		if (i == prices.size() - 1) {
			answer.push_back(0);
			break;
		}
		int stack = 1;
		for (int j = i + 1; j < prices.size(); ++j) {
			if (prices[i] <= prices[j]) {

				if (j == prices.size() - 1) {
					answer.push_back(stack);
					break;
				}
				stack++;
			}
			else {
				answer.push_back(stack);
				break;
			}
		}
	}



	return answer;
}