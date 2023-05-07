#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n);

int main(int argc, char* argv[])
{
    print(solution(4));
    print(solution(5));
    print(solution(6));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n)
{
    vector<int> answer((n + 1) * n / 2);
    vector<vector<int>> vv(n, vector<int>(n, -1));
    int dx[] = {0, 1, -1};
    int dy[] = {1, 0, -1};
    int num = 1, dcur = 0;
    int x = 0, y = -1;

    do 
    {
        for (int i = 0; i < n; ++i)
            vv[y += dy[dcur]][x += dx[dcur]] = num++;

        dcur = ++dcur % 3;
    }
    while (n--);

    num = 0;

    for (vector<int>& v : vv)
        for (int e : v)
            if (e != -1)
                answer[num++] = e;
            else
                break;

    return answer;
}
