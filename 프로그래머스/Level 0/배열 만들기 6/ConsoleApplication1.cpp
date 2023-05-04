#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr);

int main(int argc, char* argv[])
{
    print(solution({0, 1, 1, 1, 0}));
    print(solution({0, 1, 0, 1, 0}));
    print(solution({0, 1, 1, 0}));

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
    vector<int> answer;

    for (int e : arr)
        if (answer.empty() || answer.back() != e)
            answer.emplace_back(e);
        else
            answer.pop_back();

    return answer.empty() ? vector<int>{-1} : answer;
}
