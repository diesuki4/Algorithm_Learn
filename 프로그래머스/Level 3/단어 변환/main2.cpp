#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

bool canConvert(string& a, string& b);
int solution(string begin, string target, vector<string> words);

int main(int argc, char* argv[])
{
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}) << endl;
    cout << solution("hit", "cog", {"hot", "dot", "dog", "lot", "log"}) << endl;

    return 0;
}

bool canConvert(string& a, string& b)
{
    static const int DIFF = 1;
    int diff = 0;

    for (int i = 0; i < a.length(); ++i)
        diff += (a[i] != b[i]);

    return (diff == DIFF);
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    queue<pair<int, string>> que;
    vector<bool> isUsed(words.size(), false);

    que.push({0, begin});

    while (!que.empty())
    {
        int level = que.front().first;
        string s = que.front().second;
        que.pop();

        if (s == target)
            return level;

        for (int i = 0; i < words.size(); ++i)
        {
            if (!isUsed[i] && canConvert(s, words[i]))
            {
                isUsed[i] = true;
                que.push({level + 1, words[i]});
            }
        }
    }
    
    return 0;
}
