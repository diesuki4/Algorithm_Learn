#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point;
enum class DIR;
Point moveTo(Point& p, DIR dir, vector<string>& board);
int solution(vector<string> board);

int main(int argc, char* argv[])
{
    cout << solution({"...D..R",
                      ".D.G...",
                      "....D.D",
                      "D....D.",
                      "..D...."}) << endl;

    cout << solution({".D.R",
                      "....",
                      ".G..",
                      "...D"}) << endl;

    return 0;
}

struct Point
{
    unsigned r;
    unsigned c;
    int dist;
};

enum class DIR
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

Point moveTo(Point& p, DIR dir, vector<string>& board)
{
    size_t R = board.size(), C = board.front().size();
    Point pM(p);
    int dr, dc;
    
    switch (dir)
    {
    case DIR::UP:    dr = -1; dc = 0; break;
    case DIR::DOWN:  dr = +1; dc = 0; break;
    case DIR::LEFT:  dr = 0; dc = -1; break;
    case DIR::RIGHT: dr = 0; dc = +1; break;
    }

    while ((pM.r + dr) < R && (pM.c + dc) < C && board[pM.r + dr][pM.c + dc] != 'D')
        pM.r += dr, pM.c += dc;

    ++pM.dist;

    return pM;
}

int solution(vector<string> board)    
{
    size_t R = board.size(), C = board.front().size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    queue<Point> que;

    for (unsigned r = 0; r < R; ++r)
    {
        for (unsigned c = 0; c < C; ++c)
        {
            if (board[r][c] == 'R')
            {
                que.push({r, c, 0});

                break;
            }
        }
    }

    while (!que.empty())
    {
        Point p = que.front(); que.pop();

        if (board[p.r][p.c] == 'G')
            return p.dist;
        else if (visited[p.r][p.c])
            continue;

        visited[p.r][p.c] = true;

        que.emplace(moveTo(p, DIR::UP, board));
        que.emplace(moveTo(p, DIR::DOWN, board));
        que.emplace(moveTo(p, DIR::LEFT, board));
        que.emplace(moveTo(p, DIR::RIGHT, board));
    }

    return -1;
}
