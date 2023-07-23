#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void print(vector<string> result);
void combination(map<string, int>& mp, string src, string crs, int depth);
vector<string> solution(vector<string> orders, vector<int> course);

int main(int argc, char* argv[])
{
    print(solution({"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"}, {2, 3, 4}));
    print(solution({"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"}, {2, 3, 5}));
    print(solution({"XYZ", "XWY", "WXA"}, {2, 3, 4}));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

void combination(map<string, int>& mp, string src, string crs, int depth)
{
    if (crs.length() == depth)
    {
        ++mp[crs];

        return;
    }

    for (int i = 0; i < src.length(); ++i)
        combination(mp, src.substr(i + 1), crs + src[i], depth);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    set<string> answer;

    for (string& order : orders)
        sort(order.begin(), order.end());

    for (int crs : course)
    {
        int sup = 0;
        map<string, int> mp;

        for (string order : orders)
            combination(mp, order, "", crs);

        for (auto it : mp)
            sup = max(sup, it.second);

        for (auto it : mp)
            if (2 <= sup && it.second == sup)
                answer.emplace(it.first);
    }

    return vector<string>(answer.begin(), answer.end());
}
