// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill);

int main(int argc, char* argv[])
{
    cout << solution({{5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5},
                      {5, 5, 5, 5, 5}},
                     {{1, 0, 0, 3, 4, 4},
                      {1, 2, 0, 2, 3, 2},
                      {2, 1, 0, 3, 1, 2},
                      {1, 0, 1, 3, 3, 1}}) << endl;

    cout << solution({{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}},
                     {{1, 1, 1, 2, 2, 4},
                      {1, 0, 0, 1, 1, 2},
                      {2, 2, 0, 2, 0, 100}}) << endl;

    return 0;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = board.size() * board.front().size();

    for (vector<int>& sk : skill)
    {
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int degree = (sk[0] == 1) ? -sk[5] : sk[5];

        for (int r = r1; r <= r2; ++r)
        {
            for (int c = c1; c <= c2; ++c)
            {
                int prev = board[r][c];

                board[r][c] += degree;
                answer += (prev <= 0) && (0 < board[r][c]) ? +1 : 0;
                answer += (0 < prev) && (board[r][c] <= 0) ? -1 : 0;
            }
        }
    }

    return answer;
}
