// 이 코드는 틀린 풀이이다.
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>

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
    unordered_map<char, int> umap;

    for (int i = 0; i < s.length(); ++i)
    {
        ++umap[s[i]];

        int minCount = INT_MAX;
        
        for (pair<char, int> pr : umap)
        {
            if (pr.second == minCount)
            {
                s = s.substr(i + 1);
                ++answer;
                umap.clear();
                i = -1;

                break;
            }
            else
            {
                minCount = min(minCount, pr.second);
            }
        }
    }

    return answer + !!s.length();
}
