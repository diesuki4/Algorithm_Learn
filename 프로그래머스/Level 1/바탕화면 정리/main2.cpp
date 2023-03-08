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

    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {
            if (wallpaper[x][y] == '#')
            {
                lux = min(lux, x);
                luy = min(luy, y);
                rdx = max(rdx, x + 1);
                rdy = max(rdy, y + 1);
            }
        }
    }

    return vector<int>{lux, luy, rdx, rdy};
}
