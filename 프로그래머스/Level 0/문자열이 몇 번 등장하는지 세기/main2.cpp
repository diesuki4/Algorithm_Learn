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

    for (int pos = myString.find(pat, 0); pos != string::npos; pos = myString.find(pat, ++pos))
        ++answer;

    return answer;
}
