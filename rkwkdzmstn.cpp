#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& a, const string& b) {

	return a + b > b + a ? true : false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> temp(numbers.size());

	for (int i = 0; i < numbers.size(); ++i) {
		temp[i] = to_string(numbers[i]);
	}
	sort(temp.begin(), temp.end(), compare);
	for (int i = 0; i < temp.size(); ++i) {
		answer += temp[i];
	}
	if (answer[0] == '0')
		return "0";
	return answer;
}