#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land);

int main(int argc, char* argv[])
{
    cout << solution({{1, 2, 3, 5}, {5, 6, 7, 8}, {4, 3, 2, 1}}) << endl;

    return 0;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    size_t n = land.size();

    for (int i = 1; i < n; ++i)
    {
        land[i][0] += max(land[i - 1][1], max(land[i - 1][2], land[i - 1][3]));
        land[i][1] += max(land[i - 1][0], max(land[i - 1][2], land[i - 1][3]));
        land[i][2] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][3]));
        land[i][3] += max(land[i - 1][0], max(land[i - 1][1], land[i - 1][2]));
    }

    return *max_element(land[n - 1].begin(), land[n - 1].end());
}
