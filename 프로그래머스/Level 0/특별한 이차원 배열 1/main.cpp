#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> result);
vector<vector<int>> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(3));
    print(solution(6));
    print(solution(1));

    return 0;
}

void print(vector<vector<int>> result)
{
    for (vector<int>& v : result)
    {
        for (int e : v)
            cout << e << " ";

        cout << endl;
    }
}

vector<vector<int>> solution(int n)
{
    vector<vector<int>> answer(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        ++answer[i][i];

    return answer;
}
