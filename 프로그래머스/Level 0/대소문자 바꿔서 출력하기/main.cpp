#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

string solution(string s);

int main(int argc, char* argv[])
{
    string s;

    cin >> s;
    cout << solution(s);

    return 0;
}

string solution(string s)
{
    for_each(s.begin(), s.end(), [](char& c){ c = isupper(c) ? tolower(c) : toupper(c); });

    return s;
}
