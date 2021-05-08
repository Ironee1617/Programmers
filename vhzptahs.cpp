#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> v;

    for (int i = 0; i < nums.size(); i++) {
        if (find(v.begin(), v.end(), nums[i]) == v.end())
            v.push_back(nums[i]);
    }

    if (v.size() > nums.size() / 2) answer = nums.size() / 2;
    else answer = v.size();

    return answer;
}