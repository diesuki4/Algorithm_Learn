#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> numbers);

int main(int argc, char* argv[])
{
    print(solution({2, 3, 3, 5}));
    print(solution({9, 1, 5, 3, 6, 2}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> numbers)
{
    size_t size = numbers.size();
    vector<int> answer(size, -1);
    stack<pair<int, int>> stck;

    for (int i = 0; i < size; ++i)
    {
        int t = i;

        while (stck.empty() == false && stck.top().second < numbers[i])
        {
            answer[stck.top().first] = numbers[i];
            stck.pop();
        }

        stck.emplace(pair<int, int>(i, numbers[i]));
    }

    return answer;
}
