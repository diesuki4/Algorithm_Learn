#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board);

int main(int argc, char* argv[])
{
    cout << solution(4, 5, {"CCBDE",
                            "AAADE",
                            "AAABF",
                            "CCBBF"}) << endl;

    cout << solution(6, 6, {"TTTANT",
                            "RRFACC",
                            "RRRFCC",
                            "TRRRAA",
                            "TTMMMF",
                            "TMMTTJ"}) << endl;

    cout << solution(10, 10, {"DDABBAABBA",
                              "AAAAAABBBA",
                              "DDACCBBBAA",
                              "DDABBBBBAA",
                              "AAABBABBBA",
                              "CCADDAABBB",
                              "CCADDAABBB",
                              "BBACCABBBA",
                              "BBAAABBBAA",
                              "DDABBBBAAA"}) << endl;

    return 0;
}

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    vector<vector<char>> vv(n + 1, vector<char>(m + 1, '\0'));

    for (int j = 0; j < m; ++j)
        for (int i = 0; i < n; ++i)
            vv[i][j] = board[m - 1 - j][i];

    int nRemoved;

    do
    {
        unordered_set<int> removeCoords;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                char c = vv[i][j];

                if (c == '\0')
                    break;

                if (vv[i][j + 1] == c && vv[i + 1][j] == c && vv[i + 1][j + 1] == c)
                    removeCoords.emplace(i * 100 + j),
                    removeCoords.emplace(i * 100 + (j + 1)),
                    removeCoords.emplace((i + 1) * 100 + j),
                    removeCoords.emplace((i + 1) * 100 + (j + 1));
            }
        }

        answer += nRemoved = removeCoords.size();

        for (int coord : removeCoords)
            vv[coord / 100][coord % 100] = '\0';

        for (vector<char>& v : vv)
            fill(remove(v.begin(), v.end(), '\0'), v.end(), '\0');
    }
    while (nRemoved);
            
    return answer;
}
