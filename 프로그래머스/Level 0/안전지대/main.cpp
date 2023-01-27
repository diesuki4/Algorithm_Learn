#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void setDanger(vector<vector<int>>& board, int i, int j);
int solution(vector<vector<int>> board);

int main(int argc, char* argv[])
{
    cout << solution({{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}}) << endl;
    cout << solution({{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0}}) << endl;
    cout << solution({{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}}) << endl;

    return 0;
}

void setDanger(vector<vector<int>>& board, int i, int j)
{
    for (int k = i - 1; k <= i + 1; ++k)
    {
        for (int l = j - 1; l <= j + 1; ++l)
        {
            try
            {
                int& cell = board.at(k).at(l);

                if (!cell)
                    cell = 2;
            }
            catch (exception& e)
            {
                continue;
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    int n = board.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (board[i][j] == 1)
                setDanger(board, i, j);

    return accumulate(board.begin(), board.end(), 0, [](const int n, const vector<int>& vec) { return n + count(vec.begin(), vec.end(), 0); });
}
