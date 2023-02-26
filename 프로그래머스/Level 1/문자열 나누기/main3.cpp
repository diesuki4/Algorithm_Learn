#include <iostream>

using namespace std;

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("banana") << endl;
    cout << solution("abracadabra") << endl;
    cout << solution("aaabbaccccabba") << endl;

    return 0;
}

int solution(string s)
{
    int answer = 0;
    int count = 0, otherCount = 0;
    int i, j;
    size_t length = s.length();
    
    for (i = 0; i < length; ++i)
    {
        for (j = i; j < length; ++j)
        {
            (s[j] == s[i]) ? ++count : ++otherCount;

            if (count == otherCount)
            {
                count = otherCount = 0;
                i = j;
                ++answer;

                break;
            }
        }
    }

    return answer + (i == j);
}
