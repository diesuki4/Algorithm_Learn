// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> stones, int k);

int main(int argc, char* argv[])
{
    cout << solution({2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3) << endl;

    return 0;
}

int solution(vector<int> stones, int k)
{
    int answer = INT_MAX;

    for (auto it = stones.begin(); it != stones.end() - k + 1; ++it)
        answer = min(answer, *max_element(it, it + k));

    return answer;
}
