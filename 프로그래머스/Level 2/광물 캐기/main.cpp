#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int calculate(int pick, size_t from, vector<string>& minerals);
int rDFS(int diamond, int iron, int stone, size_t from, vector<string>& minerals);
int solution(vector<int> picks, vector<string> minerals);

int main(int argc, char* argv[])
{
    cout << solution({1, 3, 2}, {"diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone"}) << endl;
    cout << solution({0, 1, 1}, {"diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond"}) << endl;

    return 0;
}

int calculate(int pick, size_t from, vector<string>& minerals)
{
    static unordered_map<string, int> cost[3] = {
        {{"diamond", 1},  {"iron", 1}, {"stone", 1}},
        {{"diamond", 5},  {"iron", 1}, {"stone", 1}},
        {{"diamond", 25}, {"iron", 5}, {"stone", 1}}
    };

    int result = 0;

    for (int i = from; i < min(from + 5, minerals.size()); ++i)
        result += cost[pick][minerals[i]];

    return result;
};

int rDFS(int diamond, int iron, int stone, size_t from, vector<string>& minerals)
{
    if (minerals.size() <= from || diamond + iron + stone == 0)
        return 0;

    int result = INT_MAX;

    if (diamond)
        result = min(result, calculate(0, from, minerals) + rDFS(diamond - 1, iron, stone, from + 5, minerals));
    if (iron)
        result = min(result, calculate(1, from, minerals) + rDFS(diamond, iron - 1, stone, from + 5, minerals));
    if (stone)
        result = min(result, calculate(2, from, minerals) + rDFS(diamond, iron, stone - 1, from + 5, minerals));

    return result;
}

int solution(vector<int> picks, vector<string> minerals)
{
    return rDFS(picks[0], picks[1], picks[2], 0, minerals);
}
