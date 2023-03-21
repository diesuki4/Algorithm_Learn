#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

#define index(v, val) find((v).begin(), (v).end(), (val)) - (v).begin()

using namespace std;

void print(vector<int> result);
vector<int> solution(string s);

int main(int argc, char* argv[])
{
    print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"));
    print(solution("{{1,2,3},{2,1},{1,2,4,3},{2}}"));
    print(solution("{{20,111},{111}}"));
    print(solution("{{123}}"));
    print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"));

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
    vector<int> answer;
    vector<int> counts;
    int* arr = new int[100'001]();
    string tmp;

    for (char c : s)
        if (isdigit(c))
            tmp += c;
        else if (0 < tmp.length())
            ++arr[stoi(tmp)],
            tmp.clear();

    for (int i = 0; i < 100'001; ++i)
        if (0 < arr[i])
            answer.emplace_back(i),
            counts.emplace_back(arr[i]);
    
    vector<int> t = answer;
    auto pred = [&](int a, int b) { return counts[index(t, a)] > counts[index(t, b)]; };
    sort(answer.begin(), answer.end(), pred);

    delete[] arr;
    arr = nullptr;

    return answer;
}
