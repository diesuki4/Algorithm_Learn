// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, long long k);

int main(int argc, char* argv[])
{
    print(solution(3, 5));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, long long k)
{
    vector<int> answer(n);

    iota(answer.begin(), answer.end(), 1);

    while (--k)
        next_permutation(answer.begin(), answer.end());

    return answer;
}
