#include <iostream>

using namespace std;

int solution(string word);

int main(int argc, char* argv[])
{
    cout << solution("AAAAE") << endl;
    cout << solution("AAAE") << endl;
    cout << solution("I") << endl;
    cout << solution("EIO") << endl;

    return 0;
}

int solution(string word)
{
    string s("AEIOU");
    int n = word.size(), answer(n);

    for (int i = 0, b = 1; i < n; ++i, b *= 5)
        answer += s.rfind(word[i]) * 781 / b;

    return answer;
}
