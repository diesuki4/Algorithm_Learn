#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool canQ(vector<int>& board, int row, int col);
int rDFS(vector<int>& board, int row);
int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(4) << endl;

    return 0;
}

bool canQ(vector<int>& board, int row, int col)
{
    for (int r = 0; r < row; r++)
        if (board[r] == col)
            return false;
        else if (abs(row - r) == abs(col - board[r]))
            return false;

    return true;
}

int rDFS(vector<int>& board, int row)
{
    size_t n = board.size();

    if (n <= row)
        return 1;

    int result = 0;

    for (int col = 0; col < n; ++col)
    {
        if (canQ(board, row, col))
        {
            board[row] = col;
            result += rDFS(board, row + 1);
        }
    }

    return result;
}

int solution(int n)
{
    vector<int> board(n, 0);

    return rDFS(board, 0);
}
