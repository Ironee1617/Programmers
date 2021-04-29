#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int a = 0; a < commands.size(); ++a) {
		vector<int> arr(commands[a][1] - commands[a][0] + 1);
		//자르고
		int k = 0;
		for (int i = commands[a][0] - 1; i < commands[a][1]; ++i)
		{
			arr[k] = array[i];
			k++;
		}
		//정렬하고
		sort(arr.begin(), arr.end());
		//k번째 숫자구하고
		answer.push_back(arr[commands[a][2] - 1]);
		//answer배열에 넣고
	}

	return answer;
}