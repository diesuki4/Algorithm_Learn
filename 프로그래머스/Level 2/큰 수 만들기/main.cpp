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
    size_t len = number.length();
    string answer;

    for (int i = 0; i < len; ++i)
    {
        if (k == 0 || answer.empty() || answer.back() >= number[i])
        {
            if (i + k < len)
                answer.push_back(number[i]);
        }
        else
        {
            while (0 < k && !answer.empty() && answer.back() < number[i])
            {
                answer.pop_back();
                --k;
            }

            answer.push_back(number[i]);
        }
    }

    return answer;
}
