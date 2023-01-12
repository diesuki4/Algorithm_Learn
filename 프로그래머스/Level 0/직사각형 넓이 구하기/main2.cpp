#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots);

int main(int argc, char* argv[])
{
    cout << solution({{1, 1}, {2, 1}, {2, 2}, {1, 2}}) << endl;
    cout << solution({{-1, -1}, {1, 1}, {1, -1}, {-1, 1}}) << endl;
}

int solution(vector<vector<int>> dots)
{
    sort(dots.begin(), dots.end());

    return (dots[3][0] - dots[0][0]) * (dots[3][1] - dots[0][1]);
}
