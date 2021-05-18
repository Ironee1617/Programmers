#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	int a = s.size();
	if (a % 2 == 0) {
		a /= 2;
		answer = s.substr(a - 1, 2);
	}
	else {
		a /= 2;
		answer = s.at(a);
	}

	return answer;
}