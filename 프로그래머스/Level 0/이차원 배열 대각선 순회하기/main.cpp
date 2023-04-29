#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> board, int k);

int main(int argc, char* argv[])
{
    cout << solution({{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {3, 4, 5}}, 2) << endl;

    return 0;
}

int solution(vector<vector<int>> board, int k)
{
    int answer = 0;
    int row = board.size(), col = board.front().size();

    ++k;

    for (int i = 0; i < row && i < k; ++i)
    {
        int c = (col <= k - i) ? col : k - i;

        answer += accumulate(board[i].begin(), board[i].begin() + c, 0);
    }

    return answer;
}
