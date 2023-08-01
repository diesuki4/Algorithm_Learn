#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <regex>

using namespace std;

void rDFS(vector<vector<string>>& candidates, set<string> current, set<set<string>>& result);
int solution(vector<string> user_id, vector<string> banned_id);

int main(int argc, char* argv[])
{
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "abc1**"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"*rodo", "*rodo", "******"}) << endl;
    cout << solution({"frodo", "fradi", "crodo", "abc123", "frodoc"}, {"fr*d*", "*rodo", "******", "******"}) << endl;

    return 0;
}

void rDFS(vector<vector<string>>& candidates, set<string> current, set<set<string>>& result)
{
    if (candidates.size() <= current.size())
    {
        result.emplace(current);
        return;
    }

    for (string& s : candidates[current.size()])
    {
        if (current.find(s) != current.end())
            continue;

        set<string> st(current);
        st.emplace(s);

        rDFS(candidates, st, result);
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    vector<vector<string>> candidates;

    for (string& bnid : banned_id)
    {
        replace(bnid.begin(), bnid.end(), '*', '.');

        candidates.resize(candidates.size() + 1);

        for (string& usid : user_id)
            if (regex_match(usid, regex(bnid)))
                candidates.back().emplace_back(usid);
    }

    set<set<string>> result;

    rDFS(candidates, {}, result);

    return result.size();
}
