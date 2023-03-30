#include <iostream>
#include <stack>

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
    stack<char> stck;

    for (char c : s)
    {
        if (stck.empty() || c == '(')
            stck.emplace(c);
        else
            stck.pop();

        if (!stck.empty())
            if (stck.top() == ')')
                return false;
    }

    return stck.empty();
}
