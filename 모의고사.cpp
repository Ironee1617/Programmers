#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int v_one[] = { 1,2,3,4,5 };
	int v_two[] = { 2,1,2,3,2,4,2,5 };
	int v_thr[] = { 3,3,1,1,2,2,4,4,5,5 };

	int one = 0, two = 0, thr = 0;



	for (int i = 0; i < answers.size(); i++) {
		if (v_one[i % 5] == answers[i])
			one++;
		if (v_two[i % 8] == answers[i])
			two++;
		if (v_thr[i % 10] == answers[i])
			thr++;
	}

	int maxCount = max(one, max(two, thr));

	if (maxCount == one) answer.push_back(1);
	if (maxCount == two) answer.push_back(2);
	if (maxCount == thr) answer.push_back(3);

	return answer;
}