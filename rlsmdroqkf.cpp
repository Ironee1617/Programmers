#include <string>
#include <vector>

using namespace std;

vector<int> pop_front(vector<int>, int);

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	while (!progresses.empty()) {
		for (int i = 0; i < progresses.size(); ++i)
		{
			progresses[i] += speeds[i];
		}
		int result = 0;
		for (int i = 0; i < progresses.size(); ++i) {
			if (progresses[i] >= 100)
				result += 1;
			else
				break;
		}

		if (result != 0)
		{
			answer.push_back(result);
			progresses = pop_front(progresses, result);
			speeds = pop_front(speeds, result);
		}
	}

	return answer;
}

vector<int> pop_front(vector<int> v, int num = 1)
{
	for (int i = 0; i < v.size() - num; ++i)
	{
		v[i] = v[i + num];
	}

	for (int i = 0; i < num; ++i)
		v.pop_back();
	return v;
}