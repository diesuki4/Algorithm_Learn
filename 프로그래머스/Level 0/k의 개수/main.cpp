#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(int i, int j, int k);

int main(int argc, char* argv[])
{
    cout << solution(1, 13, 1) << endl;
    cout << solution(10, 50, 5) << endl;
    cout << solution(3, 10, 2) << endl;
}

int solution(int i, int j, int k)
{
    int answer = 0;

    for (int t = i; t <= j; ++t)
    {
        string s = to_string(t);
        answer += count(s.begin(), s.end(), '0' + k);
    }

    return answer;
}
