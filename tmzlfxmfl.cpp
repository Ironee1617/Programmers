#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	int index = 0;
	vector<string> skill_v(skill_trees.size());

	for (int i = 0; i < skill_trees.size(); i++) {
		index = 0;
		for (int j = 0; j < skill_trees[i].size(); j++) {
			for (int k = 0; k < skill.size(); k++) {
				if (skill_trees[i][j] == skill[k]) {
					skill_v[i] += skill_trees[i][j];
					index++;
					break;
				}
			}
			if (index == skill.size())
				break;
		}
	}

	for (int i = 0; i < skill_v.size(); i++) {
		if (skill_v[i].size() == 0) {
			answer++;
		}
		else {
			for (int j = 0; j < skill_v[i].size(); j++) {
				if (skill[j] != skill_v[i][j])
					break;

				if (j == skill_v[i].size() - 1)
					answer++;
			}
		}
	}

	return answer;
}