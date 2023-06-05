#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> prices);

int main(int argc, char* argv[])
{
    print(solution({1, 2, 3, 2, 3}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> stck;
    int size = prices.size();

    for (int i = 0; i < size; ++i)
    {
        while (!stck.empty() && prices[i] < prices[stck.top()])
        {
            answer[stck.top()] = i - stck.top();
            stck.pop();
        }

        stck.emplace(i);
    }

    while (!stck.empty())
    {
        answer[stck.top()] = size - stck.top() - 1;
        stck.pop();
    }

    return answer;
}
