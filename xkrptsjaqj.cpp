#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void DFS(vector<int> numbers, int target, int sum, int depth) {
	if (depth == numbers.size()) {
		if (target == sum) {
			answer++;
			return;
		}
	}
	else if (depth > numbers.size()) return;

	DFS(numbers, target, sum + numbers[depth], depth + 1);
	DFS(numbers, target, sum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {

	DFS(numbers, target, numbers[0], 1);
	DFS(numbers, target, -numbers[0], 1);

	return answer;
}