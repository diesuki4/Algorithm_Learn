#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> gems);

int main(int argc, char* agv[])
{
    print(solution({"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"}));
    print(solution({"AA", "AB", "AC", "AA", "AC"}));
    print(solution({"XYZ", "XYZ", "XYZ"}));
    print(solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    unordered_map<string, int> umap, current;
    size_t n = gems.size();
    int minLen = n;

    for (string& gem : gems)
        ++umap[gem];

    for (int s = 0, e = 0; e < n; ++e)
    {
        ++current[gems[e]];

        if (current.size() == umap.size())
        {
            while (2 <= current[gems[s]])
                --current[gems[s++]];

            int len = e - s;

            if (len < minLen)
            {
                minLen = len;
                answer = {s + 1, e + 1};
            }
        }
    }

    return answer;
}
