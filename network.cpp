#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[200];
void dfs(int n, vector<vector<int>> computers, int start) {

	visit[start] = true;

	for (int i = 0; i < n; ++i) {
		if (computers[start][i] == 1 && !visit[i]) {
			dfs(n, computers, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; ++i) {
		if (visit[i]) continue;
		answer++;
		dfs(n, computers, i);
	}
	return answer;
}