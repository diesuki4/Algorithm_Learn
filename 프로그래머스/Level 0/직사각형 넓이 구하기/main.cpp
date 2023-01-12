#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> dots);

int main(int argc, char* argv[])
{
    cout << solution({{1, 1}, {2, 1}, {2, 2}, {1, 2}}) << endl;
    cout << solution({{-1, -1}, {1, 1}, {1, -1}, {-1, 1}}) << endl;
}

int solution(vector<vector<int>> dots)
{
    vector<int> vecX({dots[0][0], dots[1][0], dots[2][0], dots[3][0]});
    vector<int> vecY({dots[0][1], dots[1][1], dots[2][1], dots[3][1]});

    int minX = *min_element(vecX.begin(), vecX.end());
    int maxX = *max_element(vecX.begin(), vecX.end());

    int minY = *min_element(vecY.begin(), vecY.end());
    int maxY = *max_element(vecY.begin(), vecY.end());

    return (maxX - minX) * (maxY - minY);
}
