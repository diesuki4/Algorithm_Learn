#include <iostream>
#include <vector>

using namespace std;

void rDFS(int i, vector<vector<int>>& computers, vector<bool>& visited);
int solution(int n, vector<vector<int>> computers);

int main(int argc, char* argv[])
{
    cout << solution(3, {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}) << endl;
    cout << solution(3, {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}}) << endl;

    return 0;
}

void rDFS(int i, vector<vector<int>>& computers, vector<bool>& visited)
{
    visited[i] = true;

    for (int j = 0; j < computers.size(); ++j)
        if (!visited[j] && computers[i][j])
            rDFS(j, computers, visited);
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
        {
            rDFS(i, computers, visited);
            ++answer;
        }
    }
            
    return answer;
}
