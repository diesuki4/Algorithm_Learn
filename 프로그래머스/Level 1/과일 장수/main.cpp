#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score);

int main(int argc, char* argv[])
{
    cout << solution(3, 4, {1, 2, 3, 1, 2, 3, 1}) << endl;
    cout << solution(4, 3, {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2}) << endl;

    return 0;
}

int solution(int k, int m, vector<int> score)
{
    int answer = 0;

    sort(score.rbegin(), score.rend());

    while (m <= score.size())
    {
        answer += score[m - 1] * m;

        score.erase(score.begin(), score.begin() + m);
    }

    return answer;
}
