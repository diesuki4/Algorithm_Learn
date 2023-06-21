#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included);

int main(int argc, char* argv[])
{
    cout << solution(3, 4, {true, false, false, true, true}) << endl;
    cout << solution(7, 1, {false, false, false, true, false, false, false}) << endl;

    return 0;
}

int solution(int a, int d, vector<bool> included)
{
    int answer = 0;

    for (bool b : included)
        answer += (b ? a : 0),
        a += d;

    return answer;
}
