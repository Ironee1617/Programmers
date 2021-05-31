#include <string>
#include <vector>

using namespace std;

int divide(int n) {
	int one_num = 0;

	while (true) {
		if (n < 2) {
			if (n == 1)
				one_num++;
			break;
		}

		if (n % 2 == 1)
			one_num++;

		n /= 2;
	}
	return one_num;
}


int solution(int n) {
	int answer = 0;
	int one_num = 0;
	int comp_one = 0;
	one_num = divide(n);

	for (int i = n + 1; ; i++) {
		comp_one = divide(i);
		if (comp_one == one_num) {
			answer = i;
			break;
		}
	}

	return answer;
}