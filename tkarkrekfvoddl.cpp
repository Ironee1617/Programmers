#include <string>
#include <vector>

using namespace std;


vector<int> solution(int n) {
	vector<int> answer;
	int k = 1;
	int pattern = 0;
	vector<vector<int>> v(n, vector<int>(n));
	int x = 0, y = 0;

	for (int i = 2; i <= n; i++) {
		k = i + k;
	}

	int count = n - 1;
	int num = count;

	for (int i = 1; i <= k; i++) {
		v[x][y] = i;

		if (num == 0) {
			if (x == 0 || y == 0) {
				num = count;
			}
			else if (x != 0 && y != 0) {
				count--;
				num = count;
			}
			pattern++;
		}

		if (pattern % 3 == 0) {
			x++;
		}
		else if (pattern % 3 == 1) {
			y++;
		}
		else {
			x--;
			y--;
		}
		num--;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (v[i][j] != 0) answer.push_back(v[i][j]);
	}



	return answer;
}