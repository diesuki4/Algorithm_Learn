// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkSquare(vector<vector<int>>& board, int i, int j);
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

int checkSquare(vector<vector<int>>& board, int r, int c)
{
    int n = 0;
    int R = board.size(), C = board.front().size();

    while (r < R && c < C)
    {
        for (int i = r - n; i <= r; ++i)
            if (board[i][c] == 0)
                return n * n;

        for (int j = c - n; j < c; ++j)
            if (board[r][j] == 0)
                return n * n;

        ++r, ++c, ++n;
    }

    return n * n;
}

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int R = board.size(), C = board.front().size();

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (board[r][c])
                answer = max(checkSquare(board, r, c), answer);

    return answer;
}
