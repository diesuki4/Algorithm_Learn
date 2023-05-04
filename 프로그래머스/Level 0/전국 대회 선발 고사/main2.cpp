#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance);

int main(int argc, char* argv[])
{
    cout << solution({3, 7, 2, 5, 4, 6, 1}, {false, true, true, true, true, false, false}) << endl;
    cout << solution({1, 2, 3}, {true, true, true}) << endl;
    cout << solution({6, 1, 5, 2, 3, 4}, {true, false, true, false, false, true}) << endl;

    return 0;
}

int solution(vector<int> rank, vector<bool> attendance)
{
    int answer = 0, cur = 0;
    int arr[] = {10'000, 100, 1};
    size_t size = rank.size();
    vector<int> v(size + 1);

    for (int i = 0; i < size; ++i)
        v[rank[i]] = attendance[i] ? i : -1;

    for (int i = 1; i <= size; ++i)
    {
        if (v[i] != -1)
        {
            answer += arr[cur++] * v[i];

            if (cur == 3)
                break;
        }
    }

    return answer;
}
