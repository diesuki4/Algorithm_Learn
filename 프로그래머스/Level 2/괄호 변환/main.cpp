#include <iostream>
#include <stack>

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
    int numOpen = 0, numClose = 0;

    for (char c : s)
        numOpen += (c == '('),
        numClose += (c == ')');

    return (numOpen == numClose);
}

bool is_right(string s)
{
    stack<char> stck;
    int nOpen = 0, nClose = 0;

    for (char c : s)
    {
        nOpen += (c == '(');
        nClose += (c == ')');

        if (stck.empty() || c == '(')
            stck.emplace(c);
        else if (stck.top() == '(')
            stck.pop();
        else
            return false;
    }

    return stck.empty() && (nOpen == nClose);
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
