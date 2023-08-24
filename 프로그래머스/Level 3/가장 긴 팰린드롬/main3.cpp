#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s);

int main(int argc, char* argv[])
{
    cout << solution("abcdcba") << endl;
    cout << solution("abacde") << endl;

    return 0;
}

int solution(string s)
{
    int answer = 1;
    size_t n = s.length();
    vector<vector<bool>> DP(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
        DP[i][i] = true;

    for (int i = 0; i < n - 1; ++i)
        if (DP[i][i + 1] = (s[i] == s[i + 1]))
            answer = 2;

    for (int diff = 2; diff < n; ++diff)
    {
        for (int i = 0; i + diff < n; ++i)
        {
            int j = i + diff;

            if (DP[i + 1][j - 1] && (s[i] == s[j]))
            {
                DP[i][j] = true;
                answer = max(answer, diff + 1);
            }
        }
    }

    return answer;
}
