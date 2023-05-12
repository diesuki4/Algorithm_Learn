#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

int solution(string str1, string str2);

int main(int argc, char* argv[])
{
    cout << solution("FRANCE", "french") << endl;
    cout << solution("handshake", "shake hands") << endl;
    cout << solution("aa1+aa2", "AAAA12") << endl;
    cout << solution("E=M*C^2", "e=m*c^2") << endl;

    return 0;
}

int solution(string str1, string str2)
{
    int answer = 0;
    int nUnion = 0, nInter = 0;
    vector<int> setA(676, 0), setB(676, 0);

    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);

    for (int i = 0; i < str1.length() - 1; ++i)
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            ++setA[(str1[i] - 'A') * 26 + (str1[i + 1] - 'A')];

    for (int i = 0; i < str2.length() - 1; ++i)
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            ++setB[(str2[i] - 'A') * 26 + (str2[i + 1] - 'A')];

    for (int i = 0; i < 676; ++i)
        nUnion += max(setA[i], setB[i]),
        nInter += min(setA[i], setB[i]);

    return nUnion ? (1.f * nInter / nUnion * 65536) : 65536;
}
