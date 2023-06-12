#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(int n, int from, int through, int to);
vector<vector<int>> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(2));
    print(solution(4));

    return 0;
}

void print(vector<vector<int>> result)
{
    for (vector<int>& v : result)
    {
        cout << "[ ";

        for (int e : v)
            cout << e << " ";

        cout << "]";
    }

    cout << endl;
}

vector<vector<int>> solution(int n, int from, int through, int to)
{
    if (n == 1)
        return {{from, to}};

    vector<vector<int>> result = solution(n - 1, from, to, through);

    result.emplace_back(vector<int>{from, to});

    vector<vector<int>> t = solution(n - 1, through, from, to);
    copy(t.begin(), t.end(), back_inserter(result));

    return result;
}

vector<vector<int>> solution(int n)
{
    return solution(n, 1, 2, 3);
}
