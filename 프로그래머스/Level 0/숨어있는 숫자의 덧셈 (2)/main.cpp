#include <iostream>

using namespace std;

int solution(string my_string);

int main(int argc, char* argv[])
{
    cout << solution("aAb1B2cC34oOp") << endl;
    cout << solution("1a2b3c4d123Z") << endl;
}

int solution(string my_string)
{
    int t = 1;
    int answer = 0;

    for (string::reverse_iterator rit = my_string.rbegin(); rit != my_string.rend(); ++rit)
    {
        if (isdigit(*rit))
        {
            answer += (*rit - '0') * t;
            t *= 10;
        }
        else
        {
            t = 1;
        }
    }

    return answer;
}
