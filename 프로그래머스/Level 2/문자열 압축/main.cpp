#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string compress(string& s, int n);
int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("aabbaccc") << endl;
    cout << solution("ababcdcdababcdcd") << endl;
    cout << solution("abcabcdede") << endl;
    cout << solution("abcabcabcabcdededededede") << endl;
    cout << solution("xababcdcdababcdcd") << endl;

    return 0;
}

string compress(string& s, int n)
{
    vector<string> v;

    for (int pos = 0; pos < s.length(); pos += n)
        v.emplace_back(s.substr(pos, n));

    v.emplace_back("0");

    string result, current = v.front();
    int cnt = 0;

    for (string& str : v)
    {
        if (str == current)
        {
            ++cnt;
        }
        else
        {
            result += (cnt <= 1) ? "" : to_string(cnt);
            result += current;

            current = str;
            cnt = 1;
        }
    }

    return result;
}

int solution(string s)
{
    size_t answer = s.length();
    int last = answer * 0.5f;

    for (int i = 1; i <= last; ++i)
        answer = min(compress(s, i).length(), answer);

    return answer;
}
