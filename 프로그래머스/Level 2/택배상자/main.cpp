#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order);

int main(int argc, char* argv[])
{
    cout << solution({4, 3, 1, 2, 5}) << endl;
    cout << solution({5, 4, 3, 2, 1}) << endl;

    return 0;
}

int solution(vector<int> order)
{
    int answer = 0;
    size_t n = order.size();
    stack<int> stck;

    for (int i = 1; i <= n; ++i)
    {
        stck.emplace(i);

        while (!stck.empty() && stck.top() == order[answer])
        {
            ++answer;
            stck.pop();
        }
    }

    return answer;
}
