#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;
	int st = 0;
	int en = people.size() - 1;

	sort(people.begin(), people.end());

	while (true) {
		if (st == en) { answer++; break; }
		else if (st > en) { break; }

		if (people[st] + people[en] <= limit) st++;
		answer++;
		en--;
	}

	return answer;
}