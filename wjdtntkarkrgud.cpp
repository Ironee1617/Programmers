#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> triangle) {
	int answer = 0;

	vector<vector<int>> v(triangle.size(), vector<int>(triangle.size()));

	v[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0)
			{
				v[i][j] = v[i - 1][j] + triangle[i][j];
			}
			else if (i == j)
			{
				v[i][j] = v[i - 1][j - 1] + triangle[i][j];
			}
			else
			{
				v[i][j] = max(v[i - 1][j - 1] + triangle[i][j], v[i - 1][j] + triangle[i][j]);
			}
		}
	}

	for (int i = 0; i < triangle.size(); ++i) {
		answer = max(v[v.size() - 1][i], answer);
	}

	cout << answer << endl;
	return answer;
}