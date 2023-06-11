#include <iostream>

using namespace std;

bool rDFS(string s, string& word, int& answer);
int solution(string word);

int main(int argc, char* argv[])
{
    cout << solution("AAAAE") << endl;
    cout << solution("AAAE") << endl;
    cout << solution("I") << endl;
    cout << solution("EIO") << endl;

    return 0;
}

bool rDFS(string s, string& word, int& answer)
{
    const static string alphabets[] = {"A", "E", "I", "O", "U"};

    ++answer;

    if (s == word)
        return true;
    else if (s.length() == 5)
        return false;

    for (const string& alpha : alphabets)
        if (rDFS(s + alpha, word, answer))
            return true;

    return false;
}

int solution(string word)
{
    int answer = 0;
    const string alphabets[] = {"A", "E", "I", "O", "U"};

    for (const string& alpha : alphabets)
        if (rDFS(alpha, word, answer))
            return answer;
}
