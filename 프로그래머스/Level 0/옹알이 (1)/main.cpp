#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int solution(vector<string> babbling);

int main(int argc, char* argv[])
{
    cout << solution({"aya", "yee", "u", "maa", "wyeoo"}) << endl;
    cout << solution({"ayaye", "uuuma", "ye", "yemawoo", "ayaa"}) << endl;

    return 0;
}

int solution(vector<string> babbling)
{
    int answer = 0;

    for (string s : babbling)
    {
        size_t length = s.length();
        vector<string> words = {"aya", "ye", "woo", "ma"};

        for (string word : words)
            s = regex_replace(s, regex(word), string(word.length(), '_'), regex_constants::format_first_only);

        answer += (s == string(length, '_'));
    }

    return answer;
}
