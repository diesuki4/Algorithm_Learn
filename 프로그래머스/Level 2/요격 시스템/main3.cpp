#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets);

int main(int argc, char* argv[])
{
    cout << solution({{4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4}}) << endl;

    return 0;
}

int solution(vector<vector<int>> targets)
{
    sort(targets.begin(), targets.end(), [](auto& t1, auto& t2) { return t1[1] < t2[1]; });

    int answer = 1;
    int e = targets.front()[1];

    for (vector<int>& t : targets)
        if (e <= t[0])
            ++answer,
            e = t[1];

    return answer;
}
