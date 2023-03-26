#include <iostream>
#include <stack>

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
    stack<char> stck;

    for (char c : s)
        if (!stck.empty() && stck.top() == c)
            stck.pop();
        else
            stck.emplace(c);

    return stck.empty();
}
