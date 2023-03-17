#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons);

int main(int argc, char* argv[])
{
    cout << solution(80, {{80, 20}, {50, 40}, {30, 10}}) << endl;

    return 0;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = -1;

    for (auto it = dungeons.begin(); it != dungeons.end(); ++it)
    {
        if ((*it)[0] <= k)
        {
            auto next_dungeons = dungeons;

            next_dungeons.erase(next_dungeons.begin() + (it - dungeons.begin()));

            answer = max(answer, solution(k - (*it)[1], next_dungeons) + 1);
        }
    }

    return answer;
}
