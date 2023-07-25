#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int rDFS(vector<vector<bool>>& tree, int vertex);
int calculate(vector<vector<bool>> tree, vector<int>& discon);
int solution(int n, vector<vector<int>> wires);

int main(int argc, char* argv[])
{
    cout << solution(9, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}}) << endl;
    cout << solution(4, {{1, 2}, {2, 3}, {3, 4}}) << endl;
    cout << solution(7, {{1, 2}, {2, 7}, {3, 7}, {3, 4}, {4, 5}, {6, 7}}) << endl;

    return 0;
}

int rDFS(vector<vector<bool>>& tree, int vertex)
{
    int nConnected = 1;

    for (int j = 1; j < tree.size(); ++j)
    {
        if (tree[vertex][j])
        {
            tree[vertex][j] = tree[j][vertex] = false,
            nConnected += rDFS(tree, j);
        }
    }

    return nConnected;
}

int calculate(vector<vector<bool>> tree, vector<int>& discon)
{
    tree[discon[0]][discon[1]] = tree[discon[1]][discon[0]] = false;

    return abs(rDFS(tree, discon[0]) - rDFS(tree, discon[1]));
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = 100;
    vector<vector<bool>> tree(n + 1, vector<bool>(n + 1, false));

    for (auto& wire : wires)
        tree[wire[0]][wire[1]] = tree[wire[1]][wire[0]] = true;

    for (auto& wire : wires)
        answer = min(answer, calculate(tree, wire));

    return answer;
}
