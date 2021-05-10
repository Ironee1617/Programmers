#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	answer.push_back(arr[0]);

	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i - 1] != arr[i])
			answer.push_back(arr[i]);
	}

	if (arr[arr.size() - 1] != answer[answer.size() - 1])
		answer.push_back(arr[arr.size() - 1]);

	return answer;
}