#include <iostream>
#include <unordered_map>

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
    int sum = 0;
    size_t length = s.length();
    unordered_map<char, int> umap;

    for (int i = 0; i < length; ++i)
    {
        ++sum;
        ++umap[s[i]];

        for (pair<char, int> pr : umap)
        {
            if (pr.second == sum - pr.second)
            {
                ++answer;
                sum = 0;
                umap.clear();

                break;
            }
        }
    }

    return answer + !!sum;
}
