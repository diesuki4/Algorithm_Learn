#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end);

int main(int argc, char* argv[])
{
    cout << solution({{2, 2, 6}, {1, 5, 10}, {4, 2, 9}, {3, 8, 3}}, 2, 2, 3) << endl;

    return 0;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;

    --col;
    auto pred = [col](auto& t1, auto& t2) { return (t1[col] == t2[col]) ? (t1[0] > t2[0]) : (t1[col] < t2[col]); };

    stable_sort(data.begin(), data.end(), pred);

    auto S = [&data](int i) { return accumulate(data[i - 1].begin(), data[i - 1].end(), 0, [i](int sum, int num) { return sum + (num % i); }); };

    for (int i = row_begin; i <= row_end; ++i)
        answer ^= S(i);

    return answer;
}
