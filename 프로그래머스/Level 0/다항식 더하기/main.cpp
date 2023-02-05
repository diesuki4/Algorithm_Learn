#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string makePoly(int x, int c);
string solution(string polynomial);

int main(int argc, char* argv[])
{
    cout << solution("3x + 7 + x") << endl;
    cout << solution("x + x + x") << endl;

    return 0;
}

string makePoly(int x, int c)
{
    if (x == 0)
        return to_string(c);
    else
        return (x == 1 ? "" : to_string(x)) + "x" + (c == 0 ? "" : (" + " + to_string(c)));
}

string solution(string polynomial)
{
    istringstream iss(polynomial);
    string s;
    int x = 0, c = 0;

    while (iss >> s)
    {
        size_t length = s.length();

        if (s == "+")
            continue;
        else if (s[length - 1] == 'x')
            x += (length == 1) ? 1 : stoi(s.substr(0, length - 1));
        else
            c += stoi(s);
    }

    return makePoly(x, c);
}
