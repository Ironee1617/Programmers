#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
bool conversion[50];
//vector<int> result;

void dfs(string begin, string target, vector<string> words) {
	cout << begin << endl;
	if (begin == target)
		return;

	for (int i = 0; i < words.size(); ++i) {
		if (conversion[i]) continue;

		int count = 0;
		for (int j = 0; j < begin.size(); ++j)
			if (begin[j] != words[i][j]) count++;

		if (count == 1) {
			conversion[i] = true;
			answer++;
			dfs(words[i], target, words);
		}
	}
}

int solution(string begin, string target, vector<string> words) {
	for (int i = 0; i < words.size(); ++i)
		if (words[i] == target) dfs(begin, target, words);

	return answer;
}