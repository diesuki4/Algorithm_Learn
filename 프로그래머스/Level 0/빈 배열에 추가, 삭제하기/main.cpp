#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<int> arr, vector<bool> flag);

int main(int argc, char* argv[])
{
    print(solution({3, 2, 4, 1, 3}, {true, false, true, false, false}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<int> arr, vector<bool> flag)
{
    size_t size = arr.size();
    vector<int> answer;

    for (int i = 0; i < size; ++i)
    {
        if (flag[i])
        {
            vector<int> v(arr[i] * 2, arr[i]);

            answer.insert(answer.end(), v.begin(), v.end());
        }
        else
        {
            answer.erase(answer.end() - arr[i], answer.end());
        }
    }

    return answer;
}
