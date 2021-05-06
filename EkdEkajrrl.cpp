#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
	int answer = 0;
	int N = land.size();
	for (int i = 0; i < N - 1; i++) {
		land[i + 1][0] += max({ land[i][1], land[i][2], land[i][3] });
		land[i + 1][1] += max({ land[i][0], land[i][2], land[i][3] });
		land[i + 1][2] += max({ land[i][0], land[i][1], land[i][3] });
		land[i + 1][3] += max({ land[i][0], land[i][1], land[i][2] });
	}

	for (int i = 0; i < 4; i++) {
		answer = max(land[N - 1][i], answer);
	}

	return answer;
}