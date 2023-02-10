#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr);

int main(int argc, char* argv[])
{
    print(solution({1, 1, 3, 3, 0, 1, 1}));
    print(solution({4, 4, 4, 3, 3}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr)
{
    stack<int> stck;
    vector<int> answer;

    for (int e : arr)
    {
        if (stck.empty())
        {
            stck.emplace(e);
            answer.emplace_back(e);
        }
        else if (stck.top() != e)
        {
            stck.pop();
            stck.emplace(e);
            answer.emplace_back(e);
        }
    }

    return answer;
}
