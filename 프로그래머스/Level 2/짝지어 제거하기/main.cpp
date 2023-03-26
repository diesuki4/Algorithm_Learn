#include <iostream>

using namespace std;

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("baabaa") << endl;
    cout << solution("cdcd") << endl;

    return 0;
}

int solution(string s)
{
    auto find_pair = [](string& s) -> size_t
    {
        size_t len = s.length() - 1;

        for (int i = 0; i < len; ++i)
            if (s[i] == s[i + 1])
                return i;

        return string::npos;
    };

    s += '0';

    for (size_t pos = find_pair(s); pos != string::npos; pos = find_pair(s))
        s.erase(pos, 2);

    return (s == "0");
}
