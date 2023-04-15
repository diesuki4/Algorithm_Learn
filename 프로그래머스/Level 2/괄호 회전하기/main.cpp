#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("[](){}") << endl;
    cout << solution("}]()[{") << endl;
    cout << solution("[)(]") << endl;
    cout << solution("}}}") << endl;

    return 0;
}

int solution(string s)
{
    int answer = 0;
    size_t len = s.length();

    auto check = [](string& s) -> bool
    {
        stack<char> stck;

        for (char c : s)
        {
            if (stck.empty() || c == '(' || c == '{' || c == '[')
                stck.emplace(c);
            else if ((stck.top() == '(' && c == ')') || (stck.top() == '{' && c == '}') || (stck.top() == '[' && c == ']'))
                stck.pop();

            if (!stck.empty())
                if (stck.top() == ')' || stck.top() == '}' || stck.top() == ']')
                    return false;
        }

        return stck.empty();
    };

    while (--len)
    {
        answer += check(s);

        rotate(s.begin(), s.begin() + 1, s.end());
    }

    return answer;
}
