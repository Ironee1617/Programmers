#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	vector<int> num(n, 1);

	for (int i = 0; i < lost.size(); ++i) {
		num[lost[i] - 1] = 0;
	}

	for (int i = 0; i < reserve.size(); ++i) {
		num[reserve[i] - 1] += 1;
	}

	for (int i = 0; i < num.size(); ++i) {
		if (num[i] == 0) {
			if (i != 0) {
				if (num[i - 1] == 2) {
					num[i - 1] -= 1;
					num[i] += 1;
					continue;
				}
			}

			if (i != num.size() - 1) {
				if (num[i + 1] == 2) {
					num[i + 1] -= 1;
					num[i] += 1;
					continue;
				}
			}
		}
	}

	for (int i = 0; i < num.size(); ++i) {
		if (num[i] >= 1)
			answer += 1;
	}

	return answer;
}