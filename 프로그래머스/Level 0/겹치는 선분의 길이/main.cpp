#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines);

int main(int argc, char* argv[])
{
    cout << solution({{0, 1}, {2, 5}, {3, 9}}) << endl;;
    cout << solution({{-1, 1}, {1, 3}, {3, 9}}) << endl;;
    cout << solution({{0, 5}, {3, 9}, {1, 10}}) << endl;;

    return 0;
}

int solution(vector<vector<int>> lines)
{
    vector<int> v(200, 0);

    for (vector<int>& line : lines)
        for (int i = line[0]; i < line[1]; ++i)
            ++v[100 + i];

    return count_if(v.begin(), v.end(), [](const int e) { return 1 < e; });
}
