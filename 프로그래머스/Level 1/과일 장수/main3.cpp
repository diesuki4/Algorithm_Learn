#include <iostream>
#include <vector>
#include <queue>

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
    priority_queue<int> prque(score.begin(), score.end());

    while (m <= prque.size())
    {
        int min_score = 0;

        for (int i = 0; i < m; ++i)
        {
            min_score = prque.top();
            prque.pop();
        }

        answer += min_score * m;
    }

    return answer;
}
