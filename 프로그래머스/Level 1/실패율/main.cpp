#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
float failure_rate(vector<int>& reached_users, int i);
vector<int> solution(int N, vector<int> stages);

int main(int argc, char* argv[])
{
    print(solution(5, {2, 1, 2, 6, 2, 4, 3, 3}));
    print(solution(4, {4, 4, 4, 4, 4}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

// i+1번째 스테이지에 도달한 사람 = i번째 스테이지를 클리어한 사람
// (i번째 스테이지에 도달한 사람 - i번째 스테이지를 클리어한 사람) / i번째 스테이지에 도달한 사람
// i번째 스테이지에 있는 사람 / i번째 스테이지에 도달한 사람
float failure_rate(vector<int>& reached_users, int i)
{
    if (reached_users[i])
        return (reached_users[i] - reached_users[i + 1]) / (float)reached_users[i];
    else
        return 0.0f;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer(N);
    vector<int> reached_users(N + 2, 0);

    for (int i = 1; i <= N; ++i)
        answer[i - 1] = i;

    // 각 스테이지별 도달한 사람 수 계산
    for (int stage : stages)
        for (int i = 1; i <= stage; ++i)
            ++reached_users[i];

    // 실패율을 기준으로 정렬
    // answer의 원소들이 인덱스를 뜻하므로 reached_users에 전달해 실패율을 기준으로 정렬할 수 있다.
    auto func = [&reached_users](int a, int b) { return failure_rate(reached_users, a) > failure_rate(reached_users, b); };
    stable_sort(answer.begin(), answer.end(), func);

    return answer;
}
