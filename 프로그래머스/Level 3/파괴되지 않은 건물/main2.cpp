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
    int answer = 0;
    int R = board.size(), C = board.front().size();
    vector<vector<int>> pSum(R + 1, vector<int>(C + 1, 0));

    for (vector<int>& sk : skill)
    {
        int r1 = sk[1], c1 = sk[2];
        int r2 = sk[3], c2 = sk[4];
        int degree = (sk[0] == 1) ? -sk[5] : sk[5];

        pSum[r1][c1] += degree;
        pSum[r1][c2 + 1] -= degree;
        pSum[r2 + 1][c1] -= degree;
        pSum[r2 + 1][c2 + 1] += degree;
    }

    for (int r = 1; r < R; ++r)
        for (int c = 0; c < C; ++c)
            pSum[r][c] += pSum[r - 1][c];

    for (int c = 1; c < C; ++c)
        for (int r = 0; r < R; ++r)
            pSum[r][c] += pSum[r][c - 1];

    for (int r = 0; r < R; ++r)
        for (int c = 0; c < C; ++c)
            if (0 < board[r][c] + pSum[r][c])
                ++answer;

    return answer;
}
