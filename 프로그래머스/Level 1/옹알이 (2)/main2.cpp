#include <iostream>
#include <vector>

using namespace std;

int solution(vector<string> babbling);

int main(int argc, char* argv[])
{
    cout << solution({"aya", "yee", "u", "maa"}) << endl;
    cout << solution({"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"}) << endl;

    return 0;
}

int solution(vector<string> babbling)
{
    int answer = 0;

    for (string s : babbling)
    {
        char flag = '\0';
        bool isPronounceable = true;
        size_t length = s.length();

        for (int i = 0; i < length; ++i)
        {
            if (s.substr(i, 3) == "aya" && flag != 'a')
                flag = 'a', i += 2;
            else if (s.substr(i, 2) == "ma" && flag != 'm')
                flag = 'm', i += 1;
            else if (s.substr(i, 3) == "woo" && flag != 'w')
                flag = 'w', i += 2;
            else if (s.substr(i, 2) == "ye" && flag != 'y')
                flag = 'y', i += 1;
            else {
                isPronounceable = false; break; }
        }

        if (isPronounceable)
            ++answer;
    }

    return answer;
}
