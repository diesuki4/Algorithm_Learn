#include <iostream>

using namespace std;

string solution(int q, int r, string code);

int main(int argc, char* argv[])
{
    cout << solution(3, 1, "qjnwezgrpirldywt") << endl;
    cout << solution(1, 0, "programmers") << endl;

    return 0;
}

string solution(int q, int r, string code)
{
    string answer;

    for (int i = 0; i < code.length(); ++i)
        if (i % q == r)
            answer.emplace_back(code[i]);

    return answer;
}
