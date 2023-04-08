#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> progresses, vector<int> speeds);

int main(int argc, char* argv[])
{
    print(solution({93, 30, 55}, {1, 30, 5}));
    print(solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    size_t size = progresses.size();
    vector<int> answer;

    auto func = [&](int a, int b) { return ceil((100.f - a) / b); };
    transform(progresses.begin(), progresses.end(), speeds.begin(), progresses.begin(), func);

    int maxIdx = 0, day = 0;

    for (int i = 0; i < size; ++i, ++day)
    {
        if (progresses[maxIdx] < progresses[i])
        {
            answer.emplace_back(day);
            maxIdx = i;
            day = 0;
        }
    }

    answer.emplace_back(day);

    return answer;
}
