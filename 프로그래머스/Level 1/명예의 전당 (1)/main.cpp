#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void print(vector<int> result);
vector<int> solution(int k, vector<int> score);

int main(int argc, char* argv[])
{
    print(solution(3, {10, 100, 20, 150, 1, 100, 200}));
    print(solution(4, {0, 300, 40, 300, 20, 70, 150, 50, 500, 1000}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int k, vector<int> score)
{
    size_t size = score.size();
    vector<int> answer(size);
    priority_queue<int, vector<int>, greater<int>> prque;

    for (int i = 0; i < size; ++i)
    {
        if (prque.size() < k)
        {
            prque.emplace(score[i]);
        }
        else if (prque.top() < score[i])
        {
            prque.pop();
            prque.emplace(score[i]);
        }

        answer[i] = prque.top();
    }

    return answer;
}
