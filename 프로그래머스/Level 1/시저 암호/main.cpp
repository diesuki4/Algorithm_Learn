#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s, int n);

int main(int argc, char* argv[])
{
    cout << solution("AB", 1) << endl;
    cout << solution("z", 1) << endl;
    cout << solution("a B z", 4) << endl;

    return 0;
}

string solution(string s, int n)
{
    transform(s.begin(), s.end(), s.begin(), [n](char c) -> char
    {
        if (!isalpha(c))
            return c;
        
        return isupper(c) ? 'A' + (c + n - 'A') % 26 : 'a' + (c + n - 'a') % 26;
    });

    return s;
}
