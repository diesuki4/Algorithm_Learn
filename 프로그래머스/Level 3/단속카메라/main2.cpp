#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes);

int main(int argc, char* argv[])
{
    cout << solution({{-20, -15}, {-14, -5}, {-18, -13}, {-5, -3}}) << endl;

    return 0;
}

int solution(vector<vector<int>> routes)
{
    int answer = 0;
    int end = -30'001;

    sort(routes.begin(), routes.end());

    for (vector<int>& rt : routes)
    {
        if (end < rt[0])
            end = rt[1],
            ++answer;
        else
            end = min(end, rt[1]);
    }

    return answer;
}
