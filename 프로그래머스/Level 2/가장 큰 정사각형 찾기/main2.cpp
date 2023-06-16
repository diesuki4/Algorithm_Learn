#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board);

int main(int argc, char* argv[])
{
    cout << solution({{0, 1, 1, 1},
                      {1, 1, 1, 1},
                      {1, 1, 1, 1},
                      {0, 0, 1, 0}}) << endl;

    cout << solution({{0, 0, 1, 1},
                      {1, 1, 1, 1}}) << endl;

    cout << solution({{1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1},
                      {0, 0, 1, 1, 1}}) << endl;

    cout << solution({{0, 1},
                      {0, 0}}) << endl;

    return 0;
}

int solution(vector<vector<int>> board)
{
    int answer = find(board[0].begin(), board[0].end(), 1) != board[0].end() ? 1 : 0;
    int n = board.size(), m = board[0].size();

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = (min(board[i][j - 1], min(board[i - 1][j - 1], board[i - 1][j]))) + 1;
                answer = max(board[i][j], answer);
            }
        }
    }

    return answer * answer;
}
