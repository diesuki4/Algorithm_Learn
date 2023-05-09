#include <iostream>

using namespace std;

string solution(string code);

int main(int argc, char* argv[])
{
    cout << solution("abc1abc1abc") << endl;

    return 0;
}

string solution(string code)
{
    bool mode = false;
    size_t len = code.length();
    string answer;

    for (int i = 0; i < len; ++i)
        if (code[i] == '1')
            mode = !mode;
        else if ( (i & 1) == (mode ? 1 : 0) )
            answer += code[i];

    return answer.empty() ? "EMPTY" : answer;
}
