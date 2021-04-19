#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int _k = k;
	int next = 1;
	answer += number[0];

	for (int i = 0; _k > 0; i++) {
		if (next >= number.size())
			break;
		if (answer[i] - '0' < number[next] - '0') {
			answer[i] = number[next];
			_k--;
			i--;
			while (true) {
				if (i < 0 || _k <= 0)
					break;

				if (answer[i] < answer[i + 1])
				{
					answer[i] = answer[i + 1];
					answer.erase(i + 1, 1);
					_k--;
					i--;
					continue;
				}
				else
					break;
			}
		}
		else
			answer += number[next];

		next++;
	}

	if (_k != 0) {
		answer.erase(answer.size() - _k, _k);
	}
	else
		for (int i = next; i < number.size(); i++) {
			answer += number[i];
		}


	return answer;
}