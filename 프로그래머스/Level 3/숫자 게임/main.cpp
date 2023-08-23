#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B);

int main(int argc, char* argv[])
{
    cout << solution({5,1,3,7}, {2,2,6,8}) << endl;
    cout << solution({2,2,2,2}, {1,1,1,1}) << endl;

    return 0;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pqA, pqB;

    for (int num : A) pqA.emplace(num);
    for (int num : B) pqB.emplace(num);

    while (!pqB.empty())
    {
        if (pqA.top() < pqB.top())
            ++answer,
            pqA.pop();

        pqB.pop();
    }

    return answer;
}
