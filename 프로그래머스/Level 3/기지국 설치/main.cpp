#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<int> stations, int w);

int main(int argc, char* argv[])
{
    cout << solution(11, {4, 11}, 1) << endl;
    cout << solution(16, {9}, 2) << endl;

    return 0;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    vector<int> section;

    for (int st : stations)
    {
        section.emplace_back(st - w - start);
        start = st + w + 1;
    }

    if (start <= n)
        section.emplace_back(n + 1 - start);

    float W = w + 1 + w;

    for (int sec : section)
        answer += ceil(sec / W);

    return answer;
}
