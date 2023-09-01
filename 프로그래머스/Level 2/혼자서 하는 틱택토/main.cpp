#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> board);

int main(int argc, char* argv[])
{
    cout << solution({"O.X", ".O.", "..X"}) << endl;
    cout << solution({"OOO", "...", "XXX"}) << endl;
    cout << solution({"OOO", "XOX", "XXO"}) << endl;
    cout << solution({"...", ".X.", "..."}) << endl;
    cout << solution({"...", "...", "..."}) << endl;

    return 0;
}

int solution(vector<string> board)
{
    int nO = 0, nX = 0;

    for (string& s : board)
        for (char c : s)
            nO += (c == 'O'),
            nX += (c == 'X');

    int diff = nO - nX;

    if (!(diff == 0 || diff == 1))
        return 0;

    vector<vector<vector<int>>> vvv = {
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}},
        {{2, 0}, {1, 1}, {0, 2}}
    };

    bool bO = 0, bX = 0;

    for (auto& vv : vvv)
    {
        int tO = 0;

        for (auto& v : vv)
            tO += (board[v[0]][v[1]] == 'O');

        if (tO == 3)
        {
            if (nX + 1 != nO)
                return 0;

            bO = true;
            break;
        }
    }

    for (auto& vv : vvv)
    {
        int tX = 0;

        for (auto& v : vv)
            tX += (board[v[0]][v[1]] == 'X');

        if (tX == 3)
        {
            if (nX != nO)
                return 0;

            bX = true;
            break;
        }
    }

    if (bO && bX)
        return 0;

    return 1;
}
