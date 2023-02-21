#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling);

int main(int argc, char* argv[])
{
    cout << solution({"aya", "yee", "u", "maa"}) << endl;
    cout << solution({"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"}) << endl;

    return 0;
}

int solution(vector<string> babbling)
{
    int answer = 0;
    unordered_map<string, string> words{{"aya", "0"}, {"ye", "1"}, {"woo", "2"}, {"ma", "3"}};

    for (string s : babbling)
    {
        size_t length = s.length();

        for (pair<string, string> pr : words)
            s = regex_replace(s, regex(pr.first), pr.second);

        if (length == s.length())
            continue;

        length = s.length();
        s = regex_replace(s, regex("[a-z]"), "");

        if (length != s.length())
            continue;

        length = s.length();
        s.erase(unique(s.begin(), s.end()), s.end());

        if (length != s.length())
            continue;

        ++answer;
    }

    return answer;
}
