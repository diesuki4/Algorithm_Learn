#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<vector<int>> queries);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 2, 3, 4}, {{0, 1}, {1, 2}, {2, 3}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    for (vector<int>& v : queries)
    {
        int s = v[0], e = v[1] + 1;

        for_each(arr.begin() + s, arr.begin() + e, [](int& num) { ++num; });
    }

    return arr;
}
