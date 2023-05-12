#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2);

int main(int argc, char* argv[])
{
    cout << solution("FRANCE", "french") << endl;
    cout << solution("handshake", "shake hands") << endl;
    cout << solution("aa1+aa2", "AAAA12") << endl;
    cout << solution("zzzz", "zz+zz") << endl;
    cout << solution("E=M*C^2", "e=m*c^2") << endl;

    return 0;
}

int solution(string str1, string str2)
{
    int answer = 0;
    short nUnion = 0, nInter = 0;
    short setA[703] = {0}, setB[703] = {0};

    for (int i = 1; i < str1.length(); ++i)
        if (isalpha(str1[i - 1]) && isalpha(str1[i]))
            ++setA[(str1[i - 1] & 31) * 26 + (str1[i] & 31)];

    for (int i = 1; i < str2.length(); ++i)
        if (isalpha(str2[i - 1]) && isalpha(str2[i]))
            ++setB[(str2[i - 1] & 31) * 26 + (str2[i] & 31)];

    for (int i = 0; i < 703; ++i)
        nUnion += max(setA[i], setB[i]),
        nInter += min(setA[i], setB[i]);

    return nUnion ? (1.f * nInter / nUnion * 65536) : 65536;
}
