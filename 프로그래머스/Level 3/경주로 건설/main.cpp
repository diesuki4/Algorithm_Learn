#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

enum class DIR;
int rDFS(unsigned r, unsigned c, DIR dir, int cur_cost, vector<vector<int>>& board, vector<vector<unordered_map<DIR, int>>>& cost);
int solution(vector<vector<int>> board);

int main(int argc, char* argv[])
{
    cout << solution({{0, 0, 0},
                      {0, 0, 0},
                      {0, 0, 0}}) << endl;

    cout << solution({{0, 0, 0, 0, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 1, 0, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 1},
                      {0, 0, 1, 0, 0, 0, 1, 0},
                      {0, 1, 0, 0, 0, 1, 0, 0},
                      {1, 0, 0, 0, 0, 0, 0, 0}}) << endl;
    
    cout << solution({{0, 0, 1, 0},
                      {0, 0, 0, 0},
                      {0, 1, 0, 1},
                      {1, 0, 0, 0}}) << endl;
    
    cout << solution({{0, 0, 0, 0, 0, 0},
                      {0, 1, 1, 1, 1, 0},
                      {0, 0, 1, 0, 0, 0},
                      {1, 0, 0, 1, 0, 1},
                      {0, 1, 0, 0, 0, 1},
                      {0, 0, 0, 0, 0, 0}}) << endl;

    return 0;
}

enum class DIR
{
    DOWN,
    RIGHT,
    UP,
    LEFT
};

int rDFS(unsigned r, unsigned c, DIR dir, int cur_cost, vector<vector<int>>& board, vector<vector<unordered_map<DIR, int>>>& cost)
{
    size_t n = board.size();

    if (n <= r || n <= c || board[r][c] == 1 || cost[r][c][dir] <= cur_cost)
        return INT_MAX;

    cost[r][c][dir] = cur_cost;

    if (r == n - 1 && c == n - 1)
        return cur_cost;

    int result = INT_MAX;
    unordered_map<DIR, vector<int>> umap = {{DIR::DOWN, {1, 0}}, {DIR::RIGHT, {0, 1}}, {DIR::UP, {-1, 0}}, {DIR::LEFT, {0, -1}}};

    for (auto& pr : umap)
    {
        DIR nextDir = pr.first;
        int dr = pr.second[0];
        int dc = pr.second[1];

        result = min(result, rDFS(r + dr, c + dc, nextDir, cur_cost + (dir == nextDir ? 100 : 600), board, cost));
    }

    return result;
}

int solution(vector<vector<int>> board)
{
    size_t n = board.size();
    vector<vector<unordered_map<DIR, int>>> cost(n, vector<unordered_map<DIR, int>>(n,
        {{DIR::DOWN,  INT_MAX},
         {DIR::RIGHT, INT_MAX},
         {DIR::UP,    INT_MAX},
         {DIR::LEFT,  INT_MAX}}
    ));

    return min(rDFS(0, 0, DIR::DOWN, 0, board, cost), rDFS(0, 0, DIR::RIGHT, 0, board, cost));
}
