#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int a = 0; a < commands.size(); ++a) {
		vector<int> arr(commands[a][1] - commands[a][0] + 1);
		//�ڸ���
		int k = 0;
		for (int i = commands[a][0] - 1; i < commands[a][1]; ++i)
		{
			arr[k] = array[i];
			k++;
		}
		//�����ϰ�
		sort(arr.begin(), arr.end());
		//k��° ���ڱ��ϰ�
		answer.push_back(arr[commands[a][2] - 1]);
		//answer�迭�� �ְ�
	}

	return answer;
}