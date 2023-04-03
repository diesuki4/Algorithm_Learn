#include <iostream>

using namespace std;

string solution(string number, int k);

int main(int argc, char* argv[])
{
    cout << solution("1924", 2) << endl;
    cout << solution("1231234", 3) << endl;
    cout << solution("4177252841", 4) << endl;
    cout << solution("4321", 1) << endl;

    return 0;
}

string solution(string number, int k)
{
    string answer;
    size_t len = number.length();
    char max = '\0';
    int maxIdx = 0;

    for (int i = 0; i < len; ++i)
    {
        if (max < number[i])
        {
            max = number[i];
            maxIdx = i;
        }

        if (i == k)
        {
            ++k;
            answer.push_back(max);

            i = maxIdx;
            max = '\0';
        }
    }

    return answer;
}
