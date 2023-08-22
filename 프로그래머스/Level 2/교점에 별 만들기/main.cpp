#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print(vector<string> result);
struct Point;
bool intersection_point(vector<int>& line1, vector<int>& line2, Point& result);
vector<string> solution(vector<vector<int>> line);

int main(int argc, char* argv[])
{
    print(solution({{2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12}}));
    print(solution({{0, 1, -1}, {1, 0, -1}, {1, 0, 1}}));
    print(solution({{1, -1, 0}, {2, -1, 0}}));
    print(solution({{1, -1, 0}, {2, -1, 0}, {4, -1, 0}}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << endl;
}

struct Point
{
    long x;
    long y;
};

bool intersection_point(vector<int>& line1, vector<int>& line2, Point& result)
{
    long ad_bc = long(line1[0]) * line2[1] - long(line1[1]) * line2[0];

    if (ad_bc == 0)
        return false;

    long bf_ed = long(line1[1]) * line2[2] - long(line1[2]) * line2[1];
    long ec_af = long(line1[2]) * line2[0] - long(line1[0]) * line2[2];

    if ((bf_ed % ad_bc) || (ec_af % ad_bc))
        return false;

    result.x = bf_ed / ad_bc;
    result.y = ec_af / ad_bc;

    return true;
}

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    size_t n = line.size();

    long minX = LONG_MAX, minY = LONG_MAX, maxX = LONG_MIN, maxY = LONG_MIN;
    vector<Point> intsctPoints;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            Point result;

            if (intersection_point(line[i], line[j], result))
            {
                minX = min(minX, result.x);
                minY = min(minY, result.y);

                maxX = max(maxX, result.x);
                maxY = max(maxY, result.y);

                intsctPoints.emplace_back(result);
            }
        }
    }

    answer = vector<string>(maxY - minY + 1, string(maxX - minX + 1, '.'));

    for (Point& p : intsctPoints)
        answer[maxY - p.y][p.x - minX] = '*';

    return answer;
}
