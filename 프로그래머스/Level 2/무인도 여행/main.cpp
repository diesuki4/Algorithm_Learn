#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void print(vector<int> result);
int rDFS(vector<string>& maps, int r, int c);
vector<int> solution(vector<string> maps);

int main(int argc, char* argv[])
{
    print(solution({"X591X", "X1X5X", "X231X", "1XXX1"}));
    print(solution({"XXX", "XXX", "XXX"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

int rDFS(vector<string>& maps, int r, int c)
{
    size_t H = maps.size(), W = maps.front().length();

    if (r < 0 || c < 0 || H <= r || W <= c || maps[r][c] == 'X')
        return 0;

    char days = maps[r][c];
    maps[r][c] = 'X';

    return  days - '0'
            + rDFS(maps, r - 1, c)
            + rDFS(maps, r, c - 1)
            + rDFS(maps, r + 1, c)
            + rDFS(maps, r, c + 1);
}

vector<int> solution(vector<string> maps)
{
    vector<int> answer;
    size_t H = maps.size(), W = maps.front().length();

    for (int r = 0; r < H; ++r)
        for (int c = 0; c < W; ++c)
            if (isdigit(maps[r][c]))
                answer.emplace_back(rDFS(maps, r, c));

    sort(answer.begin(), answer.end());

    return answer.empty() ? vector<int>{-1} : answer;
}
