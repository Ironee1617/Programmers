#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string week[] = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    int month[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int sum = 0;
    for (int i = 1; i < a; i++) {
        sum += month[i];
    }

    sum += b;
    answer = week[sum % 7];

    return answer;
}