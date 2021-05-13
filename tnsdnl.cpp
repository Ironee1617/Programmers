#include <string>
#include <vector>
#include <iostream>


using namespace std;


int solution(int n, vector<vector<int>> results) {
	int answer = 0;
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));


	for (int i = 0; i < results.size(); i++) {
		v[results[i][0]][results[i][1]]++;
		v[results[i][1]][results[i][0]]--;
	}

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (v[i][j] == 0)
				continue;

			for (int k = 1; k < n + 1; k++) {
				if (v[j][i] == v[i][k])
					v[j][k] = v[i][k];
			}
		}
	}

	for (int i = 1; i < v.size(); ++i) {
		for (int j = 1; j < v[i].size(); ++j) {
			cout << v[i][j] << "  ";
		}
		cout << endl;
	}

	for (int i = 1; i < n + 1; ++i) {
		int sum = 0;
		for (int j = 1; j < n + 1; ++j) {
			if (i == j) continue;
			if (v[i][j] == 0) break;
			sum++;
		}
		if (sum == n - 1) answer++;
	}
	cout << answer << endl;
	return answer;
}