#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> wallpaper);

int main(int argc, char* argv[])
{
    print(solution({".#...", "..#..", "...#."}));
    print(solution({"..........", ".....#....", "......##..", "...##.....", "....#....."}));
    print(solution({".##...##.", "#..#.#..#", "#...#...#", ".#.....#.", "..#...#..", "...#.#...", "....#...."}));
    print(solution({"..", "#."}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> wallpaper)
{
    int lux = INT_MAX, luy = INT_MAX;
    int rdx = INT_MIN, rdy = INT_MIN;
    int width = wallpaper.front().size(), height = wallpaper.size();
    int x, pos;

    for (x = 0; x < height; ++x)
        if (wallpaper[x].find('#') != string::npos)
            break;

    lux = x;

    for (x = 0; x < height; ++x)
        if ((pos = wallpaper[x].find('#')) != string::npos)
            luy = min(luy, pos);

    for (x = height - 1; 0 <= x; --x)
        if (wallpaper[x].rfind('#') != string::npos)
            break;

    rdx = x + 1;

    for (x = height - 1; 0 <= x; --x)
        if ((pos = wallpaper[x].rfind('#')) != string::npos)
            rdy = max(rdy, pos + 1);

    return vector<int>{lux, luy, rdx, rdy};
}
