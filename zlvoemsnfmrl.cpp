#include <string>
#include <vector>

using namespace std;
string solution(vector<int> numbers, string hand) {
	string answer = "";
	vector<vector<int>> v(4, vector<int>(3, 0));

	int l_x = 3, l_y = 0;
	int r_x = 3, r_y = 2;


	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0)
			numbers[i] = 11;

		int x = (numbers[i] - 1) / 3;
		int y = (numbers[i] - 1) % 3;

		if (y == 0) {
			l_x = x;
			l_y = y;
			answer += "L";
			continue;
		}
		else if (y == 2) {
			r_x = x;
			r_y = y;
			answer += "R";
			continue;
		}

		int l_sum = abs(x - l_x) + abs(y - l_y);
		int r_sum = abs(x - r_x) + abs(y - r_y);

		if (r_sum > l_sum) {
			l_x = x;
			l_y = y;
			answer += "L";
		}
		else if (r_sum < l_sum) {
			r_x = x;
			r_y = y;
			answer += "R";
		}
		else if (r_sum == l_sum) {
			if (hand == "right") {
				r_x = x;
				r_y = y;
				answer += "R";
			}
			else {
				l_x = x;
				l_y = y;
				answer += "L";
			}
		}
	}

	return answer;
}