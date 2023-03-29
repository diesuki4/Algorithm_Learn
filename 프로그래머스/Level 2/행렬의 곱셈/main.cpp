#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2);

int main(int argc, char* argv[])
{
    print(solution({{1, 4},
                    {3, 2},
                    {4, 1}},
        
                   {{3, 3},
                    {3, 3}}));

    print(solution({{2, 3, 2},
                    {4, 2, 4},
                    {3, 1, 4}},
        
                   {{5, 4, 3},
                    {2, 4, 1},
                    {3, 1, 1}}));

    return 0;
}

void print(vector<vector<int>> result)
{
    for (vector<int>& v : result)
    {
        for (int e : v)
            cout << e << " ";

        cout << endl;
    }
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    size_t M = arr1.size(), K = arr2.size(), N = arr2.front().size();
    vector<vector<int>> answer(M, vector<int>(N, 0));

    for (int row = 0; row < M; ++row)
        for (int col = 0; col < N; ++col)
            for (int i = 0; i < K; ++i)
                answer[row][col] += arr1[row][i] * arr2[i][col];

    return answer;
}
