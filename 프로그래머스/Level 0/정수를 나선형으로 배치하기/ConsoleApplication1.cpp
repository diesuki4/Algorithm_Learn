#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(4));
    print(solution(5));

    return 0;
}

void print(vector<vector<int>> result)
{
    for (vector<int>& v : result)
    {
        for (int e : v)
            cout << setw(3) << e << " ";

        cout << endl;
    }

    cout << endl;
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer(n, vector<int>(n));
    int num = 1;
    int r = 0, c = -1;

    for (int j = 0; j < n; ++j)
        answer[r][++c] = num++;

    while (true)
    {
        if (--n <= 0)
            break;

        for (int i = 0; i < n; ++i)
            answer[++r][c] = num++;

        for (int j = n; 0 < j; --j)
            answer[r][--c] = num++;

        if (--n <= 0)
            break;

        for (int i = n; 0 < i; --i)
            answer[--r][c] = num++;

        for (int j = 0; j < n; ++j)
            answer[r][++c] = num++;
    }

    return answer;
}
