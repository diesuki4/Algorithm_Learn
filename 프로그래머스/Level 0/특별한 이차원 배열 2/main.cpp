#include <iostream>
#include <vector>

using namespace std;

int solution(vector<vector<int>> arr);

int main(int argc, char* argv[])
{
    cout << solution({{5, 192, 33}, {192, 72, 95}, {33, 95, 999}}) << endl;
    cout << solution({{19, 498, 258, 587}, {63, 93, 7, 754}, {258, 7, 1000, 723}, {587, 754, 723, 81}}) << endl;

    return 0;
}

int solution(vector<vector<int>> arr)
{
    size_t n = arr.size();

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            if (arr[i][j] != arr[j][i])
                return 0;

    return 1;
}
