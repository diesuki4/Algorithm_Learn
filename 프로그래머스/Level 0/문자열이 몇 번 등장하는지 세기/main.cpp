#include <iostream>

using namespace std;

int solution(string myString, string pat);

int main(int argc, char* argv[])
{
    cout << solution("banana", "ana") << endl;
    cout << solution("aaaa", "aa") << endl;

    return 0;
}

int solution(string myString, string pat)
{
    int answer = 0;
    size_t len = myString.length(), lenPat = pat.length();

    for (int i = 0; i <= len - lenPat; ++i)
        answer += (myString.substr(i, lenPat) == pat);

    return answer;
}
