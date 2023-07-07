#include <iostream>

using namespace std;

bool is_balanced(string s);
bool is_right(string s);
string solution(string w);

int main(int argc, char* argv[])
{
    cout << solution("(()())()") << endl;
    cout << solution(")(") << endl;
    cout << solution("()))((()") << endl;

    return 0;
}

bool is_balanced(string s)
{
    int n = 0;

    for (char c : s)
        (c == '(') ? ++n : --n;

    return (n == 0);
}

bool is_right(string s)
{
    int n = 0;

    for (char c : s)
    {
        if (n == 0 || c == '(')
            ++n;
        else if (0 < n)
            --n;
        else
            return false;
    }

    return (n == 0);
}

string solution(string w)
{
    // 1
    if (w.empty())
        return w;

    // 2
    int i = 2;

    while (!is_balanced(w.substr(0, i)))
        i += 2;

    string u = w.substr(0, i), v = w.substr(i);

    // 3
    if (is_right(u))
    {
        v = solution(v);

        // 3-1
        return u + v;
    }

    // 4
    // 4-1
    string t = "(";

    // 4-2
    t += solution(v);

    // 4-3
    t += ")";

    // 4-4
    u.erase(0, 1);
    u.pop_back();
    for (char& c : u) c = (c == '(') ? ')' : '(';
    t += u;

    // 4-5
    return t;
}
