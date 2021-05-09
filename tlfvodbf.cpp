#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Cmp(pair<int, double> a, pair<int, double> b) {
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
		return a.first < b.first;
	else
		return false;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<int, double>> fail_per;
	int reach = 0;
	int notClear = 0;


	for (int i = 1; i < N + 1; i++) {
		reach = 0;
		notClear = 0;

		for (int j = 0; j < stages.size(); j++) {
			if (stages[j] >= i)
				reach++;
			if (stages[j] == i)
				notClear++;

		}

		//double fail = (reach == 0) ? 0 : (double)notClear / (double)reach;
		fail_per.push_back({ i, (reach == 0) ? 0 : (double)notClear / (double)reach });
	}

	sort(fail_per.begin(), fail_per.end(), Cmp);

	for (int i = 0; i < fail_per.size(); i++) {
		answer.push_back(fail_per[i].first);
	}

	return answer;
}