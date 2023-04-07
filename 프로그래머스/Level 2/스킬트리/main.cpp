#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

int solution(string skill, vector<string> skill_trees);

int main(int argc, char* argv[])
{
    cout << solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"}) << endl;

    return 0;
}

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    map<char, int> mp;

    for (int i = 0; i < skill.length(); ++i)
        mp[skill[i]] = i + 1;

    for (string& sk_tree : skill_trees)
    {
        char last = '\0';
        bool bSuccess = true;

        for (char c : sk_tree)
        {
            if (mp[c] - 1 == mp[last])
            {
                if (c == mp.rbegin()->first)
                    break;
                else
                    last = c;
            }
            else if (mp[c])
            {
                bSuccess = false;
                break;
            }
        }

        if (bSuccess)
            ++answer;
    }

    return answer;
}
