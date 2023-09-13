#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void print(vector<int> result);
void rDFS(int depth, vector<float>& comb, vector<vector<float>>& result);
vector<int> solution(vector<vector<int>> users, vector<int> emoticons);

int main(int argc, char* argv[])
{
    print(solution({{40, 10000}, {25, 10000}}, {7000, 9000}));
    print(solution({{40, 2900}, {23, 10000}, {11, 5200}, {5, 5900}, {40, 3100}, {27, 9200}, {32, 6900}}, {1300, 1500, 1600, 4900}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

void rDFS(int depth, vector<float>& comb, vector<vector<float>>& result)
{
    if (comb.size() <= depth)
    {
        result.emplace_back(comb);
        return;
    }

    for (float d : {0, 10, 20, 30, 40})
    {
        comb[depth] = d;
        rDFS(depth + 1, comb, result);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    map<int, int> mp;
    vector<float> v(emoticons.size());
    vector<vector<float>> result;

    rDFS(0, v, result);

    for (vector<float>& comb : result)
    {
        int nEmoticonPlus = 0;
        int revenue = 0;

        for (vector<int>& user : users)
        {
            float total = 0;
            bool bEmoticonPlus = false;

            for (int i = 0; i < comb.size(); ++i)
            {
                if (user[0] <= comb[i])
                {
                    total += emoticons[i] * (100 - comb[i]) / 100;

                    if (user[1] <= total)
                    {
                        bEmoticonPlus = true;
                        break;
                    }
                }
            }

            if (bEmoticonPlus)
                ++nEmoticonPlus;
            else
                revenue += total;
        }

        mp[nEmoticonPlus] = max(mp[nEmoticonPlus], revenue);
    }

    return {mp.rbegin()->first, mp.rbegin()->second};
}
