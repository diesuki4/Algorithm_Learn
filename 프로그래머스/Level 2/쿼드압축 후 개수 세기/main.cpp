#include <iostream>
#include <vector>
#include <utility>
#include <numeric>

using namespace std;

void print(vector<int> result);
pair<int, int> operator + (const pair<int, int>& pr1, const pair<int, int>& pr2);
pair<int, int> rSolution(vector<vector<int>>& arr, pair<int, int> start, int N);
vector<int> solution(vector<vector<int>> arr);

int main(int argc, char* argv[])
{
    print(solution({{1, 1, 0, 0},
                    {1, 0, 0, 0},
                    {1, 0, 0, 1},
                    {1, 1, 1, 1}}));

    print(solution({{1, 1, 1, 1, 1, 1, 1, 1},
                    {0, 1, 1, 1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1, 1, 1},
                    {0, 1, 0, 0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1, 0, 0, 1},
                    {0, 0, 0, 0, 1, 1, 1, 1}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

pair<int, int> operator + (const pair<int, int>& pr1, const pair<int, int>& pr2)
{
    return {pr1.first + pr2.first, pr1.second + pr2.second};
}

pair<int, int> rSolution(vector<vector<int>>& arr, pair<int, int> start, int N)
{
    auto cal_row = [&](vector<int> &v) { return accumulate(v.begin() + start.first, v.begin() + start.first + N, 0); };
    auto cal     = [&](int sum, vector<int>& v) { return sum + cal_row(v); };

    int total = accumulate(arr.begin() + start.second, arr.begin() + start.second + N, 0, cal);

    int N2 = N * N;
    int N1l2 = N * 0.5;

    if (total == 0 || total == N2)
        return {total == 0, total == N2};
    else
        return rSolution(arr, {start.first, start.second}, N1l2) +
               rSolution(arr, {start.first + N1l2, start.second}, N1l2) +
               rSolution(arr, {start.first, start.second + N1l2}, N1l2) +
               rSolution(arr, {start.first + N1l2, start.second + N1l2}, N1l2);
}

vector<int> solution(vector<vector<int>> arr)
{
    pair<int, int> answer = rSolution(arr, {0, 0}, arr.size());

    return {answer.first, answer.second};
}
