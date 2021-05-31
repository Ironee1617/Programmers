#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int p = 0;
    int y = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'y' || s[i] == 'Y') y++;
        else if (s[i] == 'p' || s[i] == 'P') p++;
    }

    if (y == p) answer = true;
    else answer = false;

    return answer;
}