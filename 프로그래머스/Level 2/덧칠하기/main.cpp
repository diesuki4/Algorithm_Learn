#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section);

int main(int argc, char* argv[])
{
    cout << solution(8, 4, {2, 3, 6}) << endl;
    cout << solution(5, 4, {1, 3}) << endl;
    cout << solution(4, 1, {1, 2, 3, 4}) << endl;

    return 0;
}

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    vector<bool> paints(n + 1, true);
    vector<bool>::iterator it = paints.begin() + section.front();

    for (int sec : section)
        paints[sec] = false;

    while ((it = find(it, paints.end(), false)) != paints.end())
    {
        vector<bool>::iterator last = (paints.end() - m <= it) ? paints.end() : it + m;

        replace(it, last, false, true);

        ++answer;
    }

    return answer;
}
