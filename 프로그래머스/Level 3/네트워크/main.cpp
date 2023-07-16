#include <iostream>
#include <vector>

using namespace std;

void rDFS(int i, int j, int n, vector<vector<int>>& computers);
int solution(int n, vector<vector<int>> computers);

int main(int argc, char* argv[])
{
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;

    return 0;
}

void rDFS(int i, int j, int n, vector<vector<int>>& computers)
{
    computers[i][j] = computers[j][i] = 0;

    for (int k = 0; k < n; ++k)
        if (computers[i][k])
            rDFS(i, k, n, computers);

    for (int k = 0; k < n; ++k)
        if (computers[j][k])
            rDFS(j, k, n, computers);
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (computers[i][j])
            {
                rDFS(i, j, n, computers);
                ++answer;
            }
        }
    }
            
    return answer;
}
