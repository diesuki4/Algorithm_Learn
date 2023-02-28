#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve);

int main(int argc, char* argv[])
{
    cout << solution(5, {2, 4}, {1, 3, 5}) << endl;
    cout << solution(5, {2, 4}, {3}) << endl;
    cout << solution(3, {3}, {1}) << endl;

    return 0;
}

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int student[31] = {0};

    for (int l : lost)
        --student[l];

    for (int r : reserve)
        ++student[r];

    for (int i = 1; i <= n; ++i)
    {
        if (student[i] == -1)
        {
            if (student[i - 1] == 1)
                student[i - 1] = student[i] = 0;
            else if (student[i + 1] == 1)
                student[i] = student[i + 1] = 0;
        }
    }

    return n - count(student + 1, student + n + 1, -1);
}
