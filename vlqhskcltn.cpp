#include <string>
#include <vector>

using namespace std;


int solution(int n) {
	int answer = 0;
	long long fi[100001];
	fi[0] = 0, fi[1] = 1;

	for (int i = 2; i <= n; i++) {
		fi[i] = ((fi[i - 1] % 1234567) + (fi[i - 2] % 1234567)) % 1234567;
	}

	answer = fi[n];

	return answer;
}