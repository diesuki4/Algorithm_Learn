// 이 풀이는 시간 초과가 발생한다.
#include <iostream>

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

    for (int len = n; 0 < len; --len)
        for (int ofs = 0; ofs + len <= n; ++ofs)
            if (s.substr(ofs, len) == string(s.rbegin() + n - len - ofs, s.rend() - ofs))
                return len;

    return 0;
}
