#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> s;

	for (int i = 0; i < moves.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[j][moves[i] - 1] == 0)
				continue;
			else {
				if (!s.empty()) {
					if (s.top() == board[j][moves[i] - 1]) {
						s.pop();
						answer += 2;
						board[j][moves[i] - 1] = 0;
					}
					else {
						s.push(board[j][moves[i] - 1]);
						board[j][moves[i] - 1] = 0;
					}
				}
				else {
					s.push(board[j][moves[i] - 1]);
					board[j][moves[i] - 1] = 0;
				}
				break;
			}
		}
	}

	return answer;
}