#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves);

class ClawMachine
{
private:
    vector<queue<int>> board;

public:
    ClawMachine(vector<vector<int>>& board) : board(vector<queue<int>>(board.size()))
    {
        for (vector<int> row : board)
            for (int i = 0; i < row.size(); ++i)
                if (row[i]) this->board[i].emplace(row[i]);
    }

    int pull(int move)
    {
        queue<int>& que = board[move - 1];

        if (que.empty())
        {
            return -1;
        }
        else
        {
            int doll = que.front(); que.pop();

            return doll;
        }
    }
};

int main(int argc, char* argv[])
{
    cout << solution({  {0, 0, 0, 0, 0},
                        {0, 0, 1, 0, 3},
                        {0, 2, 5, 0, 1},
                        {4, 2, 4, 4, 2},
                        {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4}) << endl;

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> dolls;
    ClawMachine clawMachine(board);

    for (int move : moves)
    {
        int doll = clawMachine.pull(move);

        if (!dolls.empty() && doll == dolls.top())
            dolls.pop(), answer += 2;
        else if (doll != -1)
            dolls.emplace(doll);
    }

    return answer;
}
