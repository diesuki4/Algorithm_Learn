// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

void print(vector<string> result);
vector<string> get_combinations(map<char, bool>& mp, int start, int n);
bool belongs(string& A, string& B);
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

vector<string> get_combinations(map<char, bool>& mp, int start, int n)
{
    if (n == 0)
        return { "" };

    vector<string> result;

    for (int i = start; i <= mp.size() - n; ++i)
    {
        char c = next(mp.begin(), i)->first;

        for (string sub : get_combinations(mp, i + 1, n - 1))
            result.emplace_back(string(1, c) + sub);
    }

    return result;
}

bool belongs(string& A, string& B)
{
    unordered_map<char, bool> umapB;

    for (char c : B)
        umapB[c] = true;

    for (char c : A)
        if (!umapB[c]) return false;

    return true;
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    set<string> answer;
    map<char, bool> mp;

    for (string& order : orders)
        for (char c : order)
            mp[c] = true;

    for (int n : course)
    {
        map<int, vector<string>> menus;

        for (string comb : get_combinations(mp, 0, n))
        {
            int nBelongs = 0;

            for (string& order : orders)
                nBelongs += belongs(comb, order);

            if (2 <= nBelongs)
                menus[nBelongs].emplace_back(comb);
        }

        if (0 < menus.size())
            for (string& menu : menus.rbegin()->second)
                answer.emplace(menu);
    }

    return vector<string>(answer.begin(), answer.end());
}
