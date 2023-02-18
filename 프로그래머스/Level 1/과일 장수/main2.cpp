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
    size_t size = score.size();

    sort(score.rbegin(), score.rend());

    for (int i = m - 1; i < size; i += m)
        answer += score[i] * m;

    return answer;
}
