#include <iostream>

using namespace std;

bool solution(string s);

int main(int argc, char* argv[])
{
    cout << boolalpha << solution("()()") << endl;
    cout << boolalpha << solution("(())()") << endl;
    cout << boolalpha << solution(")()(") << endl;
    cout << boolalpha << solution("(()(") << endl;

    return 0;
}

bool solution(string s)
{
    int n = 0;

    for (char c : s)
    {
        if (c == '(')
            ++n;
        else if (c == ')')
            --n;

        if (n < 0)
            return false;
    }

    return n == 0;
}
