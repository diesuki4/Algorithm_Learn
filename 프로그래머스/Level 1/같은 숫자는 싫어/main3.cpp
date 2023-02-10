#include <iostream>
#include <vector>

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
    vector<int> answer;
    int t = -1;

    for (int e : arr)
    {
        if (t == -1 || t != e)
        {
            t = e;
            answer.emplace_back(t);
        }
    }

    return answer;
}
