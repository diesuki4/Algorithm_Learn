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
    auto it_middle = v.begin() + 100;

    for (vector<int>& line : lines)
        transform(it_middle + line[0], it_middle + line[1], it_middle + line[0], [](const int e) { return e + 1; });

    return count_if(v.begin(), v.end(), [](const int e) { return 1 < e; });
}
