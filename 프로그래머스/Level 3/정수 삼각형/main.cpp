#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle);

int main(int argc, char* argv[])
{
    cout << solution({{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}}) << endl;

    return 0;
}

int solution(vector<vector<int>> triangle)
{
    int answer = triangle[0][0];

    for (int i = 1; i < triangle.size(); ++i)
    {
        for (unsigned j = 0; j < triangle[i].size(); ++j)
        {
            int l_parent = (1 <= j) ? triangle[i - 1][j - 1] : 0;
            int r_parent = (j < triangle[i - 1].size()) ? triangle[i - 1][j] : 0;

            triangle[i][j] += max(l_parent, r_parent);
            answer = max(triangle[i][j], answer);
        }
    }

    return answer;
}
