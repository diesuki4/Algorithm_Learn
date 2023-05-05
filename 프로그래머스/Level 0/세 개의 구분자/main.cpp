#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void print(vector<string> result);
vector<string> solution(string myStr);

int main(int argc, char* argv[])
{
    print(solution("baconlettucetomato"));
    print(solution("abcd"));
    print(solution("cabab"));

    return 0;
}

void print(vector<string> result)
{
    for (string& s : result)
        cout << s << " ";

    cout << endl;
}

vector<string> solution(string myStr)
{
    vector<string> answer;
    const char *str = myStr.c_str(), *delim = "abc";
    char *s = new char[strlen(str) + 1], *p;

    copy(str, str + strlen(str) + 1, s);
    p = strtok(s, delim);

    while (p)
    {
        answer.emplace_back(p);

        p = strtok(nullptr, delim);
    }

    delete s;

    return answer.empty() ? vector<string>{"EMPTY"} : answer;
}
