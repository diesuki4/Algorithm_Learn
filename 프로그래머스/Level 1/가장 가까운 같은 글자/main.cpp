#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print(vector<int> result);
vector<int> solution(string s);

int main(int argc, char* argv[])
{
    print(solution("banana"));
    print(solution("foobar"));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(string s)
{
    size_t N = s.length();
    vector<int> answer(N);
    unordered_map<char, int> umap;

    for (int i = 0; i < N; ++i)
    {
        if (umap[s[i]] == 0)
            answer[i] = -1;
        else
            answer[i] = i - umap[s[i]] + 1;

        umap[s[i]] = i + 1;
    }

    return answer;
}
