#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(vector<vector<int>> arr);

int main(int argc, char* argv[])
{
    print(solution({{572, 22, 37}, {287, 726, 384}, {85, 137, 292}, {487, 13, 876}}));
    print(solution({{57, 192, 534, 2}, {9, 345, 192, 999}}));
    print(solution({{1, 2}, {3, 4}}));

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

    cout << endl;
}

vector<vector<int>> solution(vector<vector<int>> arr)
{
    int row = arr.size(), col = arr.front().size();

    if (row < col)
    {
        arr.resize(col);

        fill(arr.begin() + row, arr.end(), vector<int>(col, 0));
    }
    else if (row > col)
    {
        for_each(arr.begin(), arr.end(), [&](vector<int>& v)
        {
            v.resize(row);

            fill(v.begin() + col, v.end(), 0);
        });
    }

    return arr;
}
