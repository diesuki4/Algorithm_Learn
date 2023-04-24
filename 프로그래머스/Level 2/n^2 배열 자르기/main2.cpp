#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, long long left, long long right);

int main(int argc, char* argv[])
{
    print(solution(3, 2, 5));
    print(solution(4, 7, 14));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer(right - left + 1);
    int r = left / n;
    int c = left % n;

    do
    {
        answer[answer.size() - (right - left + 1)] = max(++c, r + 1);

        if (c == n)
            ++r, c = 0;
    }
    while (++left <= right);

    return answer;
}
