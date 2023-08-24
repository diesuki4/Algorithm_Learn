#include <iostream>
#include <algorithm>

using namespace std;

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("abcdcba") << endl;
    cout << solution("abacde") << endl;

    return 0;
}

int solution(string s)
{
    int answer = 0;
    size_t n = s.length();

    for (int i = 0; i < n; ++i)
    {
        int l = i, r = i;

        while ((0 <= l) && (r < n) && (s[l] == s[r]))
            --l, ++r;

        answer = max(answer, r - l - 1);

        l = i, r = i + 1;

        while ((0 <= l) && (r < n) && (s[l] == s[r]))
            --l, ++r;

        answer = max(answer, r - l - 1);
    }

    return answer;
}
